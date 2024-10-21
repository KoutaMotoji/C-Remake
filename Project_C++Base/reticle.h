//===============================================================================
//
//  C++使った2D(object3D.h)
//								制作：元地弘汰
// 
//===============================================================================
#ifndef _RETICLE_H_
#define _RETICLE_H_

#include "main.h"
#include "billboard.h"

class CReticle :public CBillboard
{
public:
	CReticle();				//コンストラクタ
	~CReticle()override;		//デストラクタ
	void Init()override;		//初期化
	void Uninit()override;		//終了
	void Update()override;		//更新
	void Draw()override;		//描画
	static CReticle* Create(D3DXVECTOR3 pos);
private:
	static const float Poly_Size;
};

#endif