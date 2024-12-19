//===============================================================================
//
//  C++使った2D(mesh_Boss_Terra.h)
//								制作：元地弘汰
// 
//===============================================================================
#ifndef _BOSS_TERRA_H_
#define _BOSS_TERRA_H_

#include "main.h"
#include "objectX.h"
#include "gauge_Boss_Life.h"
#include "mesh_obstacle.h"
#include "boss_reticle.h"
#include "shadow.h"

static constexpr float WORLD_WALL_X = 1000;
static constexpr float WORLD_WALL_Y = 600;


class CBossTerra :public CObjectX
{
public:
	CBossTerra();				//コンストラクタ
	~CBossTerra()override;		//デストラクタ
	void Init()override;		//初期化
	void Uninit()override;		//終了
	void Update()override;		//更新
	void SetStatue();
	void SetBullet(D3DXVECTOR3& pos, D3DXVECTOR3& Playerpos);
	void Draw()override;		//描画
	static CBossTerra* Create(D3DXVECTOR3 pos);

	void Damaged(int nDmg) { m_nLife -= nDmg; m_Gauge->SetGauge(m_nLife); m_bDamaging = true; m_nDamageFrame = 0; };
	void DeathAnim();
	void DeathCheck();
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

	CShadow* m_pShadow;

};

class CBossStatue : public CMeshObstacle
{
public:
	CBossStatue() :m_bSeted(false) {};
	~CBossStatue()override = default;
	void Update()override
	{
		if (!m_bSeted)
		{
			SetYPos();
		}
	}
	static CBossStatue* Create(D3DXVECTOR3 pos);
private:
	void SetYPos();
	bool m_bSeted;
};

class CBossEnemySpawner : public CObjectX
{
public:
	CBossEnemySpawner() : m_moveVec({0.0f,0.0f,0.0f}), m_Lifetime(), m_CntTime(0){};
	~CBossEnemySpawner()override = default;

	void Init(int num);
	void Update()override;
	static CBossEnemySpawner* Create(D3DXVECTOR3 pos,int num);
private:
	void Move();
	void SetEnemy();
	D3DXVECTOR3 m_moveVec;
	int m_Lifetime;
	int m_CntTime;
};

#endif