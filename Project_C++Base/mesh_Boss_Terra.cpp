//===============================================================================
//
//  C++使った2D(enemy_basic.cpp)
//								制作：元地弘汰
// 
//===============================================================================
#include "mesh_Boss_Terra.h"
#include "eff_explosion.h"
#include "playerX.h"

#include "manager.h"
#include "game.h"
#include <random>

//==========================================================================================
//コンストラクタ
//==========================================================================================
CBossTerra::CBossTerra():m_bMove(false), m_nLife(400), m_bDead(false), m_bDamaging(false), m_nDamageFrame(0),m_nDeadFrame(0)
{

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