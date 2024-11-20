//===============================================================================
//
//  C++使った2D(enemy_basic.cpp)
//								制作：元地弘汰
// 
//===============================================================================
#include "mesh_Boss_Terra.h"
#include "eff_explosion.h"
#include "playerX.h"
#include "player_observer.h"
#include "boss_bullet.h"

#include "manager.h"
#include "game.h"
#include <random>

//==========================================================================================
//コンストラクタ
//==========================================================================================
CBossTerra::CBossTerra():m_bMove(false), m_nLife(400), m_bDead(false), m_bDamaging(false), m_nDamageFrame(0),m_nDeadFrame(0),m_nAttackFrame(0)
{
	m_Reticle[0] = nullptr;
	m_Reticle[1] = nullptr;
}

//==========================================================================================
//デストラクタ
//==========================================================================================
CBossTerra::~CBossTerra()
{

}

//==========================================================================================
//初期化処理
//==========================================================================================
void CBossTerra::Init()
{
	CObject::SetType(TYPE_3D_BOSSTERRA);
	m_Gauge = CGaugeBoss::Create(CObjectX::GetPos(), { 700,50 }, m_nLife);
	CObjectX::Init();
}

//==========================================================================================
//終了処理
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
//更新処理
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
				D3DXVECTOR3 setpos1 ={-500.0f,300.0f,-500.0f};
				D3DXVECTOR3	setpos2 ={-300.0f,300.0f,-500.0f};
				D3DXVECTOR3	setpos3 ={ -70.0f,300.0f,0.0f};
				D3DXVECTOR3	setpos4 ={  70.0f,300.0f,0.0f};
				D3DXVECTOR3	setpos5 ={ 300.0f,300.0f,-500.0f};
				D3DXVECTOR3	setpos6 ={ 500.0f,300.0f,-500.0f};

				setpos1	+= pos;
				setpos2	+= pos;
				setpos3	+= pos;
				setpos4	+= pos;
				setpos5	+= pos;
				setpos6	+= pos;

				D3DXVECTOR3 value1 = Playerpos - setpos1;
				D3DXVECTOR3 value2 = Playerpos - setpos2;
				D3DXVECTOR3 value3 = Playerpos - setpos3;
				D3DXVECTOR3 value4 = Playerpos - setpos4;
				D3DXVECTOR3 value5 = Playerpos - setpos5;
				D3DXVECTOR3 value6 = Playerpos - setpos6;

				D3DXVec3Normalize(&value1, &value1);
				D3DXVec3Normalize(&value2, &value2);
				D3DXVec3Normalize(&value3, &value3);
				D3DXVec3Normalize(&value4, &value4);
				D3DXVec3Normalize(&value5, &value5);
				D3DXVec3Normalize(&value6, &value6);

				CBossBullet::Create(setpos1, value1, { 0.2f,0.2f,0.8f,1.0f }, 70, 150, 100);
				CBossBullet::Create(setpos2, value2, { 0.8f,0.1f,0.1f,1.0f }, 70, 150, 100);
				CBossBullet::Create(setpos3, value3, { 0.2f,0.2f,0.8f,1.0f }, 70, 150, 100);
				CBossBullet::Create(setpos4, value4, { 0.8f,0.1f,0.1f,1.0f }, 70, 150, 100);
				CBossBullet::Create(setpos5, value5, { 0.2f,0.2f,0.8f,1.0f }, 70, 150, 100);
				CBossBullet::Create(setpos6, value6, { 0.8f,0.1f,0.1f,1.0f }, 70, 150, 100);



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
//描画処理
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
//生成処理
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
//死亡演出処理
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
			//乱数生成
			std::random_device rnd;				// 非決定的な乱数生成器でシード生成機を生成
			std::mt19937 mt(rnd());				//  メルセンヌツイスターの32ビット版、引数は初期シード
			std::uniform_int_distribution<> rand_x(-1200, 1200);     // [-1200, 1200] 範囲の一様乱数
			std::uniform_int_distribution<> rand_z(-700, 700);     // [-1200, 1200] 範囲の一様乱数
			std::uniform_int_distribution<> rand_y(-400, 700);     // [-400, 700] 範囲の一様乱数
			std::uniform_int_distribution<> rand_Radius(100, 250);		 // [400, 1200] 範囲の一様乱数
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
//攻撃のレート管理処理
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
