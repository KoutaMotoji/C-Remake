//===============================================================================
//
//  C++使った2D(enemy_basic.h)
//								制作：元地弘汰
// 
//===============================================================================
#ifndef _TEST_OBSTACLE_H_
#define _TEST_OBSTACLE_H_

#include "main.h"
#include "objectX.h"

class CMeshObstacle :public CObjectX
{
public:
	CMeshObstacle();				//コンストラクタ
	~CMeshObstacle()override;		//デストラクタ
	void Init()override;		//初期化
	void Uninit()override;		//終了
	void Update()override;		//更新
	void Draw()override;		//描画
	static CMeshObstacle* Create(D3DXVECTOR3 pos,int Type);
protected:

private:

};



#endif