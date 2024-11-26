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

constexpr int MAX_MODELTYPE = 5;

class CMeshObstacle :public CObjectX
{
public:
	static int GetMaxType()	{	return MAX_MODELTYPE;	}

	CMeshObstacle();				//�R���X�g���N�^
	~CMeshObstacle()override;		//�f�X�g���N�^
	void Init()override;		//������
	void Uninit()override;		//�I��
	void Update()override;		//�X�V
	void Draw()override;		//�`��
	static CMeshObstacle* Create(D3DXVECTOR3 pos,int Type);
	static CMeshObstacle* Create(D3DXVECTOR3 pos, D3DXVECTOR3 rot, D3DXVECTOR3 scale, int Type);
protected:

private:

};



#endif