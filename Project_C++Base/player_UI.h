//===============================================================================
//
//  C++�g����3D(gauge_stamina.h)
//								����F���n�O��
// 
//===============================================================================
#ifndef _GAUGE_LIFE_H_
#define _GAUGE_LIFE_H_

#include "main.h"
#include "object2D.h"


class CGaugeLife :public CObject2D
{
public:
	CGaugeLife(int nPriority = 6);		//�R���X�g���N�^
	~CGaugeLife()override;				//�f�X�g���N�^
	void Init()override;		//������
	void Uninit()override;		//�I��
	void Update()override;		//�X�V
	void Draw()override;		//�`��
	static CGaugeLife* Create(int nMaxGauge);
private:
	void SetGauge();

	static const float OBJ_HEIGHT;
	static const float OBJ_WIDTH;

};

class CGaugeLiFrame :public CObject2D
{
public:
	CGaugeLiFrame(int nPriority = 6) :CObject2D(nPriority) {};		//�R���X�g���N�^
	~CGaugeLiFrame()override = default;				//�f�X�g���N�^
	void Init()override;		//������

	static CGaugeLiFrame* Create(D3DXVECTOR3 pos, float fWidth, float fHeight);
private:
};

class CGaugeLiBack :public CObject2D
{
public:
	CGaugeLiBack(int nPriority = 5) : CObject2D(nPriority) {};		//�R���X�g���N�^
	~CGaugeLiBack()override = default;				//�f�X�g���N�^
	void Init()override;		//������

	static CGaugeLiBack* Create(D3DXVECTOR3 pos, float fWidth, float fHeight);
private:
};

#endif