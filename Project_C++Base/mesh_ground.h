//===============================================================================
//
//  C++�g����2D(mesh_ground.h)
//								����F���n�O��
// 
//===============================================================================
#ifndef _MESH_GROUND_H_
#define _MESH_GROUND_H_

#include "main.h"
#include "objectX.h"

class CMeshGround :public CObjectX
{
public:
	CMeshGround();				//�R���X�g���N�^
	~CMeshGround()override;		//�f�X�g���N�^
	void Init()override;		//������
	void Uninit()override;		//�I��
	void Update()override;		//�X�V
	void Draw()override;		//�`��
	static CMeshGround* Create(D3DXVECTOR3 pos);

protected:

private:

};

#endif