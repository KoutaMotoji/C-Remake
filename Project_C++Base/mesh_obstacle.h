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

class CMeshObstacle :public CObjectX
{
public:
	CMeshObstacle();				//�R���X�g���N�^
	~CMeshObstacle()override;		//�f�X�g���N�^
	void Init()override;		//������
	void Uninit()override;		//�I��
	void Update()override;		//�X�V
	void Draw()override;		//�`��
	static CMeshObstacle* Create(D3DXVECTOR3 pos,int Type);
protected:

private:

};



#endif