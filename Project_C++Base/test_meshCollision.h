//===============================================================================
//
//  C++�g����2D(test_meshCollision.h)
//								����F���n�O��
// 
//===============================================================================
#ifndef _TEST_MESHCOLLISION_H_
#define _TEST_MESHCOLLISION_H_

#include "main.h"
#include "objectX.h"

class CTestMeshCollision :public CObjectX
{
public:
	CTestMeshCollision();				//�R���X�g���N�^
	~CTestMeshCollision()override;		//�f�X�g���N�^
	void Init()override;		//������
	void Uninit()override;		//�I��
	void Update()override;		//�X�V
	void Draw()override;		//�`��
	static CTestMeshCollision* Create(D3DXVECTOR3 pos);

protected:

private:

};

#endif