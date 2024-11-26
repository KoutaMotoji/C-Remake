//===============================================================================
//
//  C++�g����2D(playerX.cpp)
//								����F���n�O��
// 
//===============================================================================
#include "playerX.h"

#include "particle3D.h"
#include "bullet3D.h"
#include "mesh_ground.h" 
#include "mesh_obstacle.h"
#include "mesh_cylinder.h"
#include "game.h"
#include "collision.h"


const float CPlayerX::MOVE_SPEED = 0.35f;
const int CPlayerX::MAX_LIFE = 1000;
const int CPlayerX::MAX_STAMINA = 500;




//==========================================================================================
//�R���X�g���N�^
//==========================================================================================
CPlayerX::CPlayerX():fGravity(0.55f),m_nLife(1000),m_nStamina(500),m_fWeaponRadius(25), bStop(false), m_bMotion(false), m_SecZrot(0.8f), m_bTransformed(false), m_bDamaged(false), m_DamageTime(0), m_bBlend(false)
{
	for (int i = 0; i < MAX_MODELPARTS; ++i)
	{
		m_apModelParts[i] = nullptr;
	}
}

//==========================================================================================
//�f�X�g���N�^
//==========================================================================================
CPlayerX::~CPlayerX()
{
	
}

//==========================================================================================
//����������
//==========================================================================================
void CPlayerX::Init()
{

	MotionInit();
	m_pReticle = CReticle::Create({ 0.0f,0.0f,500.0f });
	CObject::SetType(TYPE_3D_PLAYER);
}

//==========================================================================================
//�I������
//==========================================================================================
void CPlayerX::Uninit()
{
	for (int i = 0; i < MAX_MODELPARTS; ++i)
	{
		m_apModelParts[i]->Uninit();
	}
}

//==========================================================================================
//�X�V����
//==========================================================================================
void CPlayerX::Update()
{
	D3DXVECTOR3 CameraPos;

	ReticleController();
	if (!MotionBlending())
	{
		SetNextKey();
	}

	FloorCollision();
	PMove(CameraPos.z);
	if (!m_bMotion)
	{
		if (CManager::GetInstance()->GetJoypad()->GetTrigger(CJoypad::JOYPAD_X) == true||
			CManager::GetInstance()->GetKeyboard()->GetTrigger(DIK_R) == true)
		{
			if (!m_bTransformed)
			{
				SetNextMotion(MOTION_TRANS_JET_TO_ROBO);
			}
			else
			{
				SetNextMotion(MOTION_TRANS_ROBO_TO_JET);
			}
			m_bTransformed = !m_bTransformed;
			m_bMotion = true;
		}
	}
	
	if (MeshObstacle() &&
		!m_bDamaged)
	{
		m_bDamaged = true;
		CManager::GetInstance()->GetCamera()->SetShake(20, 40);
		m_DamageTime = 0;
	}
	if (!TestUseMeshCollision())
	{
		m_pReticle->AddPos({m_move.x,m_move.y,0.0f});
	}
	if (m_bDamaged)
	{
		++m_DamageTime;
		m_rot.x += 0.2f;
		m_rot.y += 0.3f;
		if (m_DamageTime > 100)
		{
			m_rot = {0.0f,D3DX_PI,0.0f};
			m_bDamaged = false;
		}
	}
	if (CManager::GetInstance()->GetJoypad()->GetTrigger(CJoypad::JOYPAD_RIGHT_TRIGGER) == true && !m_bMotion && !m_bDamaged)
	{
		SetNextMotion(MOTION_ROBO_SLASH);
	}
	if (CManager::GetInstance()->GetJoypad()->GetTrigger(CJoypad::JOYPAD_LEFT_TRIGGER) == true && !m_bMotion && !m_bDamaged)
	{
	
		D3DXVECTOR3 digitRot = {0.0f,0.0f,0.0f};
		D3DXVECTOR3 posMtx = { m_apModelParts[19]->GetWorldMatrix()._41, m_apModelParts[19]->GetWorldMatrix()._42 ,m_apModelParts[19]->GetWorldMatrix()._43 };

		digitRot.x = (m_pReticle->GetPos().x - posMtx.x) * 0.2f;
		digitRot.y = (m_pReticle->GetPos().y - posMtx.y) * 0.2f;
		digitRot.z = (m_pReticle->GetPos().z - posMtx.z) * 0.2f;
		D3DXVECTOR3 SetdigitedRot = { 0.0f,0.0f,0.0f };
		D3DXVECTOR3 addZpos = { 0.0f,0.0f,40.0f };
		D3DXVec3Normalize(&SetdigitedRot, &digitRot);
		SetdigitedRot.z;
		if (m_bTransformed)
		{
			SetNextMotion(MOTION_ROBO_SHOT);
			m_bMotion = true;
			CBullet3D::Create(RifleMtxSet() + m_move + addZpos, SetdigitedRot , { 1.0f,0.0f,0.2f,1.0f }, 150,25,35);
		}
		else
		{
			CBullet3D::Create(RifleMtxSet() + m_move + addZpos, SetdigitedRot, { 1.0f,0.0f,0.0f,1.0f }, 120,18,22);
		}
	}
	if (CManager::GetInstance()->GetJoypad()->GetPress(CJoypad::JOYPAD_RIGHT_SHOULDER) == true)
	{
		m_move.z -= 5.0f;
	}
	else if (CManager::GetInstance()->GetJoypad()->GetPress(CJoypad::JOYPAD_RIGHT_TRIGGER) == true)
	{
		m_move.z += 5.0f;
	}
	m_move.z += 3.0f;

	m_pReticle->SetPos({ m_pReticle->GetPos().x,m_pReticle->GetPos().y,m_pos.z + 500 });

	m_pos += m_move;
	//�ړ��ʂ��X�V
	m_move.x += (0.0f - m_move.x) * 0.17f;
	m_move.y += (0.0f - m_move.y) * 0.17f;
	m_move.z += (0.0f - m_move.z) * 0.17f;

	CameraPos = CameraPosDigit();

	CManager::GetInstance()->GetCamera()->SetPlayerPos(CameraPos);

	//GoalCheck();
}

//==========================================================================================
//�`�揈��
//==========================================================================================
void CPlayerX::Draw()
{
	LPDIRECT3DDEVICE9 pDevice;
	//�f�o�C�X�̎擾
	pDevice = CManager::GetInstance()->GetRenderer()->GetDevice();
	//�v�Z�p�}�g���b�N�X
	D3DXMATRIX mtxRot, mtxTrans, mtxSize;

	//�N�I�[�^�j�I�����쐬
	D3DXQuaternionRotationAxis(
		&m_quat,
		&m_vecAxis,
		m_fValueRot);

	//�N�I�[�^�j�I�������]�}�g���b�N�X���쐬
	D3DXMatrixRotationQuaternion(
		&mtxRot,
		&m_quat);
	m_mtxRot = mtxRot;		//��]�}�g���b�N�X��ۑ�


	//���[���h�}�g���b�N�X�̏�����
	D3DXMatrixIdentity(&m_mtxWorld);

	//�傫���𔽉f
	D3DXMatrixScaling(&mtxSize,
		m_size.y,
		m_size.x,
		m_size.z);
	D3DXMatrixMultiply(&m_mtxWorld,
		&m_mtxWorld,
		&mtxSize);
	//�����𔽉f
	D3DXMatrixRotationYawPitchRoll(&mtxRot,
		m_rot.y,
		m_rot.x,
		m_rot.z);
	D3DXMatrixMultiply(&m_mtxWorld,
		&m_mtxWorld,
		&m_mtxRot);
	D3DXMatrixMultiply(&m_mtxWorld,
		&m_mtxWorld,
		&mtxRot);
	//�ʒu�𔽉f
	D3DXMatrixTranslation(&mtxTrans,
		m_pos.x,
		m_pos.y,
		m_pos.z);
	D3DXMatrixMultiply(&m_mtxWorld,
		&m_mtxWorld,
		&mtxTrans);
	//���[���h�}�g���b�N�X�̐ݒ�
	pDevice->SetTransform(D3DTS_WORLD,
		&m_mtxWorld);
	for (int i = 0; i < MAX_MODELPARTS; ++i)
	{
		if (m_bDamaged)
		{
			m_apModelParts[i]->Draw(0.3f);
		}
		else
		{
			m_apModelParts[i]->Draw();
		}
	}
	m_pReticle->Draw();
}

//==========================================================================================
//��������
//==========================================================================================
CPlayerX* CPlayerX::Create(D3DXVECTOR3 pos)
{
	CPlayerX* player = new CPlayerX;
	player->Init();


	player->m_pos = pos;
	player->m_move = { 0.0f,0.0f,0.0f };
	player->m_rot = { 0.0f,D3DX_PI,0.0f };
	player->m_size = {1.0f,1.0f,1.0f};
	player->m_OldPos = pos;
	return player;
}

//==========================================================================================
//�ړ�����
//==========================================================================================
bool CPlayerX::PMove(float fCamRotZ)
{
	m_move += {CManager::GetInstance()->GetJoypad()->GetJoyStickVecL().x * 2, CManager::GetInstance()->GetJoypad()->GetJoyStickVecL().y * 2, 0.0f};

	if (CManager::GetInstance()->GetJoypad()->GetJoyStickTrigger(CJoypad::JOYPAD_LEFT_THUMB, CJoypad::JOYSTICK_DLEFT) == true||
		CManager::GetInstance()->GetJoypad()->GetJoyStickTrigger(CJoypad::JOYPAD_LEFT_THUMB, CJoypad::JOYSTICK_DRIGHT) == true)
	{

	}
	if (CManager::GetInstance()->GetJoypad()->GetJoyStickRelease(CJoypad::JOYPAD_LEFT_THUMB, CJoypad::JOYSTICK_DLEFT) == true ||
		CManager::GetInstance()->GetJoypad()->GetJoyStickRelease(CJoypad::JOYPAD_LEFT_THUMB, CJoypad::JOYSTICK_DRIGHT) == true)
	{

	}
	if (CManager::GetInstance()->GetKeyboard()->GetPress(DIK_A) == true||CManager::GetInstance()->GetJoypad()->GetJoyStickL(CJoypad::JOYSTICK_DLEFT) == true)
	{//A�L�[�������ꂽ

	}
	else if (CManager::GetInstance()->GetKeyboard()->GetPress(DIK_D) == true || CManager::GetInstance()->GetJoypad()->GetJoyStickL(CJoypad::JOYSTICK_DRIGHT) == true)
	{//D�L�[�������ꂽ

	}
	if (CManager::GetInstance()->GetJoypad()->GetJoyStickVecL() > 0)
	{
		m_vecAxis = { m_move.y,m_move.x,0.0f };
		D3DXVec3Normalize(&m_vecAxis, &m_vecAxis);

		m_fValueRot = (2 * sqrtf((m_move.x * m_move.x) + (m_move.y* m_move.y)) * 10) / (120 * D3DX_PI);

		m_pReticle->SetPos({ m_pos.x + m_move.x * 10,m_pos.y + m_move.y * 10, m_pos.z + 500 });
	}

	return true;
}


//==========================================================================================
//�������蔻��
//==========================================================================================
void CPlayerX::FloorCollision()
{
	if (m_pos.y < -1000)
	{
		m_pos.y = -1000;
	}
	else if (m_pos.y > 1000)
	{
		m_pos.y = 1000;
	}
	if (m_pos.x < -1200)
	{
		m_pos.x = -1200;
	}
	else if (m_pos.x > 1200)
	{
		m_pos.x = 1200;
	}

	if (m_pReticle->GetPos().y < m_pos.y -300)
	{
		m_pReticle->SetPos({ m_pReticle->GetPos().x, m_pos.y - 300 ,m_pReticle->GetPos().z });
	}
	else if (m_pReticle->GetPos().y > m_pos.y + 300)
	{
		m_pReticle->SetPos({ m_pReticle->GetPos().x, m_pos.y + 300 ,m_pReticle->GetPos().z });
	}
	if (m_pReticle->GetPos().x < m_pos.x - 500)
	{
		m_pReticle->SetPos({ m_pos.x - 500, m_pReticle->GetPos().y ,m_pReticle->GetPos().z });
	}
	else if (m_pReticle->GetPos().x > m_pos.x + 500)
	{
		m_pReticle->SetPos({ m_pos.x + 500, m_pReticle->GetPos().y ,m_pReticle->GetPos().z });
	}

}

//==========================================================================================
//�ːi�U���̎��ɕ���̕�����i�s�����ɕϊ�
//==========================================================================================
void CPlayerX::SetWeaponRot(D3DXVECTOR2 rot)
{
	m_rot = { -(abs(atan2f(rot.x ,rot.y))), m_rot.y,0.0f };
}

//==========================================================================================
//�X�^�~�i�̑����֐�
//==========================================================================================
void CPlayerX::StaminaAdd(int value)
{
	if (m_nStamina + value <= MAX_STAMINA)
	{
		m_nStamina += value;
	}
}

//==========================================================================================
//�S�[������`�F�b�N
//==========================================================================================
/*
void CPlayerX::GoalCheck()
{
	for (int j = 0; j < SET_PRIORITY; j++)
	{
		for (int i = 0; i < MAX_OBJECT; i++)
		{
			CObject* pObj = CObject::GetObjects(j, i);
			if (pObj != nullptr)
			{
				CObject::TYPE type = pObj->GetType();

				if (type == CObject::TYPE::TYPE_3D_G_MARKER)
				{
					CGoal* pGoal = dynamic_cast<CGoal*>(pObj);
					if (pGoal != nullptr)
					{
						D3DXVECTOR3 PlayerMin = { -15.0f,10.0f,0.0f };
						D3DXVECTOR3 PlayerMax = { 15.0f,35.0f,0.0f };
						D3DXVECTOR3 GoalMin = pGoal->GetModelMin();
						D3DXVECTOR3 GoalMax = pGoal->GetModelMax();
						if (m_pos.x + PlayerMax.x > (pGoal->CObjectX::GetPos().x + GoalMin.x * 2.0f) &&
							m_pos.x + PlayerMin.x < (pGoal->CObjectX::GetPos().x + GoalMax.x * 2.0f) &&
							m_pos.y + PlayerMax.y > (pGoal->CObjectX::GetPos().y + GoalMin.y * 2.0f) &&
							m_pos.y + PlayerMin.y < (pGoal->CObjectX::GetPos().y + GoalMax.y * 2.0f))
						{
							m_move.x *= 0.001f;
							CManager::GetInstance()->GetFade()->SetFade(CFade::FADE_IN, CScene::MODE_RESULT);
						}
					}
				}
			}
		}
	}
}
*/

//==========================================================================================
//���S�`�F�b�N
//==========================================================================================
void CPlayerX::DeadCheck()
{
	if (m_nLife <= 0)
	{
		CManager::GetInstance()->GetFade()->SetFade(CFade::FADE_IN, CScene::MODE_RESULT);
	}
}

//==========================================================================================
//���[�V�����̏���������
//==========================================================================================
void CPlayerX::MotionInit()
{
	MotionDataLoad();

	m_CurMotion = 0;
	m_CurKey = 0;
	m_NowFrame = 0;

}

//==========================================================================================
//���̃��[�V�����Ɉڍs���鏈��
//==========================================================================================
void CPlayerX::SetNextMotion(int nNextMotionNum)
{
	m_NextMotion = nNextMotionNum;
	m_NowFrame = 0;
	m_bBlend = true;
	MotionBlending();
}

//==========================================================================================
//���̃L�[�̃��[�V��������
//==========================================================================================
void CPlayerX::SetNextKey()
{
	//���݂̈ʒu�E�p�x
	D3DXVECTOR3 NowPos = {};
	D3DXVECTOR3 NowRot = {};

	//���̈ʒu�E�p�x
	D3DXVECTOR3 NextPos = {};
	D3DXVECTOR3 NextRot = {};

	//�����̍��������߂�p
	D3DXVECTOR3 DifPos = {};
	D3DXVECTOR3 DifRot = {};

	//�v�Z�p
	D3DXVECTOR3 DigitPos = {};
	D3DXVECTOR3 DigitRot = {};

	int nNowKey = m_CurKey;
	int nNowMotion = m_CurMotion;
	int nNextKey = (m_CurKey + 1) % m_aMotion[nNowMotion].nKeyNum;
	float fRatioFrame = (float)m_NowFrame / (float)m_aMotion[nNowMotion].aKetSet[nNowKey].nFrame;

	for (int nCntParts = 0; nCntParts < MAX_PARTS; ++nCntParts)
	{
		//���݂̌����ƈʒu�̏��
		NowPos = m_aMotion[nNowMotion].aKetSet[nNowKey].aKey[nCntParts].pos;
		NowRot = m_aMotion[nNowMotion].aKetSet[nNowKey].aKey[nCntParts].rot;
		
		//���̃L�[�̏��
		NextPos = m_aMotion[nNowMotion].aKetSet[nNextKey].aKey[nCntParts].pos;
		NextRot = m_aMotion[nNowMotion].aKetSet[nNextKey].aKey[nCntParts].rot;

		//���������߂�
		DifPos = NextPos - NowPos;
		DifRot = NextRot - NowRot;

		//-3.14�`3.14�̊Ԃ𒴂���ꍇ�̏C��
		if (DifRot.x >= D3DX_PI)
		{
			DifRot.x -= D3DX_PI * 2;
		}
		if (DifRot.y >= D3DX_PI)
		{
			DifRot.y -= D3DX_PI * 2;
		}
		if (DifRot.z >= D3DX_PI)
		{
			DifRot.z -= D3DX_PI * 2;
		}
		if (DifRot.x <= -D3DX_PI)
		{
			DifRot.x += D3DX_PI * 2;
		}
		if (DifRot.y <= -D3DX_PI)
		{
			DifRot.y += D3DX_PI * 2;
		}
		if (DifRot.z <= -D3DX_PI)
		{
			DifRot.z += D3DX_PI * 2;
		}

		DigitPos = DifPos * fRatioFrame + m_apModelParts[nCntParts]->GetDefaultPos() + NowPos;
		DigitRot = DifRot * fRatioFrame + m_apModelParts[nCntParts]->GetDefaultRot() + NowRot;

		m_apModelParts[nCntParts]->SetPos(DigitPos);
		m_apModelParts[nCntParts]->SetRot(DigitRot);
	}

	++m_NowFrame;

	if (m_NowFrame >= m_aMotion[nNowMotion].aKetSet[nNowKey].nFrame)
	{
		++m_CurKey;
		m_NowFrame = 0;
		if (m_CurKey >= m_aMotion[nNowMotion].nKeyNum)
		{
			if (!m_aMotion[nNowMotion].bLoop)
			{	
				if (m_CurMotion == MOTION_TRANS_JET_TO_ROBO||
					m_CurMotion == MOTION_TRANS_ROBO_TO_JET||
					m_CurMotion == MOTION_ROBO_SHOT || 
					m_CurMotion == MOTION_ROBO_SLASH)
				{
					m_bMotion = false;
				}
				if (m_bTransformed)
				{
					SetNextMotion(MOTION_ROBO_NUTO);
				}
				else
				{
					SetNextMotion(MOTION_JET_NUTO);
				}			
			}
			else
			{
				m_CurKey = 0;
			}
		}
	}
}
//==========================================================================================
//���[�V�����؂�ւ����̃u�����h����
//==========================================================================================
bool CPlayerX::MotionBlending()
{
	if (!m_bBlend){
		return false;
	}

	//���݂̈ʒu�E�p�x
	D3DXVECTOR3 NowPos = {};
	D3DXVECTOR3 NowRot = {};

	//���̈ʒu�E�p�x
	D3DXVECTOR3 NextPos = {};
	D3DXVECTOR3 NextRot = {};

	//�����̍��������߂�p
	D3DXVECTOR3 DifPos = {};
	D3DXVECTOR3 DifRot = {};

	//�v�Z�p
	D3DXVECTOR3 DigitPos = {};
	D3DXVECTOR3 DigitRot = {};

	int nLastKey = m_CurKey;
	int nNowMotion = m_CurMotion;

	float fRatioFrame = ((float)m_NowFrame / (float)m_aMotion[m_NextMotion].aKetSet[0].nFrame);

	for (int nCntParts = 0; nCntParts < MAX_PARTS; ++nCntParts)
	{
		//���݂̌����ƈʒu�̏��
		NowPos = m_aMotion[nNowMotion].aKetSet[nLastKey].aKey[nCntParts].pos;
		NowRot = m_aMotion[nNowMotion].aKetSet[nLastKey].aKey[nCntParts].rot;

		//���̃L�[�̏��
		NextPos = m_aMotion[m_NextMotion].aKetSet[0].aKey[nCntParts].pos;
		NextRot = m_aMotion[m_NextMotion].aKetSet[0].aKey[nCntParts].rot;

		//���������߂�
		DifPos = NextPos - NowPos;
		DifRot = NextRot - NowRot;

		//-3.14�`3.14�̊Ԃ𒴂���ꍇ�̏C��
		if (DifRot.x >= D3DX_PI)
		{
			DifRot.x -= D3DX_PI * 2;
		}
		if (DifRot.y >= D3DX_PI)
		{
			DifRot.y -= D3DX_PI * 2;
		}
		if (DifRot.z >= D3DX_PI)
		{
			DifRot.z -= D3DX_PI * 2;
		}
		if (DifRot.x <= -D3DX_PI)
		{
			DifRot.x += D3DX_PI * 2;
		}
		if (DifRot.y <= -D3DX_PI)
		{
			DifRot.y += D3DX_PI * 2;
		}
		if (DifRot.z <= -D3DX_PI)
		{
			DifRot.z += D3DX_PI * 2;
		}

		DigitPos = DifPos * fRatioFrame + m_apModelParts[nCntParts]->GetDefaultPos() + NowPos;
		DigitRot = DifRot * fRatioFrame + m_apModelParts[nCntParts]->GetDefaultRot() + NowRot;

		m_apModelParts[nCntParts]->SetPos(DigitPos);
		m_apModelParts[nCntParts]->SetRot(DigitRot);
	}

	++m_NowFrame;

	if (m_NowFrame >= m_aMotion[m_NextMotion].aKetSet[0].nFrame)
	{
		m_CurKey = 0;
		m_NowFrame = 0;
		m_CurMotion = m_NextMotion;
		m_bBlend = false;
		SetNextKey();
	} 

	return m_bBlend;
}

//==========================================================================================
//���[�V�������t�@�C������ǂݍ���
//==========================================================================================
void CPlayerX::MotionDataLoad()
{
	char LoadData[128];
	char ModelPath[128];

	int nNumModel = 0;
	FILE* pFile;
	int nCnt = 0;

	int nMotionCnt = 0;
	int nKeySet = 0;
	int nKey = 0;
	D3DXVECTOR3 pos = { 0.0f,0.0f,0.0f };
	D3DXVECTOR3 rot = { 0.0f,0.0f,0.0f };
	int nFilenameCnt = 0;
	int nParent = 0;
	int nIndex = 0;
	int nModelCnt = 0;

	pFile = fopen("data\\TEXT\\motion_Player.txt","r");
	
	if (pFile != nullptr)
	{
		while (1)
		{
			fscanf(pFile, "%s", LoadData);

			if (!strcmp(LoadData, "END_SCRIPT"))	// �t�@�C���̍Ō�
			{
				fclose(pFile);
				break;
			}

			if (LoadData[0] == '#')		// ������΂�
			{
				continue;
			}

			//���f���̓ǂݍ���
			if (!strcmp(LoadData, "NUM_MODEL"))
			{
				fscanf(pFile, "%s", LoadData);
				fscanf(pFile, "%d", &m_ModelParts);
			}
			//���f���̃t�@�C�����ǂݍ���
			if (!strcmp(LoadData, "MODEL_FILENAME"))
			{
				fscanf(pFile, "%s", LoadData);

				fscanf(pFile, "%s", ModelPath);

				m_pModelFileName[nFilenameCnt] = ModelPath;

				m_apModelParts[nFilenameCnt] = CModelParts::Create(pos, m_pModelFileName[nFilenameCnt]);

				++nFilenameCnt;
			}
			//�L�����N�^�[�̐ݒ�̓ǂݍ��݊J�n
			if (!strcmp(LoadData, "CHARACTERSET"))
			{
				while (1)
				{
					fscanf(pFile, "%s", LoadData);

					if (!strcmp(LoadData, "END_CHARACTERSET"))//�ǂݍ��݂��I��
					{
						break;
					}
					else if (!strcmp(LoadData, "PARTSSET"))
					{
						while (1)
						{
							fscanf(pFile, "%s", LoadData);

							if (LoadData[0] == '#')
							{//������΂�
								fgets(LoadData, 100, pFile);
								continue;
							}

							if (!strcmp(LoadData, "END_PARTSSET"))
							{
								//�ǂݍ��݂��I��
								break;
							}
							//�e�p�[�c�̃��[�V����pos�l
							else if (!strcmp(LoadData, "INDEX"))
							{
								fscanf(pFile, "%s", LoadData);
								fscanf(pFile, "%d", &nIndex);
							}

							//�e�p�[�c�̃��[�V����rot�l
							else if (!strcmp(LoadData, "PARENT"))
							{
								fscanf(pFile, "%s", LoadData);
								fscanf(pFile, "%d", &nParent);
							}
							//�e�p�[�c�̃��[�V����pos�l
							else if (!strcmp(LoadData, "POS"))
							{
								fscanf(pFile, "%s", LoadData);
								fscanf(pFile, "%f", &pos.x);
								fscanf(pFile, "%f", &pos.y);
								fscanf(pFile, "%f", &pos.z);
							}

							//�e�p�[�c�̃��[�V����rot�l
							else if (!strcmp(LoadData, "ROT"))
							{
								fscanf(pFile, "%s", LoadData);
								fscanf(pFile, "%f", &rot.x);
								fscanf(pFile, "%f", &rot.y);
								fscanf(pFile, "%f", &rot.z);
							}
						}
						m_apModelParts[nModelCnt]->SetPos(pos);
						m_apModelParts[nModelCnt]->SetRot(rot);

						m_apModelParts[nModelCnt]->SetDefault();
						m_apModelParts[nModelCnt]->SetIndex(nIndex);
						if (nParent != -1)
						{
							m_apModelParts[nModelCnt]->SetParent(m_apModelParts[nParent]);
						}
						++nModelCnt;
					}
				}
			}
			
			//���[�V�����̓ǂݍ��݊J�n
			if (!strcmp(LoadData, "MOTIONSET"))
			{
				while (1)
				{
					fscanf(pFile, "%s", LoadData);

					if (!strcmp(LoadData, "END_MOTIONSET"))//�ǂݍ��݂��I��
					{
						break;
					}
					//���[�v�̔��f
					else if (!strcmp(LoadData, "LOOP"))
					{
						fscanf(pFile, "%s", LoadData);
						fscanf(pFile, "%d", &m_aMotion[nMotionCnt].bLoop);
					}

					//�S�̂̃L�[���̓ǂݍ���
					else  if (!strcmp(LoadData, "NUM_KEY"))
					{
						fscanf(pFile, "%s", LoadData);
						fscanf(pFile, "%d", &m_aMotion[nMotionCnt].nKeyNum);
					}

					//�e�L�[��ǂݍ���
					if (!strcmp(LoadData, "KEYSET"))
					{
						while (1)
						{
							fscanf(pFile, "%s", LoadData); 

							if (LoadData[0] == '#')
							{//������΂�
								fgets(LoadData, 100, pFile);
								continue;
							}

							if (!strcmp(LoadData, "END_KEYSET"))
							{
								//�ǂݍ��݂��I��
								break;
							}

							//���݂̃L�[�̃t���[������ǂݍ���
							else if (!strcmp(LoadData, "FRAME"))
							{
								fscanf(pFile, "%s", LoadData);
								fscanf(pFile, "%d", &m_aMotion[nMotionCnt].aKetSet[nKeySet].nFrame);
							}

							//���݂̃L�[�̓ǂݍ���
							if (!strcmp(LoadData, "KEY"))
							{
								while (1)
								{
									fscanf(pFile, "%s", LoadData);

									if (!strcmp(LoadData, "END_KEY"))
									{
										// �ǂݍ��݂��I��
										break;
									}

									//�e�p�[�c�̃��[�V����pos�l
									else if (!strcmp(LoadData, "POS"))
									{
										fscanf(pFile, "%s", LoadData);
										fscanf(pFile, "%f", &m_aMotion[nMotionCnt].aKetSet[nKeySet].aKey[nKey].pos.x);
										fscanf(pFile, "%f", &m_aMotion[nMotionCnt].aKetSet[nKeySet].aKey[nKey].pos.y);
										fscanf(pFile, "%f", &m_aMotion[nMotionCnt].aKetSet[nKeySet].aKey[nKey].pos.z);
									}

									//�e�p�[�c�̃��[�V����rot�l
									else if (!strcmp(LoadData, "ROT"))
									{
										fscanf(pFile, "%s", LoadData);
										fscanf(pFile, "%f", &m_aMotion[nMotionCnt].aKetSet[nKeySet].aKey[nKey].rot.x);
										fscanf(pFile, "%f", &m_aMotion[nMotionCnt].aKetSet[nKeySet].aKey[nKey].rot.y);
										fscanf(pFile, "%f", &m_aMotion[nMotionCnt].aKetSet[nKeySet].aKey[nKey].rot.z);
									}
								}
								//�L�[�ԍ���i�߂�
								++nKey;
							}
						}
						//�L�[�ԍ����������A�L�[�Z�b�g�ԍ���i�߂�
						nKey = 0;
						++nKeySet;
					}
				}
				//�L�[�Z�b�g�ԍ����������A���[�V�����ԍ���i�߂�
				nKeySet = 0;
				++nMotionCnt;
			}
		}
	}
	else
	{
		assert(pFile == nullptr);
	}
}

void CPlayerX::ReticleController()
{
	D3DXVECTOR2 ReticleMove = CManager::GetInstance()->GetJoypad()->GetJoyStickVecR();
	D3DXVec2Normalize(&ReticleMove, &ReticleMove);
	m_pReticle->AddPos({ ReticleMove.x * 5,ReticleMove.y * 5,0.0f });
}


D3DXVECTOR3 CPlayerX::CameraPosDigit()
{
	D3DXVECTOR3 CamPos = m_pos;

	CamPos.z = m_pos.z;
	return CamPos;
}


D3DXVECTOR3 CPlayerX::RifleMtxSet()
{
	D3DXMATRIX RifleMtx = m_apModelParts[19]->GetWorldMatrix();
	D3DXMATRIX UseMtx;

	D3DXVECTOR3 Addpos = { 40.0f,0.0f,-4.5f };
	D3DXVECTOR3 Addrot = { 0.0f,0.0f,0.0f };

	//�v�Z�p�}�g���b�N�X
	D3DXMATRIX mtxRot, mtxTrans;

	//���[���h�}�g���b�N�X�̏�����
	D3DXMatrixIdentity(&UseMtx);

	//�����𔽉f
	D3DXMatrixRotationYawPitchRoll(&mtxRot,
		Addrot.y,
		Addrot.x,
		Addrot.z);
	D3DXMatrixMultiply(&UseMtx,
		&UseMtx,
		&mtxRot);
	//�ʒu�𔽉f
	D3DXMatrixTranslation(&mtxTrans,
		Addpos.x,
		Addpos.y,
		Addpos.z);
	D3DXMatrixMultiply(&UseMtx,
		&UseMtx,
		&mtxTrans);

	//���[���h�s���e�̍s��Ɋ|����
	D3DXMatrixMultiply(&UseMtx,
		&UseMtx,
		&RifleMtx);

	D3DXVECTOR3 RiflePos = { UseMtx._41,UseMtx._42,UseMtx._43 };

	return RiflePos;
}

//==============================�@�@���C�ƃ��b�V���̏Փ˂������������蔻��p�@�@=============================================================================
//

bool CPlayerX::TestUseMeshCollision()
{	//=============================		�n�`���b�V������		==========================================================================
	// �n�`����
	BOOL  bIsHit = false;
	float fLandDistance;
	DWORD dwHitIndex = 0U;
	float fHitU;
	float fHitV;
	LPD3DXMESH pMesh = nullptr;
	for (int j = 0; j < SET_PRIORITY; ++j) {
		for (int i = 0; i < MAX_OBJECT; i++) {
			CObject* pObj = CObject::GetObjects(j, i);
			if (pObj != nullptr) {
				CObject::TYPE type = pObj->GetType();
				if (type == CObject::TYPE::TYPE_3D_MESHOBJECT) {
					CMeshGround* pTest = dynamic_cast<CMeshGround*>(pObj);
					if (pTest != nullptr) {
						pMesh = pTest->GetMesh();
						if (pTest != nullptr) {
							// �n�`����
		
							LPD3DXMESH pMesh = nullptr;

							pMesh = pTest->GetMesh();
							D3DXVECTOR3 dir = D3DXVECTOR3(0.0f, 1.0f, 0.0f);
							D3DXVECTOR3 objpos = m_pos - pTest->GetPos();
							D3DXIntersect(pMesh, &objpos, &dir, &bIsHit, &dwHitIndex, &fHitU, &fHitV, &fLandDistance, nullptr, nullptr);

							// ----- �ڒn������ -----
							if (bIsHit)
							{
								if (m_bTransformed)
								{
									m_pos.y += fLandDistance - m_move.y + 45.0f;
								}
								else
								{
									m_pos.y += fLandDistance - m_move.y;
								}
								return true;
							}
						}
					}
				}
			}
		}
	}
	return false;
	
}

bool CPlayerX::MeshObstacle()
{	//=============================		��Q�����b�V������		==========================================================================
	CCollision* pCollision = new CCollision();

	for (int j = 0; j < SET_PRIORITY; ++j) {
		for (int i = 0; i < MAX_OBJECT; ++i) {
			CObject* pObj = CObject::GetObjects(j, i);
			if (pObj != nullptr) {
				CObject::TYPE type = pObj->GetType();
				if (type == CObject::TYPE::TYPE_3D_OBSTACLE) {
					CMeshObstacle* pTest = dynamic_cast<CMeshObstacle*>(pObj);

					if (pTest != nullptr) {
	
						D3DXVECTOR3 dir = D3DXVECTOR3(0.0f, 0.0f, -1.0f);

						if (pCollision->MeshToIntersectCollision(pTest, m_pos, dir, 10 + m_move.z))
						{
							if (pCollision != nullptr)
							{
								delete pCollision;
								pCollision = nullptr;
							}
							return true;

						}
					}
				}
				
			}
		}
	}
	if (pCollision != nullptr)
	{
		delete pCollision;
		pCollision = nullptr;
	}
	return false;
}

//
//========================================================================================================================================