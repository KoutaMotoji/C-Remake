//===============================================================================
//
//  被弾時の爆発エフェクト(eff_bomb.cpp)
//								制作：元地弘汰
// 
//===============================================================================
#include "eff_bomb.h"
#include "manager.h"

namespace
{
	int LOOP_TIME = 2;		//何フレームでアニメーションを切り替えるか
	D3DXVECTOR2 TEX_SLICE = { 5,3 };	//テクスチャの分割数
	int TEX_X = TEX_SLICE.x - 1;		//テクスチャの横分割数-1
	int TEX_Y = TEX_SLICE.y - 1;		//テクスチャの縦分割数-1
	float DEF_POLYSIZE = 60.0f;			//デフォルト時のテクスチャサイズ
};

CEffBomb::CEffBomb(int nPriority) :CBillboard(nPriority), m_nTime(0)
{
	//テクスチャの登録・割り当て
	int nIdx = CManager::GetInstance()->GetTexture()->Regist("data\\TEXTURE\\bomb001.png");
	BindTexture(CManager::GetInstance()->GetTexture()->GetAddress(nIdx), TEX_SLICE);		//横5、縦3に分割
}

CEffBomb::~CEffBomb()
{

}

//==========================================================================================
//初期化処理
//==========================================================================================
void CEffBomb::Init()
{
	CObject::SetType(TYPE_BILLBOARD);		//オブジェクト検索用のタグ付け
	CManager::GetInstance()->GetSound()->PlaySound(CSound::SOUND_LABEL_GAMESE_BOMB);
	CBillboard::Init();
}

//==========================================================================================
//終了処理
//==========================================================================================
void CEffBomb::Uninit()
{
	CBillboard::Uninit();
}

//==========================================================================================
//更新処理
//==========================================================================================
void CEffBomb::Update()
{
	//テクスチャアニメーション処理
	if (m_nTime > LOOP_TIME)	
	{
		D3DXVECTOR2 Anim = CBillboard::GetAnim();
		m_nTime = 0;

		if (Anim.x >= TEX_X)	//テクスチャのX座標を動かす
		{
			CBillboard::AddAnim({ -TEX_SLICE.x,1 });
		}
		if (Anim.y >= TEX_Y && Anim.x >= TEX_X)
		{
			Release();
			return;
		}
		if (Anim.x < TEX_SLICE.x &&
			Anim.y <= TEX_Y)	//テクスチャのY座標を動かす
		{
			CBillboard::AddAnim({ 1,0 });
		}
	}
	else
	{
		m_nTime++;
	}
	CBillboard::Update();
}

//==========================================================================================
//描画処理
//==========================================================================================
void CEffBomb::Draw()
{
	LPDIRECT3DDEVICE9 pDevice = CManager::GetInstance()->GetRenderer()->GetDevice();;

	//深度バッファを無視して描画する
	pDevice->SetRenderState(D3DRS_ZFUNC, D3DCMP_ALWAYS);
	pDevice->SetRenderState(D3DRS_ZWRITEENABLE, FALSE);

	CBillboard::Draw();

	//深度バッファの設定を戻す
	pDevice->SetRenderState(D3DRS_ZFUNC, D3DCMP_LESSEQUAL);
	pDevice->SetRenderState(D3DRS_ZWRITEENABLE, TRUE);
	pDevice->SetRenderState(D3DRS_ALPHATESTENABLE, FALSE);
}

//==========================================================================================
//生成処理
//==========================================================================================
CEffBomb* CEffBomb::Create(D3DXVECTOR3 pos)
{
	CEffBomb* Effect = new CEffBomb;

	Effect->SetPolygonParam(pos, DEF_POLYSIZE, DEF_POLYSIZE);
	Effect->Init();
	Effect->m_nTime = 0;

	return Effect;
}

//==========================================================================================
//生成処理
//==========================================================================================
CEffBomb* CEffBomb::Create(D3DXVECTOR3 pos, float Radius)
{
	CEffBomb* Effect = new CEffBomb;

	Effect->SetPolygonParam(pos, Radius, Radius);
	Effect->Init();
	Effect->m_nTime = 0;

	return Effect;
}
