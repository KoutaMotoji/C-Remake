//===============================================================================
//
//  C++�g����2D(playerX.cpp)
//								����F���n�O��
// 
//===============================================================================
#include "t_player.h"

const float CTitlePlayer::MOVE_SPEED = 0.55f;


//==========================================================================================
//�R���X�g���N�^
//==========================================================================================
CTitlePlayer::CTitlePlayer()
{
	for (int i = 0; i < MAX_MODELPARTS; ++i)
	{
		m_apModelParts[i] = nullptr;
	}
}

//==========================================================================================
//�f�X�g���N�^
//==========================================================================================
CTitlePlayer::~CTitlePlayer()
{

}

//==========================================================================================
//����������
//==========================================================================================
void CTitlePlayer::Init()
{
	ModelDataLoad();
	CObject::SetType(TYPE_3D_PLAYER);

	CManager::GetInstance()->GetCamera()->SetCameraDistance(800.0f);
	CManager::GetInstance()->GetCamera()->SetRotz(D3DX_PI);
}

//==========================================================================================
//�I������
//==========================================================================================
void CTitlePlayer::Uninit()
{
	for (int i = 0; i < MAX_MODELPARTS; ++i)
	{
		m_apModelParts[i]->Uninit();
	}
}

//==========================================================================================
//�X�V����
//==========================================================================================
void CTitlePlayer::Update()
{
	FloorCollision();
	
	//CManager::GetInstance()->GetCamera()->AddCameraDistance(-10.0f);

	m_pos += m_move;
	//�ړ��ʂ��X�V
	m_move.x += (0.0f - m_move.x) * 0.15f;
	m_move.y += (0.0f - m_move.y) * 0.15f;
	m_move.z += (0.0f - m_move.z) * 0.15f;

	CManager::GetInstance()->GetCamera()->SetPlayerPos(m_pos);
}

//==========================================================================================
//�`�揈��
//==========================================================================================
void CTitlePlayer::Draw()
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
	for (int i = 0; i < MAX_MODELPARTS; i++)
	{
		m_apModelParts[i]->Draw();	
	}
}

//==========================================================================================
//��������
//==========================================================================================
CTitlePlayer* CTitlePlayer::Create(D3DXVECTOR3 pos)
{
	CTitlePlayer* player = new CTitlePlayer;
	player->Init();

	player->m_pos = pos;
	player->m_move = { 0.0f,0.0f,0.0f };
	player->m_rot = { 0.0f,D3DX_PI,0.0f };
	player->m_size = { 1.0f,1.0f,1.0f };
	player->m_OldPos = pos;
	return player;
}

//==========================================================================================
//�ړ�����
//==========================================================================================
bool CTitlePlayer::PMove(float fCamRotZ)
{
	m_move += {CManager::GetInstance()->GetJoypad()->GetJoyStickVecL().x * 2, CManager::GetInstance()->GetJoypad()->GetJoyStickVecL().y * 2, 0.0f};

	if (CManager::GetInstance()->GetJoypad()->GetJoyStickTrigger(CJoypad::JOYPAD_LEFT_THUMB, CJoypad::JOYSTICK_DLEFT) == true ||
		CManager::GetInstance()->GetJoypad()->GetJoyStickTrigger(CJoypad::JOYPAD_LEFT_THUMB, CJoypad::JOYSTICK_DRIGHT) == true)
	{

	}
	if (CManager::GetInstance()->GetJoypad()->GetJoyStickRelease(CJoypad::JOYPAD_LEFT_THUMB, CJoypad::JOYSTICK_DLEFT) == true ||
		CManager::GetInstance()->GetJoypad()->GetJoyStickRelease(CJoypad::JOYPAD_LEFT_THUMB, CJoypad::JOYSTICK_DRIGHT) == true)
	{

	}
	if (CManager::GetInstance()->GetKeyboard()->GetPress(DIK_A) == true || CManager::GetInstance()->GetJoypad()->GetJoyStickL(CJoypad::JOYSTICK_DLEFT) == true)
	{//A�L�[�������ꂽ

	}
	else if (CManager::GetInstance()->GetKeyboard()->GetPress(DIK_D) == true || CManager::GetInstance()->GetJoypad()->GetJoyStickL(CJoypad::JOYSTICK_DRIGHT) == true)
	{//D�L�[�������ꂽ

	}
	if (CManager::GetInstance()->GetJoypad()->GetJoyStickVecL() > 0)
	{
		m_vecAxis = { abs(m_move.y),abs(m_move.x),0.0f };
		D3DXVec3Normalize(&m_vecAxis, &m_vecAxis);

	}

	return true;
}

//==========================================================================================
//�������蔻��
//==========================================================================================
void CTitlePlayer::FloorCollision()
{

}


//==========================================================================================
//���[�V�������t�@�C������ǂݍ���
//==========================================================================================
void CTitlePlayer::ModelDataLoad()
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

	pFile = fopen("data\\TEXT\\motion_title_player.txt", "r");

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
		}
	}
	else
	{
		assert(pFile == nullptr);
	}
}