//===============================================================================
//
//  C++�g����2D(enemy_basic.h)
//								����F���n�O��
// 
//===============================================================================
#ifndef _TEST_OBSTACLE_H_
#define _TEST_OBSTACLE_H_

#include "main.h"
#include "objectX.h"

class CTestObstacle :public CObjectX
{
public:
	CTestObstacle();				//�R���X�g���N�^
	~CTestObstacle()override;		//�f�X�g���N�^
	void Init()override;		//������
	void Uninit()override;		//�I��
	void Update()override;		//�X�V
	void Draw()override;		//�`��
	static CTestObstacle* Create(D3DXVECTOR3 pos,int Type);
protected:

private:

};



#endif