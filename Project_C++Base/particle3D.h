//===============================================================================
//
//  C++�g����2D(object3D.h)
//								����F���n�O��
// 
//===============================================================================
#ifndef _PARTICLE3D_H_
#define _PARTICLE3D_H_

#include "main.h"
#include "billboard.h"

class CParticle3D :public CBillboard
{
public:
	CParticle3D();				//�R���X�g���N�^
	~CParticle3D()override;		//�f�X�g���N�^
	void Init()override;		//������
	void Uninit()override;		//�I��
	void Update()override;		//�X�V
	void Draw()override;		//�`��
	static CParticle3D* Create(D3DXVECTOR3 pos,D3DXCOLOR col,float Radius,int LifeTime,bool bSizeDown);
private:
	int m_nLifeTime;		//������܂ł̎���
	float m_MinutSize;		//���b���Z����T�C�Y
	bool m_bSizeDown;
};

#endif