//===============================================================================
//
//  C++使った2D(object3D.h)
//								制作：元地弘汰
// 
//===============================================================================
#ifndef _MESH_CYLINDER_H_
#define _MESH_CYLINDER_H_

#include "main.h"
#include "object.h"

class CMeshCylinder :public CObject
{
public:
	CMeshCylinder();				//コンストラクタ
	~CMeshCylinder()override;		//デストラクタ
	void Init()override;		//初期化
	void Uninit()override;		//終了
	void Update()override;		//更新
	void Draw()override;		//描画
	static CMeshCylinder* Create(D3DXVECTOR3 pos);
private:
	int m_nVtx;
	
	D3DXVECTOR3 m_pos, m_rot;
	D3DXMATRIX m_mtx;

	//テクスチャ
	LPDIRECT3DTEXTURE9 m_apTexMeshCylinder;
	//頂点情報のポインタ
	LPDIRECT3DVERTEXBUFFER9 m_pVtxBuffMeshCylinder;
	//インデックスバッファへのポインタ
	LPDIRECT3DINDEXBUFFER9 m_pIdxBuffMeshCylinder;

	static const int MAX_VTX;
	static const int MAX_CORNER;
	static const int MAX_INDEX;

	static const float MAX_WIDTH;
	static const float MAX_HEIGHT;

};

#endif