//===============================================================================
//
//  C++使った2D(watermelon.cpp)
//								制作：元地弘汰
// 
//===============================================================================
#include "particle3D.h"
#include "manager.h"

//==========================================================================================
//コンストラクタ
//==========================================================================================
CParticle3D::CParticle3D():m_bSizeDown(true)
{
	int nIdx = CManager::GetInstance()->GetTexture()->Regist("data\\TEXTURE\\shadow000.jpg");
	BindTexture(CManager::GetInstance()->GetTexture()->GetAddress(nIdx));

}

//==========================================================================================
//デストラクタ
//==========================================================================================
CParticle3D::~CParticle3D()
{

}

//==========================================================================================
//初期化処理
//==========================================================================================
void CParticle3D::Init()
{
	CObject::SetType(TYPE_BILLBOARD);
	CBillboard::Init();
}

//==========================================================================================
//終了処理
//==========================================================================================
void CParticle3D::Uninit()
{
	CBillboard::Uninit();
}

//==========================================================================================
//更新処理
//==========================================================================================
void CParticle3D::Update()
{
	if (m_bSizeDown)
	{
		CBillboard::AddScale(-m_MinutSize);
	}

	if (m_nLifeTime > 0)
	{
		m_nLifeTime--;
	}
	else
	{
		CObject::Release();
		return;
	}
	CBillboard::Update();
}

//==========================================================================================
//描画処理
//==========================================================================================
void CParticle3D::Draw()
{
	LPDIRECT3DDEVICE9 pDevice = CManager::GetInstance()->GetRenderer()->GetDevice();;

	//加算合成の設定
	pDevice->SetRenderState(D3DRS_BLENDOP, D3DBLENDOP_ADD);
	pDevice->SetRenderState(D3DRS_SRCBLEND, D3DBLEND_SRCALPHA);
	pDevice->SetRenderState(D3DRS_DESTBLEND, D3DBLEND_ONE);
	//アルファテスト設定
	pDevice->SetRenderState(D3DRS_ALPHATESTENABLE, TRUE);
	pDevice->SetRenderState(D3DRS_ALPHAREF, 0);
	pDevice->SetRenderState(D3DRS_ALPHAFUNC, D3DCMP_GREATER);

	//Zアルファ
	//pDevice->SetRenderState(D3DRS_ZFUNC, D3DCMP_ALWAYS);
	pDevice->SetRenderState(D3DRS_ZWRITEENABLE, FALSE);

	CBillboard::Draw();

	//通常の合成に戻す設定
	pDevice->SetRenderState(D3DRS_BLENDOP, D3DBLENDOP_ADD);
	pDevice->SetRenderState(D3DRS_SRCBLEND, D3DBLEND_SRCALPHA);
	pDevice->SetRenderState(D3DRS_DESTBLEND, D3DBLEND_INVSRCALPHA);

	//Zアルファ
	pDevice->SetRenderState(D3DRS_ZFUNC, D3DCMP_LESSEQUAL);
	pDevice->SetRenderState(D3DRS_ZWRITEENABLE, TRUE);
	pDevice->SetRenderState(D3DRS_ALPHATESTENABLE, FALSE);
}

//==========================================================================================
//生成処理
//==========================================================================================
CParticle3D* CParticle3D::Create(D3DXVECTOR3 pos, D3DXCOLOR col, float Radius,int LifeTime,bool bSizeDown)
{
	CParticle3D* particle = new CParticle3D;

	particle->SetPolygonParam(pos, Radius, Radius,col);
	particle->Init();
	particle->m_nLifeTime = LifeTime;
	float f = (1.0f / LifeTime);
	particle->m_MinutSize = f;
	particle->m_bSizeDown = bSizeDown;
	return particle;
}