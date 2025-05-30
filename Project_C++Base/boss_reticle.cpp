//===============================================================================
//
//  ボスのビーム射撃時のレティクルの処理(boss_reticle.cpp)
//								制作：元地弘汰
// 
//===============================================================================
#include "boss_reticle.h"
#include "manager.h"

CBossReticle::CBossReticle(int nPriority) : CBillboard(nPriority)
{
	//テクスチャの登録・割り当て
	int nIdx = CManager::GetInstance()->GetTexture()->Regist("data\\TEXTURE\\reticle001.png");
	BindTexture(CManager::GetInstance()->GetTexture()->GetAddress(nIdx));

}

CBossReticle::~CBossReticle()
{

}

//==========================================================================================
//初期化処理
//==========================================================================================
void CBossReticle::Init()
{
	CObject::SetType(TYPE_BILLBOARD);
	CBillboard::Init();
}

//==========================================================================================
//終了処理
//==========================================================================================
void CBossReticle::Uninit()
{
	CBillboard::Uninit();
}

//==========================================================================================
//更新処理
//==========================================================================================
void CBossReticle::Update()
{
	--m_nLife;
	CBillboard::AddRot({ 0.0f,0.0f,m_RotateSpeed });
	CBillboard::AddScale(-Poly_MinutSize);
	CBillboard::Update();
}

//==========================================================================================
//描画処理
//==========================================================================================
void CBossReticle::Draw()
{
	CBillboard::Draw();
}

//==========================================================================================
//生成処理
//==========================================================================================
CBossReticle* CBossReticle::Create(D3DXVECTOR3 pos, float Radius, int nLife, float Rotate)
{
	CBossReticle* reticle = new CBossReticle;

	reticle->SetPolygonParam(pos, Radius, Radius);
	reticle->Init();
	reticle->m_nLife = nLife;
	reticle->Poly_MinutSize = 1.0f / nLife;
	reticle->m_RotateSpeed = Rotate;
	return reticle;
}