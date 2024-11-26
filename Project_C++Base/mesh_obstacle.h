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

constexpr int MAX_MODELTYPE = 5;

class CMeshObstacle :public CObjectX
{
public:
	static int GetMaxType()	{	return MAX_MODELTYPE;	}

	CMeshObstacle();				//コンストラクタ
	~CMeshObstacle()override;		//デストラクタ
	void Init()override;		//初期化
	void Uninit()override;		//終了
	void Update()override;		//更新
	void Draw()override;		//描画
	static CMeshObstacle* Create(D3DXVECTOR3 pos,int Type);
	static CMeshObstacle* Create(D3DXVECTOR3 pos, D3DXVECTOR3 rot, D3DXVECTOR3 scale, int Type);
protected:

private:

};



#endif