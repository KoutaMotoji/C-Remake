//===============================================================================
//
//  C++�g����2D(mesh_Boss_Terra.h)
//								����F���n�O��
// 
//===============================================================================
#ifndef _BOSS_TERRA_H_
#define _BOSS_TERRA_H_

#include "main.h"
#include "object.h"
#include "gauge_Boss_Life.h"
#include "mesh_obstacle.h"
#include "boss_reticle.h"
#include "modelparts.h"

#include "shadow.h"

static constexpr float WORLD_WALL_X = 1000;
static constexpr float WORLD_WALL_Y = 600;

//���[�V�����p�萔
static constexpr int B_MAX_MODELPARTS = 21;
static constexpr int B_MAX_PARTS = 21;
static constexpr int B_MAX_KEYSET = 21;
static constexpr int B_MAX_MOTION = 7;

class CBossTerra :public CObject
{
public:
	CBossTerra();				//�R���X�g���N�^
	~CBossTerra()override;		//�f�X�g���N�^
	void Init()override;		//������
	void Uninit()override;		//�I��
	void Update()override;		//�X�V
	void Attack(D3DXVECTOR3& Playerpos);
	void SetStatue();
	void SetBullet(D3DXVECTOR3& pos, D3DXVECTOR3& Playerpos);
	void Draw()override;		//�`��
	static CBossTerra* Create(D3DXVECTOR3 pos);

	void Damaged(int nDmg) { m_nLife -= nDmg; m_Gauge->SetGauge(m_nLife); m_bDamaging = true; m_nDamageFrame = 0; };
	void DeathAnim();
	void DeathCheck();
	bool GetDamageState() { return m_bDamaging; }
	bool GetDeadState() { return m_bDead; }
	bool AttackRateCheck();
	D3DXMATRIX GetBossMtx(int idx) { return m_apModelParts[idx]->GetWorldMatrix(); }
	LPD3DXMESH GetBossMesh(int idx) { return m_apModelParts[idx]->GetMesh(); }
protected:

private:
	D3DXVECTOR3 m_pos, m_rot, m_size;	//���W�E��]�E�傫��
	D3DXVECTOR3 m_move;				//�ړ���
	D3DXMATRIX m_mtxWorld;			//���[���h�}�g���b�N�X
	//D3DXMATRIX m_mtxWeaponWorld;	//����̃��[���h�}�g���b�N�X
	//D3DXVECTOR3 m_WeaponCollisionPos;		//����̊p�x�����ƂɎZ�o���铖���蔻��̑��Έʒu

	CBossReticle* m_Reticle[2];
	CGaugeBoss* m_Gauge;
	int m_nLife;
	bool m_bMove;
	bool m_bDead;
	int m_nDamageFrame;
	int m_nDeadFrame;
	int m_nAttackFrame;
	bool m_bTransformed;
	bool m_bDamaging;

	CModelParts* m_apModelParts[B_MAX_MODELPARTS];

	char* m_pModelFileName[B_MAX_MODELPARTS];
	int m_ModelParts;	//���f���p�[�c��
	int m_CurKey;		//���݂̃L�[�ԍ�
	int m_CurMotion;	//���݂̃��[�V�����ԍ�
	int m_NextMotion;	//���݂̃��[�V�����ԍ�
	int m_KeySetNum;	//�L�[�Z�b�g��
	int m_MotionNum;	//���[�V�����ő吔
	int m_NowFrame;		//���݂̃t���[��
	float m_SecZrot;
	struct Key
	{
		//�ʒu
		D3DXVECTOR3 pos;
		//����
		D3DXVECTOR3 rot;
	};
	struct KeySet
	{

		int nFrame;
		Key aKey[B_MAX_PARTS];
	};
	struct Motion
	{
		int bLoop;
		int nKeyNum;
		KeySet aKetSet[B_MAX_KEYSET];
	};
	Motion m_aMotion[B_MAX_MOTION];

	void MotionInit();
	void MotionDataLoad();
	void SetNextMotion(int nNextMotionNum);
	void SetNextKey();
	bool MotionBlending();

	bool m_bBlend;
	bool m_bMotion;

	enum
	{
		MOTION_SHIP_NUTO = 0,
		MOTION_TRANSFORM,
		MOTION_ROBO_NUTO,
		MOTION_ROBO_BURST,
		MOTION_ROBO_FUNNEL,
		MOTION_ROBO_SHOOT,
		MOTION_ROBO_DIE
	};

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