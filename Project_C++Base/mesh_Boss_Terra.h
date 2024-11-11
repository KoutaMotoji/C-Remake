//===============================================================================
//
//  C++�g����2D(enemy_basic.h)
//								����F���n�O��
// 
//===============================================================================
#ifndef _BOSS_TERRA_H_
#define _BOSS_TERRA_H_

#include "main.h"
#include "objectX.h"
#include "gauge_Boss_Life.h"

class CBossTerra :public CObjectX
{
public:
	CBossTerra();				//�R���X�g���N�^
	~CBossTerra()override;		//�f�X�g���N�^
	void Init()override;		//������
	void Uninit()override;		//�I��
	void Update()override;		//�X�V
	void Draw()override;		//�`��
	static CBossTerra* Create(D3DXVECTOR3 pos);

	void Damaged(int nDmg) { m_nLife -= nDmg; m_Gauge->SetGauge(m_nLife); };
protected:

private:
	CGaugeBoss* m_Gauge;
	int m_nLife;
	bool m_bMove;
	bool m_bDead;
};



#endif