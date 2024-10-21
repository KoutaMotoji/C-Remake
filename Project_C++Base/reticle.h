//===============================================================================
//
//  C++�g����2D(object3D.h)
//								����F���n�O��
// 
//===============================================================================
#ifndef _RETICLE_H_
#define _RETICLE_H_

#include "main.h"
#include "billboard.h"

class CReticle :public CBillboard
{
public:
	CReticle();				//�R���X�g���N�^
	~CReticle()override;		//�f�X�g���N�^
	void Init()override;		//������
	void Uninit()override;		//�I��
	void Update()override;		//�X�V
	void Draw()override;		//�`��
	static CReticle* Create(D3DXVECTOR3 pos);
private:
	static const float Poly_Size;
};

#endif