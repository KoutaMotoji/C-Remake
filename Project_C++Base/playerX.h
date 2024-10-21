//===============================================================================
//
//  C++�g����2D(playerX.h)
//								����F���n�O��
// 
//===============================================================================
#ifndef _PLAYERX_H_
#define _PLAYERX_H_

#include "main.h"
#include "object.h"
#include "modelparts.h"
#include "test_meshCollision.h" 
#include "manager.h"


#define MAX_MODELPARTS	(16)

#define MAX_PARTS	(16)
#define MAX_KEYSET	(16)
#define MAX_MOTION	(7)

class CPlayerX :public CObject
{
public:
	CPlayerX();					//�R���X�g���N�^
	~CPlayerX()override;		//�f�X�g���N�^
	void Init()override;		//������
	void Uninit()override;		//�I��
	void Update()override;		//�X�V
	void Draw()override;		//�`��

	bool PMove(float fCamRotZ);
	static CPlayerX* Create(D3DXVECTOR3 pos);
	int GetPLife() { return m_nLife; };
	int GetPStamina() { return m_nStamina; };
	void StaminaAdd(int value);				//�X�^�~�i��

	D3DXVECTOR3 GetPos() { return m_pos; };
private:
	D3DXVECTOR3 m_pos,m_rot,m_size;
	D3DXVECTOR3 m_move;				//����
	D3DXVECTOR3 m_OldPos;			//�ߋ��̈ʒu
	D3DXMATRIX m_mtxWorld;			//���[���h�}�g���b�N�X
	D3DXMATRIX m_mtxWeaponWorld;	//����̃��[���h�}�g���b�N�X
	D3DXVECTOR3 m_WeaponCollisionPos;		//����̊p�x�����ƂɎZ�o���铖���蔻��̑��Έʒu
	void FloorCollision();			//���Ƃ̓����蔻��

	void SetWeaponRot(D3DXVECTOR2 rot);		//����̕�����ݒ�
	void DamageAdd(int nDmg) { m_nLife -= nDmg; DeadCheck(); };	//�_���[�W���Z�A�����m�F
	void NextAttack();
	void DoDashCheck() {
		if (CManager::GetInstance()->GetJoypad()->GetJoyStickRepeat(CJoypad::JOYPAD_LEFT_THUMB, CJoypad::JOYSTICK_DLEFT) == true ||
			CManager::GetInstance()->GetJoypad()->GetJoyStickRepeat(CJoypad::JOYPAD_LEFT_THUMB, CJoypad::JOYSTICK_DRIGHT) == true)
		{
			SetNextMotion(MOTION_DASH);
		}
	};
	bool AttackTimer();
	//void GoalCheck();						//�S�[�����Ă��邩�`�F�b�N
	void DeadCheck();
	D3DXVECTOR3 WeaponMtxFunc();
	static const float MOVE_SPEED;			//�ړ��X�s�[�h�̐ݒ�
	float fGravity;							//�d��
	float m_fWeaponRadius;
	const int MAX_JUMPCNT;					//�W�����v�̍ő��
	int m_nJumpCnt;							//���݂̃W�����v�c�萔
	bool m_bOldJump;
	bool m_bDashed;							//�ːi�����ۂ�
	D3DXVECTOR2 StickVec;					//�X�e�B�b�N�̕������x�N�g��(x.y)
	int m_nLife;			//�̗�
	int m_nStamina;			//�X�^�~�i
	static const int MAX_LIFE;
	static const int MAX_STAMINA;
	bool bStop;				//�f�o�b�O�p�ړ��ʖ���
	int m_nAttackCnt;						//�U���i�v���p
	unsigned int m_nAttackFrame;	//�U�����[�V�����v���p�A�U���t���[���p
	bool m_bAttack;			//�U�������ۂ�
	bool m_bAttackDis;		//�U���ڍs�P�\����
	int m_nLastAttackNum;


	CModelParts* m_apModelParts[MAX_MODELPARTS];

	char* m_pModelFileName[MAX_MODELPARTS];
	int m_ModelParts;	//���f���p�[�c��
	int m_CurKey;		//���݂̃L�[�ԍ�
	int m_CurMotion;	//���݂̃��[�V�����ԍ�
	int m_KeySetNum;	//�L�[�Z�b�g��
	int m_MotionNum;	//���[�V�����ő吔
	int m_NowFrame;		//���݂̃t���[��
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
		Key aKey[MAX_PARTS];
	};
	struct Motion
	{
		int bLoop;
		int nKeyNum;
		KeySet aKetSet[MAX_KEYSET];
		
	};
	Motion m_aMotion[MAX_MOTION];

	void MotionInit();
	void MotionDataLoad();
	void SetNextMotion(int nNextMotionNum);
	void SetNextKey();
	enum
	{
		MOTION_DEFAULT,
		MOTION_DASH,
		MOTION_ATTACK1,
		MOTION_ATTACK2,
		MOTION_ATTACK3,
		MOTION_RUSH,
		MOTION_JUMP
	};
	LPD3DXMESH m_pMesh;

	bool TestUseMeshCollision();
};

#endif