//===============================================================================
//
//  C++�g����3D(shadow.h)
//								����F���n�O��
// 
//===============================================================================
#ifndef _SHADOW_H_
#define _SHADOW_H_

#include "main.h"
#include "object3D.h"

static constexpr float DEF_RADIUS = 200.0f;

class CShadow :public CObject3D
{
public:
	CShadow() {}				//�R���X�g���N�^
	~CShadow()override = default;		//�f�X�g���N�^
	void Init()override;		//������
	void Uninit()override { CObject3D::Uninit(); }		//�I��
	void Update()override { CObject3D::Update(); }		//�X�V
	void Draw()override;		//�`��

	static CShadow* Create(D3DXVECTOR3 pos);
private:

};

#endif