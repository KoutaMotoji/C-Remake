//===============================================================================
//
//  チュートリアルシール用メッシュスカイボックス処理(tu_sky.h)
//								制作：元地弘汰
// 
//===============================================================================
#ifndef _TUTORIAL_SKY_H_
#define _TUTORIAL_SKY_H_

#include "main.h"
#include "object.h"

class CTutorialSky :public CObject
{
public:
	CTutorialSky(int nPliority = 0);				//コンストラクタ
	~CTutorialSky()override;		//デストラクタ
	void Init()override;		//初期化
	void Uninit()override;		//終了
	void Update()override;		//更新
	void Draw()override;		//描画
	static CTutorialSky* Create(D3DXVECTOR3 pos);

	inline LPD3DXMESH GetMesh() { return m_pMesh; };
	inline D3DXVECTOR3 GetPos() { return m_pos; }
private:
	D3DXVECTOR3 m_pos, m_rot;
	D3DXMATRIX m_mtx;

	LPD3DXMESH m_pMesh;

	//テクスチャ
	LPDIRECT3DTEXTURE9 m_apTexMeshCylinder;

	static const int MAX_VTX;
	static const int MAX_CORNER;
	static const int MAX_INDEX;

	static const float MAX_WIDTH;
	static const float MAX_HEIGHT;
};

#endif