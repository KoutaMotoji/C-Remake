//===============================================================================
//
//  C++使った2D(enemy_basic.h)
//								制作：元地弘汰
// 
//===============================================================================
#ifndef _ENEMY_TERRA_H_
#define _ENEMY_TERRA_H_

#include "main.h"
#include "objectX.h"

class CEnemyBase :public CObjectX
{
public:
	CEnemyBase();				//コンストラクタ
	~CEnemyBase()override;		//デストラクタ
	void Init()override;		//初期化
	void Uninit()override;		//終了
	void Update()override;		//更新
	void Draw()override;		//描画
	static CEnemyBase* Create(D3DXVECTOR3 pos);

	void Damaged();

protected:
	bool m_bMove;
	D3DXVECTOR3 m_DefPos;
private:
};



#endif