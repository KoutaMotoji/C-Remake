//===============================================================================
//
//  C++使った2D(test_meshCollision.h)
//								制作：元地弘汰
// 
//===============================================================================
#ifndef _TEST_MESHCOLLISION_H_
#define _TEST_MESHCOLLISION_H_

#include "main.h"
#include "objectX.h"

class CTestMeshCollision :public CObjectX
{
public:
	CTestMeshCollision();				//コンストラクタ
	~CTestMeshCollision()override;		//デストラクタ
	void Init()override;		//初期化
	void Uninit()override;		//終了
	void Update()override;		//更新
	void Draw()override;		//描画
	static CTestMeshCollision* Create(D3DXVECTOR3 pos);

protected:

private:

};

#endif