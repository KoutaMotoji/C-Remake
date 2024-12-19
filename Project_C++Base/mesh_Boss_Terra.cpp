//===============================================================================
//
//  C++�g����2D(mesh_Boss_Terra.cpp)
//								����F���n�O��
// 
//===============================================================================
#include "mesh_Boss_Terra.h"
#include "eff_explosion.h"
#include "playerX.h"
#include "player_observer.h"
#include "boss_bullet.h"
#include "enemy_base.h"
#include "particle3D.h"

#include "mesh_ground.h"
#include "manager.h"
#include "game.h"

namespace BulletOption {
	//�e�e�̔��˒n�_�̈ʒu
	D3DXVECTOR3 setpos1 = { -500.0f,300.0f,-500.0f };
	D3DXVECTOR3	setpos2 = { -300.0f,300.0f,-500.0f };
	D3DXVECTOR3	setpos3 = { -70.0f,300.0f,0.0f };
	D3DXVECTOR3	setpos4 = { 70.0f,300.0f,0.0f };
	D3DXVECTOR3	setpos5 = { 300.0f,300.0f,-500.0f };
	D3DXVECTOR3	setpos6 = { 500.0f,300.0f,-500.0f };

	int Life = 60;
	float Radius = 150;
	float EffectSize = 100;
	D3DXCOLOR color1 = { 0.2f,0.2f,0.8f,1.0f };
	D3DXCOLOR color2 = { 0.8f,0.1f,0.1f,1.0f };
	D3DXCOLOR DamagingColor = { 1.0f,0.1f,0.2,0.8f };
}

//==========================================================================================
//�R���X�g���N�^
//==========================================================================================
CBossTerra::CBossTerra():m_bMove(false), m_nLife(400), m_bDead(false), m_bDamaging(false), m_nDamageFrame(0),m_nDeadFrame(0),m_nAttackFrame(0), m_move({0.0f,0.0f,0.0f})
{
	m_Reticle[0] = nullptr;
	m_Reticle[1] = nullptr;
}

//==========================================================================================
//�f�X�g���N�^
//==========================================================================================
CBossTerra::~CBossTerra()
{

}

//==========================================================================================
//����������
//==========================================================================================
void CBossTerra::Init()
{
	CObject::SetType(TYPE_3D_BOSSTERRA);
	m_Gauge = CGaugeBoss::Create(CObjectX::GetPos(), { 700,50 }, m_nLife);
	CObjectX::Init();
}

//==========================================================================================
//�I������
//==========================================================================================
void CBossTerra::Uninit()
{
	if (m_Reticle[0] != nullptr)
	{
		m_Reticle[0]->Release();
		m_Reticle[0] = nullptr;
	}
	if (m_Reticle[1] != nullptr)
	{
		m_Reticle[1]->Release();
		m_Reticle[1] = nullptr;
	}
	if (m_Gauge != nullptr)
	{
		m_Gauge->Uninit();
	}
	CObjectX::Uninit();
}

//==========================================================================================
//�X�V����
//==========================================================================================
void CBossTerra::Update()
{
	D3DXVECTOR3 pos = CObjectX::GetPos();
	D3DXVECTOR3 Playerpos = CPlayerObserver::GetInstance()->GetPlayerPos();
	if (CObjectX::GetPos().x > 500.0f ||
		CObjectX::GetPos().x < -500.0f)
	{
		m_bMove = !m_bMove;
	}
	if (!m_bDead)
	{
		if (m_bMove)
		{
			CObjectX::AddPos({ 5.0f,0.0f,0.0f });
		}
		else
		{
			CObjectX::AddPos({ -5.0f,0.0f,0.0f });
		}
		if (AttackRateCheck())
		{
			std::random_device rnd;				// �񌈒�I�ȗ���������ŃV�[�h�����@�𐶐�
			std::mt19937 mt(rnd());				//  �����Z���k�c�C�X�^�[��32�r�b�g�ŁA�����͏����V�[�h
			std::uniform_int_distribution<> rand_num(0, 2);     // [0, 1] �͈͂̈�l����
			switch (rand_num(mt))
			{
			case 0:
				CManager::GetInstance()->GetSound()->PlaySound(CSound::SOUND_LABEL_GAMESE_BOSSLOCKON);

				m_Reticle[0] = CBossReticle::Create(Playerpos, 150, 50, 0.08f);
				m_Reticle[1] = CBossReticle::Create(Playerpos, 100, 50, -0.06f);
				break;
			case 1:
				SetStatue();
				break;
			case 2:
				for (int i = 0; i < 5; ++i)
				{
					CBossEnemySpawner::Create(pos,i);
				}
				break;
			}
		}


		if (m_Reticle[0] != nullptr &&
			m_Reticle[1] != nullptr)
		{
			m_Reticle[0]->SetPos(Playerpos);
			m_Reticle[1]->SetPos(Playerpos);
			if (m_Reticle[0]->GetLifeState() ||
				m_Reticle[1]->GetLifeState())
			{
				CManager::GetInstance()->GetSound()->PlaySound(CSound::SOUND_LABEL_GAMESE_BOSSSHOT);
				SetBullet(pos, Playerpos);

				m_Reticle[0]->Release();
				m_Reticle[1]->Release();
				m_Reticle[0] = nullptr;
				m_Reticle[1] = nullptr;
			}
		}
	}
	
	if (m_bDamaging)
	{
		++m_nDamageFrame;
		if (m_nDamageFrame > 20)
		{
			m_bDamaging = false;
		}
	}

	m_Gauge->SetPos({ CObjectX::GetPos().x,CObjectX::GetPos().y + 400.0f ,CObjectX::GetPos().z });
	DeathCheck();
	if(m_bDead)
	{
		DeathAnim();
	}


	m_move.z = CPlayerObserver::GetInstance()->GetPlayerMove().z * 1.135f;
	float disPos = pos.z - Playerpos.z;
	if (disPos < 1500)
	{
		m_move.z += 2500;
	}
	CObjectX::AddPos(m_move);

	//�ړ��ʂ��X�V
	m_move.x += (0.0f - m_move.x) * 0.17f;
	m_move.y += (0.0f - m_move.y) * 0.17f;
	m_move.z += (0.0f - m_move.z) * 0.17f;

	CObjectX::Update();
}


//==========================================================================================
//�`�揈��
//==========================================================================================
void CBossTerra::Draw()
{
	if (m_bDamaging||m_bDead)
	{
		CObjectX::Draw(BulletOption::DamagingColor);
	}
	else
	{
		CObjectX::Draw();
	}
}

//==========================================================================================
//��������
//==========================================================================================
CBossTerra* CBossTerra::Create(D3DXVECTOR3 pos)
{
	CBossTerra* enemy = new CBossTerra;

	enemy->BindModel("data\\MODEL\\Boss_Terra.x");
	enemy->SetModelParam(pos);
	enemy->Init();

	return enemy;
}

//==========================================================================================
//���S���o����
//==========================================================================================
void CBossTerra::DeathAnim() {
	if (m_nDeadFrame % 15 == 0)
	{
		if (m_nDeadFrame == 180)
		{
			m_Gauge->Release();
			m_Gauge = nullptr;
			CObject::Release();
			CManager::GetInstance()->GetFade()->SetFade(CFade::FADE_IN, CScene::MODE_RESULT);
			return;
		}
		else
		{
			//��������
			std::random_device rnd;				// �񌈒�I�ȗ���������ŃV�[�h�����@�𐶐�
			std::mt19937 mt(rnd());				//  �����Z���k�c�C�X�^�[��32�r�b�g�ŁA�����͏����V�[�h
			std::uniform_int_distribution<> rand_x(-1200, 1200);    // [-1200, 1200] �͈͂̈�l����
			std::uniform_int_distribution<> rand_z(-700, 700);		// [-700, 700] �͈͂̈�l����
			std::uniform_int_distribution<> rand_y(-400, 700);		// [-400, 700] �͈͂̈�l����
			std::uniform_int_distribution<> rand_Radius(100, 250);	// [100, 250] �͈͂̈�l����
			D3DXVECTOR3 pos = {
							CObjectX::GetMatrix()._41 + (float)(rand_x(mt)),
							CObjectX::GetMatrix()._42 + (float)(rand_y(mt)),
							CObjectX::GetMatrix()._43 + (float)(rand_z(mt))
			};
			CEffExplosion::Create(pos, rand_Radius(mt));
		}
	}
	
	++m_nDeadFrame;
	CObjectX::AddPos({0.0f, -2.0f, 0.0f});
	
};

//==========================================================================================
//�U���̃��[�g�Ǘ�����
//==========================================================================================
bool CBossTerra::AttackRateCheck()
{
	if (m_nAttackFrame >= 180) {
		m_nAttackFrame = 0;
		return true;
	}
	++m_nAttackFrame;
	return false;
}

void CBossTerra::DeathCheck() 
{
	if (m_nLife <= 0 && !m_bDead)
	{
		CObjectX::AddRot({ 0.4f,0.0f,0.6f });
		m_bDead = true;
		CScene* pScene = CManager::GetInstance()->GetScene();
		if (pScene->GetSceneMode() == CScene::MODE_GAME)
		{
			CGame* pGame = dynamic_cast<CGame*>(pScene);
			pGame->GetScore()->AddScore(5000);
		}
	}
};

//==========================================================================================
//�e�̔��˂�ݒ�
//==========================================================================================
void CBossTerra::SetBullet(D3DXVECTOR3& pos, D3DXVECTOR3& Playerpos)
{
	using namespace BulletOption;

	D3DXVECTOR3 pos1 = setpos1 + pos;
	D3DXVECTOR3 pos2 = setpos2 + pos;
	D3DXVECTOR3 pos3 = setpos3 + pos;
	D3DXVECTOR3 pos4 = setpos4 + pos;
	D3DXVECTOR3 pos5 = setpos5 + pos;
	D3DXVECTOR3 pos6 = setpos6 + pos;

	D3DXVECTOR3 value1 = Playerpos - pos1;
	D3DXVECTOR3 value2 = Playerpos - pos2;
	D3DXVECTOR3 value3 = Playerpos - pos3;
	D3DXVECTOR3 value4 = Playerpos - pos4;
	D3DXVECTOR3 value5 = Playerpos - pos5;
	D3DXVECTOR3 value6 = Playerpos - pos6;

	D3DXVec3Normalize(&value1, &value1);
	D3DXVec3Normalize(&value2, &value2);
	D3DXVec3Normalize(&value3, &value3);
	D3DXVec3Normalize(&value4, &value4);
	D3DXVec3Normalize(&value5, &value5);
	D3DXVec3Normalize(&value6, &value6);

	CBossBullet::Create(pos1, value1, color1, Life, Radius, EffectSize);
	CBossBullet::Create(pos2, value2, color2, Life, Radius, EffectSize);
	CBossBullet::Create(pos3, value3, color1, Life, Radius, EffectSize);
	CBossBullet::Create(pos4, value4, color2, Life, Radius, EffectSize);
	CBossBullet::Create(pos5, value5, color1, Life, Radius, EffectSize);
	CBossBullet::Create(pos6, value6, color2, Life, Radius, EffectSize);
}

//==========================================================================================
//�{�X���o���Β��̏o��
//==========================================================================================
void CBossTerra::SetStatue()
{
	CManager::GetInstance()->GetSound()->PlaySound(CSound::SOUND_LABEL_GAMESE_SPAWN);

	std::random_device rnd;				// �񌈒�I�ȗ���������ŃV�[�h�����@�𐶐�
	std::mt19937 mt(rnd());				//  �����Z���k�c�C�X�^�[��32�r�b�g�ŁA�����͏����V�[�h
	std::uniform_int_distribution<> rand_x(-2500, 2500);	 // [-3000, 3000] �͈͂̈�l����
	std::uniform_int_distribution<> rand_y(2000, 5000);		 // [2000, 5000] �͈͂̈�l����

	for (int i = 0; i < 4; ++i)
	{
		CBossStatue::Create(
			{ (float)(rand_x(mt)),
			(float)(rand_y(mt)),
			CObjectX::GetPos().z + (i + 1) * 2500 }
		);
	}
}

//==========================================================================================
//�{�X���o���Β��̐�������
//==========================================================================================
CBossStatue* CBossStatue::Create(D3DXVECTOR3 pos)
{
	CBossStatue* statue = new CBossStatue;

	statue->BindModel("data\\MODEL\\boss_statue.x");
	statue->SetModelParam(pos);
	statue->Init();
	statue->AddPos({ 0.0f,3000.0f,0.0f });
	return statue;
}

//==========================================================================================
//�󒆂ɏo�����Β���n�ʂɓ˂��h��
//==========================================================================================
void CBossStatue::SetYPos()
{
	CBossStatue::AddPos({ 0.0f,-250.0f,0.0f });
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
							D3DXVECTOR3 objpos = CBossStatue::GetPos() - pTest->GetPos();
							D3DXIntersect(pMesh, &objpos, &dir, &bIsHit, &dwHitIndex, &fHitU, &fHitV, &fLandDistance, nullptr, nullptr);

							// ----- �ڒn������ -----
							if (bIsHit)
							{
								if (fLandDistance > 100)
								{
									m_bSeted = true;
									CManager::GetInstance()->GetSound()->PlaySound(CSound::SOUND_LABEL_GAMESE_FALL);
								}
							}
						}
					}
				}
			}
		}
	}
}

//==========================================================================================================================
//�G����o����N���X�̏����Q

//==========================================================================================
//�{�X���o���G�̐�������
//==========================================================================================
CBossEnemySpawner* CBossEnemySpawner::Create(D3DXVECTOR3 pos,int num)
{
	CBossEnemySpawner* statue = new CBossEnemySpawner;

	statue->BindModel("data\\MODEL\\enemy_base.x");
	statue->SetModelParam(pos);
	statue->Init(num);
	return statue;
}

//==========================================================================================
//����������
//==========================================================================================
void CBossEnemySpawner::Init(int num)
{
	//��������
	std::random_device rnd;			// �񌈒�I�ȗ���������ŃV�[�h�����@�𐶐�
	std::mt19937 mt(rnd());			//  �����Z���k�c�C�X�^�[��32�r�b�g�ŁA�����͏����V�[�h
	std::uniform_int_distribution<> rand_x(-1200, 1200);	// [-1200, 1200] �͈͂̈�l����
	std::uniform_int_distribution<> rand_y(-1000, 1000);	// [-1000, 1000] �͈͂̈�l����
	std::uniform_int_distribution<> rand_z(1500, 2500);		// [1000, 2000] �͈͂̈�l����
	std::uniform_int_distribution<> rand_time(30, 60);		// [30, 60] �͈͂̈�l����

	m_Lifetime = rand_time(mt);

	m_moveVec = {
		(float)(rand_x(mt) / m_Lifetime),
		(float)(rand_y(mt) / m_Lifetime),
		(float)((rand_z(mt) * (num + 1)) / m_Lifetime)
	};

	CObjectX::Init();
}

//==========================================================================================
//�X�V����
//==========================================================================================
void CBossEnemySpawner::Update()
{
	if (m_CntTime >= m_Lifetime)
	{
		SetEnemy();
	}
	else
	{
		++m_CntTime;
		Move();
	}
	CObjectX::Update();
}

//==========================================================================================
//����������
//==========================================================================================
void CBossEnemySpawner::Move()
{
	D3DXVECTOR3 pos = CObjectX::GetPos();

	pos += m_moveVec;

	if (pos.x >= WORLD_WALL_X)
	{
		pos.x = WORLD_WALL_X;
	}
	else if (pos.x <= -WORLD_WALL_X)
	{
		pos.x = -WORLD_WALL_X;
	}

	if (pos.y >= WORLD_WALL_Y)
	{
		pos.y = WORLD_WALL_Y;
	}
	else if (pos.y <= -WORLD_WALL_Y)
	{
		pos.y = -WORLD_WALL_Y;
	}
	CParticle3D::Create(pos, {0.2f,0.0f,1.0f,0.7f}, 90, 120, true);

	CObjectX::SetPos(pos);
}

//==========================================================================================
//�{���̓G�ɒu�������鏈��
//==========================================================================================
void CBossEnemySpawner::SetEnemy()
{
	CObjectX::SetSize({ 0.8f,0.8f ,0.8f });

	CEnemyBase::Create(CObjectX::GetPos());
	CObject::Release();
	return;
}
