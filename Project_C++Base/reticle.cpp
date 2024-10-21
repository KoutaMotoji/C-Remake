//===============================================================================
//
//  C++使った2D(watermelon.cpp)
//								制作：元地弘汰
// 
//===============================================================================
#include "reticle.h"
#include "manager.h"

const float CReticle::Poly_Size = 25.0f;

//==========================================================================================
//コンストラクタ
//==========================================================================================
CReticle::CReticle()
{
	int nIdx = CManager::GetInstance()->GetTexture()->Regist("data\\TEXTURE\\reticle000.png");
	BindTexture(CManager::GetInstance()->GetTexture()->GetAddress(nIdx));

}

//==========================================================================================
//デストラクタ
//==========================================================================================
CReticle::~CReticle()
{

}

//==========================================================================================
//初期化処理
//==========================================================================================
void CReticle::Init()
{
	CObject::SetType(TYPE_BILLBOARD);
	CBillboard::Init();
}

//==========================================================================================
//終了処理
//==========================================================================================
void CReticle::Uninit()
{
	CBillboard::Uninit();
}

//==========================================================================================
//更新処理
//==========================================================================================
void CReticle::Update()
{
	CBillboard::Update();
}

//==========================================================================================
//描画処理
//==========================================================================================
void CReticle::Draw()
{
	LPDIRECT3DDEVICE9 pDevice = CManager::GetInstance()->GetRenderer()->GetDevice();;

	//加算合成の設定
	pDevice->SetRenderState(D3DRS_BLENDOP, D3DBLENDOP_ADD);
	pDevice->SetRenderState(D3DRS_SRCBLEND, D3DBLEND_INVDESTCOLOR);
	pDevice->SetRenderState(D3DRS_DESTBLEND, D3DBLEND_INVSRCCOLOR);
	//アルファテスト設定
	pDevice->SetRenderState(D3DRS_ALPHATESTENABLE, TRUE);
	pDevice->SetRenderState(D3DRS_ALPHAREF, 0);
	pDevice->SetRenderState(D3DRS_ALPHAFUNC, D3DCMP_GREATER);


	CBillboard::Draw();

	//通常の合成に戻す設定
	pDevice->SetRenderState(D3DRS_BLENDOP, D3DBLENDOP_ADD);
	pDevice->SetRenderState(D3DRS_SRCBLEND, D3DBLEND_SRCALPHA);
	pDevice->SetRenderState(D3DRS_DESTBLEND, D3DBLEND_INVSRCALPHA);
}

//==========================================================================================
//生成処理
//==========================================================================================
CReticle* CReticle::Create(D3DXVECTOR3 pos)
{
	CReticle* reticle = new CReticle;

	reticle->SetPolygonParam(pos, Poly_Size, Poly_Size);
	reticle->Init();
	return reticle;
}