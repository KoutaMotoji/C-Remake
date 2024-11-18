//===============================================================================
//
//  C++�g����2D(enemy_basic.cpp)
//								����F���n�O��
// 
//===============================================================================
#include "mesh_Boss_Terra.h"
#include "eff_explosion.h"
#include "playerX.h"
#include "player_observer.h"

#include "manager.h"
#include "game.h"
#include <random>

//==========================================================================================
//�R���X�g���N�^
//==========================================================================================
CBossTerra::CBossTerra():m_bMove(false), m_nLife(400), m_bDead(false), m_bDamaging(false), m_nDamageFrame(0),m_nDeadFrame(0),m_nAttackFrame(0)
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
	D3DXVECTOR3 Playerpos = CPlayerObserver::GetPlayerPos();
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
			m_Reticle[0] = CBossReticle::Create(Playerpos, 150, 50, 0.08f);
			m_Reticle[1] = CBossReticle::Create(Playerpos, 100, 50, -0.06f);
		}
		if (m_Reticle[0] != nullptr &&
			m_Reticle[1] != nullptr)
		{
			m_Reticle[0]->SetPos(Playerpos);
			m_Reticle[1]->SetPos(Playerpos);
			if (m_Reticle[0]->GetLifeState() ||
				m_Reticle[1]->GetLifeState())
			{
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
	m_Gauge->SetPos({ CObjectX::GetPos().x,CObjectX::GetPos().y + 300.0f ,CObjectX::GetPos().z });
	DeathCheck();
	if(m_bDead)
	{
		DeathAnim();
	}
	CObjectX::Update();
}

//==========================================================================================
//�`�揈��
//==========================================================================================
void CBossTerra::Draw()
{
	if (m_bDamaging||m_bDead)
	{
		CObjectX::Draw({1.0f,0.1f,0.2,0.8f});
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
	if (m_nDeadFrame % 5 == 0)
	{
		if (m_nDeadFrame == 180)
		{
			m_Gauge->Release();
			m_Gauge = nullptr;
			CObject::Release();
			return;
		}
		else
		{
			//��������
			std::random_device rnd;				// �񌈒�I�ȗ���������ŃV�[�h�����@�𐶐�
			std::mt19937 mt(rnd());				//  �����Z���k�c�C�X�^�[��32�r�b�g�ŁA�����͏����V�[�h
			std::uniform_int_distribution<> rand_x(-1200, 1200);     // [-1200, 1200] �͈͂̈�l����
			std::uniform_int_distribution<> rand_z(-700, 700);     // [-1200, 1200] �͈͂̈�l����
			std::uniform_int_distribution<> rand_y(-400, 700);     // [-400, 700] �͈͂̈�l����
			std::uniform_int_distribution<> rand_Radius(100, 250);		 // [400, 1200] �͈͂̈�l����
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
