//===============================================================================
//
//  チュートリアルシール用メッシュスカイボックス処理(tu_sky.cpp)
//								制作：元地弘汰
//
//===============================================================================
#include "tu_sky.h"
#include "player_observer.h"

#include "manager.h"

//静的メンバ初期化
const float CTutorialSky::MAX_WIDTH = 12000.0f;
const float CTutorialSky::MAX_HEIGHT = 10000.0f;


const int CTutorialSky::MAX_CORNER = 8;

const int CTutorialSky::MAX_VTX = MAX_CORNER * 2;
const int CTutorialSky::MAX_INDEX = MAX_VTX + 2;

CTutorialSky::CTutorialSky(int nPriority) : CObject(nPriority),
		m_pos({ 0.0f,0.0f,0.0f }),
		m_rot({ 0.0f,0.0f,0.0f })
{

}

CTutorialSky::~CTutorialSky()
{

}

//==========================================================================================
//初期化処理
//==========================================================================================
void CTutorialSky::Init()
{
	//各ポインタの初期化
	m_apTexMeshCylinder = nullptr;
	m_pMesh = nullptr;

	CObject::SetType(TYPE_3D_MADEMESH);

	LPDIRECT3DDEVICE9 pDevice = CManager::GetInstance()->GetRenderer()->GetDevice();;
	//テクスチャの読み込み
	D3DXCreateTextureFromFile(pDevice,
		"data\\TEXTURE\\sky_bg005.png",
		&m_apTexMeshCylinder);

	D3DXCreateMeshFVF(
		(DWORD)MAX_VTX,
		(DWORD)MAX_VTX,
		D3DXMESH_WRITEONLY | D3DXMESH_MANAGED,
		FVF_VERTEX_3D,
		pDevice,
		&m_pMesh);

	VERTEX_3D* pVtx;	//頂点情報のポインタ

	//メッシュの頂点バッファのロック
	m_pMesh->LockVertexBuffer(0, (LPVOID*)&pVtx);

	for (int i = 0; i < 2; ++i) {	//頂点座標の設定
		for (int j = 0; j < MAX_CORNER; ++j) {
			float radian = (((float)j) / (float)MAX_CORNER);
			int nNum = ((i * MAX_CORNER) + j);
			pVtx[nNum].pos.x = m_pos.x + (cosf(radian * 2 * D3DX_PI) * MAX_WIDTH);
			pVtx[nNum].pos.z = m_pos.z + (sinf(radian * 2 * D3DX_PI) * MAX_WIDTH);
			pVtx[nNum].pos.y = m_pos.y + i * -MAX_HEIGHT;
		}
	}
	for (int i = 0; i < MAX_VTX; ++i)	//法線とカラーの設定
	{
		pVtx[i].nor = D3DXVECTOR3(0.0f, 1.0f, 0.0f);

		pVtx[i].col = D3DCOLOR_RGBA(255, 255, 255, 255);
	}
	for (int i = 0; i < 2; ++i)			//テクスチャ座標の設定
	{
		for (int j = 0; j < MAX_CORNER; ++j) {
			int nNum = ((i * MAX_CORNER) + j);

			pVtx[nNum].tex = {
				(float)((1.0f / (MAX_CORNER)) * j * 2),
				(float)(1.0f * i)

			};
		}
	}
	//メッシュの頂点バッファのアンロック
	m_pMesh->UnlockVertexBuffer();

	int nLoop = 0;

	WORD* pIdx;	//インデックス情報のポインタ
	//メッシュのインデックスバッファのロック
	m_pMesh->LockIndexBuffer(0, (LPVOID*)&pIdx);

	for (int X = 0; X < MAX_CORNER - 1; ++X)	//メッシュのインデックス番号の設定
	{
		pIdx[nLoop] = (X + MAX_CORNER);
		++nLoop;

		pIdx[nLoop] = X;
		++nLoop;

		pIdx[nLoop] = (X + 1 + MAX_CORNER);
		++nLoop;


		pIdx[nLoop] = X;
		++nLoop;

		pIdx[nLoop] = (X + 1 + MAX_CORNER);
		++nLoop;

		pIdx[nLoop] = X + 1;
		++nLoop;
	}

	pIdx[nLoop] = (MAX_VTX - 1);
	++nLoop;

	pIdx[nLoop] = (MAX_CORNER - 1);
	++nLoop;

	pIdx[nLoop] = (MAX_CORNER);
	++nLoop;

	pIdx[nLoop] = (MAX_CORNER - 1);
	++nLoop;

	pIdx[nLoop] = (MAX_CORNER);
	++nLoop;

	pIdx[nLoop] = 0;

	//メッシュのインデックスバッファのアンロック
	m_pMesh->UnlockIndexBuffer();
}

//==========================================================================================
//終了処理
//==========================================================================================
void CTutorialSky::Uninit()
{
	if (m_apTexMeshCylinder != nullptr)	//テクスチャの破棄
	{
		m_apTexMeshCylinder->Release();
		m_apTexMeshCylinder = nullptr;
	}
	if (m_pMesh != nullptr)				//メッシュの破棄
	{
		m_pMesh->Release();
		m_pMesh = nullptr;
	}
}

//==========================================================================================
//更新処理
//==========================================================================================
void CTutorialSky::Update()
{
	//Z座標をプレイヤーに追従させる
	m_pos.z = CPlayerObserver::GetInstance()->GetPlayerPos().z;
}

//==========================================================================================
//描画処理
//==========================================================================================
void CTutorialSky::Draw()
{
	LPDIRECT3DDEVICE9 pDevice;
	//デバイスの取得
	pDevice = CManager::GetInstance()->GetRenderer()->GetDevice();


	//計算用マトリックス
	D3DXMATRIX mtxRot, mtxTrans;
	//ワールドマトリックス
	D3DXMatrixIdentity(&m_mtx);
	//向きを反映
	D3DXMatrixRotationYawPitchRoll(&mtxRot,
		m_rot.y,
		m_rot.x,
		m_rot.z);
	D3DXMatrixMultiply(&m_mtx,
		&m_mtx,
		&mtxRot);
	//位置を反映
	D3DXMatrixTranslation(&mtxTrans,
		m_pos.x,
		m_pos.y,
		m_pos.z);
	D3DXMatrixMultiply(&m_mtx,
		&m_mtx,
		&mtxTrans);
	//ワールドマトリックスの設定
	pDevice->SetTransform(D3DTS_WORLD,
		&m_mtx);

	pDevice->SetTexture(0, m_apTexMeshCylinder);

	// 法線の自動正規化を有効に
	pDevice->SetRenderState(D3DRS_NORMALIZENORMALS, TRUE);
	pDevice->SetRenderState(D3DRS_CULLMODE, D3DCULL_NONE);	//カリングを両面に

	//加算合成の設定
	pDevice->SetRenderState(D3DRS_BLENDOP, D3DBLENDOP_ADD);
	pDevice->SetRenderState(D3DRS_SRCBLEND, D3DBLEND_SRCALPHA);
	pDevice->SetRenderState(D3DRS_DESTBLEND, D3DBLEND_ONE);
	 
	//アルファテスト設定
	pDevice->SetRenderState(D3DRS_ALPHATESTENABLE, TRUE);
	pDevice->SetRenderState(D3DRS_ALPHAREF, 0);
	pDevice->SetRenderState(D3DRS_ALPHAFUNC, D3DCMP_GREATER);

	m_pMesh->DrawSubset(0);

	//通常の合成に戻す設定
	pDevice->SetRenderState(D3DRS_BLENDOP, D3DBLENDOP_ADD);
	pDevice->SetRenderState(D3DRS_SRCBLEND, D3DBLEND_SRCALPHA);
	pDevice->SetRenderState(D3DRS_DESTBLEND, D3DBLEND_INVSRCALPHA);

	// 法線の自動正規化を無効に
	pDevice->SetRenderState(D3DRS_NORMALIZENORMALS, FALSE);
	pDevice->SetRenderState(D3DRS_CULLMODE, D3DCULL_CCW);	//カリング戻し
}


//==========================================================================================
//生成処理
//==========================================================================================
CTutorialSky* CTutorialSky::Create(D3DXVECTOR3 pos)
{
	CTutorialSky* field = new CTutorialSky;
	field->Init();
	field->m_pos = pos;
	field->m_pos.y += MAX_HEIGHT * 0.6;
	return field;
}
