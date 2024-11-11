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
#include "gauge_Boss_Life.h"

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

	void Damaged(int nDmg) { m_nLife -= nDmg; m_Gauge->SetGauge(m_nLife); };
protected:

private:
	CGaugeBoss* m_Gauge;
	int m_nLife;
	bool m_bMove;
	bool m_bDead;
};



#endif