//===============================================================================
//
//  C++�g����3D(tree_billboard.h)
//								����F���n�O��
// 
//===============================================================================
#ifndef _TREE_BILLBOARD_H_
#define _TREE_BILLBOARD_H_

#include "main.h"
#include "billboard.h"

namespace {
	float Poly_Radius = 300.0f;
}

class CTreeBillboard :public CBillboard
{
public:
	CTreeBillboard(int nPriority = 5) ;				//�R���X�g���N�^
	~CTreeBillboard()override;		//�f�X�g���N�^
	void Init()override;		//������
	void Uninit()override;		//�I��
	void Update()override;		//�X�V
	void Draw()override { CBillboard::Draw(); };		//�`��

	static CTreeBillboard* Create(D3DXVECTOR3 pos,int TexIdx);
	void SetPosGround(float HalfRadius);
private:
	int m_snTexIdx[3];
};

#endif