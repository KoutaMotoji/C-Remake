//===============================================================================
//
//  C++使った2D(enemy_basic.h)
//								制作：元地弘汰
// 
//===============================================================================
#ifndef _BOSS_TERRA_H_
#define _BOSS_TERRA_H_

#include "main.h"
#include "objectX.h"

class CBossTerra :public CObjectX
{
public:
	CBossTerra();				//コンストラクタ
	~CBossTerra()override;		//デストラクタ
	void Init()override;		//初期化
	void Uninit()override;		//終了
	void Update()override;		//更新
	void Draw()override;		//描画
	static CBossTerra* Create(D3DXVECTOR3 pos);
protected:

private:
	bool m_bMove;
};



#endif