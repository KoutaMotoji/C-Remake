//===============================================================================
//
//  C++使った2D(object3D.h)
//								制作：元地弘汰
// 
//===============================================================================
#ifndef _PARTICLE3D_H_
#define _PARTICLE3D_H_

#include "main.h"
#include "billboard.h"

class CParticle3D :public CBillboard
{
public:
	CParticle3D();				//コンストラクタ
	~CParticle3D()override;		//デストラクタ
	void Init()override;		//初期化
	void Uninit()override;		//終了
	void Update()override;		//更新
	void Draw()override;		//描画
	static CParticle3D* Create(D3DXVECTOR3 pos,D3DXCOLOR col,float Radius,int LifeTime,bool bSizeDown);
private:
	int m_nLifeTime;		//消えるまでの時間
	float m_MinutSize;		//毎秒減算するサイズ
	bool m_bSizeDown;
};

#endif