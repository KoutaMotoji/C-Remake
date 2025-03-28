//===============================================================================
//
//  リザルト画面演出の煙エフェクト(eff_smoke.cpp)
//								制作：元地弘汰
// 
//===============================================================================
#include "eff_smoke.h"
#include "manager.h"

namespace
{
	//乱数生成の上限・下限の設定

	int XZ_RAND_MIN = -8;
	int XZ_RAND_MAX = 8;

	int Y_RAND_MIN = 10;
	int Y_RAND_MAX = 30;

	int ROTV_RAND_MIN = 800;
	int ROTV_RAND_MAX = 1500;

	int ADDSIZE_RAND_MIN = 80;
	int ADDSIZE_RAND_MAX = 150;

	float F_CLAC_NUM = 0.15f;

};


CEffSmoke::CEffSmoke(int nPriority) :CBillboard(nPriority), m_nTime(0)
{
	//テクスチャの登録・割り当て
	int nIdx = CManager::GetInstance()->GetTexture()->Regist("data\\TEXTURE\\smoke.png");
	BindTexture(CManager::GetInstance()->GetTexture()->GetAddress(nIdx), { 1,1 });
}

CEffSmoke::~CEffSmoke()
{

}

//==========================================================================================
//初期化処理
//==========================================================================================
void CEffSmoke::Init()
{
	CObject::SetType(TYPE_BILLBOARD);
	m_moveValue = SetRandValue();
	CBillboard::Init();
}

//==========================================================================================
//終了処理
//==========================================================================================
void CEffSmoke::Uninit()
{
	CBillboard::Uninit();
}

//==========================================================================================
//更新処理
//==========================================================================================
void CEffSmoke::Update()
{
	--m_nLife;
	if (m_nLife < 0)	//残留時間が0以下の時
	{
		//オブジェクトを解放
		CObject::Release();
		return;
	}

	//演出用処理
	CBillboard::AddPos(m_moveValue);				
	CBillboard::AddRot({ 0.0f,0.0f,m_fRotValue });
	CBillboard::AddScale(0.05f);

	CBillboard::Update();
}

//==========================================================================================
//描画処理
//==========================================================================================
void CEffSmoke::Draw()
{
	LPDIRECT3DDEVICE9 pDevice = CManager::GetInstance()->GetRenderer()->GetDevice();;

	// 法線の自動正規化を有効に
	pDevice->SetRenderState(D3DRS_NORMALIZENORMALS, TRUE);
	pDevice->SetRenderState(D3DRS_CULLMODE, D3DCULL_NONE);	//カリングを両面に

	//アルファテスト設定
	pDevice->SetRenderState(D3DRS_ALPHATESTENABLE, TRUE);
	pDevice->SetRenderState(D3DRS_ALPHAREF, 0);
	pDevice->SetRenderState(D3DRS_ALPHAFUNC, D3DCMP_GREATER);

	CBillboard::Draw();

	//通常の合成に戻す設定
	pDevice->SetRenderState(D3DRS_BLENDOP, D3DBLENDOP_ADD);
	pDevice->SetRenderState(D3DRS_SRCBLEND, D3DBLEND_SRCALPHA);
	pDevice->SetRenderState(D3DRS_DESTBLEND, D3DBLEND_INVSRCALPHA);
	// 法線の自動正規化を無効に
	pDevice->SetRenderState(D3DRS_NORMALIZENORMALS, FALSE);
	pDevice->SetRenderState(D3DRS_CULLMODE, D3DCULL_CCW);	//カリングをもどす

}

//==========================================================================================
//生成処理
//==========================================================================================
CEffSmoke* CEffSmoke::Create(D3DXVECTOR3 pos, float Radius,int nLife)
{
	CEffSmoke* Effect = new CEffSmoke;

	Effect->SetPolygonParam(pos, Radius, Radius);
	Effect->Init();
	Effect->m_nLife = nLife;
	Effect->m_nTime = 0;
	return Effect;
}

//==========================================================================================
//生成処理
//==========================================================================================
D3DXVECTOR3 CEffSmoke::SetRandValue()
{
	D3DXVECTOR3 vec;
	CEffSmoke* Effect = new CEffSmoke;

	std::random_device rnd;			// 非決定的な乱数生成器でシード生成機を生成
	std::mt19937 mt(rnd());			//  メルセンヌツイスターの32ビット版、引数は初期シード
	std::uniform_int_distribution<> rand_x(XZ_RAND_MIN, XZ_RAND_MAX);		// [-8, 8] 範囲の一様乱数
	std::uniform_int_distribution<> rand_y(Y_RAND_MIN, Y_RAND_MAX);		// [10, 30] 範囲の一様乱数
	std::uniform_int_distribution<> rand_z(XZ_RAND_MIN, XZ_RAND_MAX);		// [-8, 8] 範囲の一様乱数
	std::uniform_int_distribution<> rotV(ROTV_RAND_MIN, ROTV_RAND_MAX);	// [800, 1500] 範囲の一様乱数
	std::uniform_int_distribution<> addSize(ADDSIZE_RAND_MIN, ADDSIZE_RAND_MAX);	// [80, 150] 範囲の一様乱数

	vec = {
		(float)(rand_x(mt))* F_CLAC_NUM,
		(float)(rand_y(mt))* F_CLAC_NUM,
		(float)(rand_z(mt))* F_CLAC_NUM
	};

	m_fRotValue = ((float)rotV(mt) * 0.0001);
	AddScale((float)(addSize(mt) * 0.008f));
	return vec;
}