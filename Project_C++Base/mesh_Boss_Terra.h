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
#include "boss_reticle.h"



class CBossTerra :public CObjectX
{
public:
	CBossTerra();				//�R���X�g���N�^
	~CBossTerra()override;		//�f�X�g���N�^
	void Init()override;		//������
	void Uninit()override;		//�I��
	void Update()override;		//�X�V
	void SetBullet(D3DXVECTOR3& pos, D3DXVECTOR3& Playerpos);
	void Draw()override;		//�`��
	static CBossTerra* Create(D3DXVECTOR3 pos);

	void Damaged(int nDmg) { m_nLife -= nDmg; m_Gauge->SetGauge(m_nLife); m_bDamaging = true; m_nDamageFrame = 0; };
	void DeathAnim();
	void DeathCheck() {
		if (m_nLife <= 0&&!m_bDead)
		{
			CObjectX::AddRot({ 0.4f,0.0f,0.6f });
			m_bDead = true;
		}
	};
	bool GetDamageState() { return m_bDamaging; }
	bool GetDeadState() { return m_bDead; }
	bool AttackRateCheck();
protected:

private:
	CBossReticle* m_Reticle[2];
	CGaugeBoss* m_Gauge;
	D3DXVECTOR3 m_move;
	int m_nLife;
	bool m_bMove;
	bool m_bDead;
	int m_nDamageFrame;
	int m_nDeadFrame;
	int m_nAttackFrame;
	bool m_bDamaging;
};



#endif