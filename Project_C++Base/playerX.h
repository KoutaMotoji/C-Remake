//===============================================================================
//
//  C++使った2D(playerX.h)
//								制作：元地弘汰
// 
//===============================================================================
#ifndef _PLAYERX_H_
#define _PLAYERX_H_

#include "main.h"
#include "object.h"
#include "modelparts.h"
#include "test_meshCollision.h" 
#include "reticle.h"

#include "manager.h"


#define MAX_MODELPARTS	(20)

#define MAX_PARTS	(20)
#define MAX_KEYSET	(20)
#define MAX_MOTION	(7)

class CPlayerX :public CObject
{
public:
	CPlayerX();					//コンストラクタ
	~CPlayerX()override;		//デストラクタ
	void Init()override;		//初期化
	void Uninit()override;		//終了
	void Update()override;		//更新
	void Draw()override;		//描画

	bool PMove(float fCamRotZ);
	static CPlayerX* Create(D3DXVECTOR3 pos);
	int GetPLife() { return m_nLife; };
	int GetPStamina() { return m_nStamina; };
	void StaminaAdd(int value);				//スタミナ回復

	D3DXVECTOR3 GetPos() { return m_pos; };
private:
	D3DXVECTOR3 m_pos,m_rot,m_size;
	D3DXVECTOR3 m_move;				//慣性
	D3DXVECTOR3 m_OldPos;			//過去の位置
	D3DXMATRIX m_mtxWorld;			//ワールドマトリックス
	D3DXMATRIX m_mtxWeaponWorld;	//武器のワールドマトリックス
	D3DXVECTOR3 m_WeaponCollisionPos;		//武器の角度をもとに算出する当たり判定の相対位置
	void FloorCollision();			//床との当たり判定

	void SetWeaponRot(D3DXVECTOR2 rot);		//武器の方向を設定
	void DamageAdd(int nDmg) { m_nLife -= nDmg; DeadCheck(); };	//ダメージ加算、生存確認
	void DoDashCheck() {
		if (CManager::GetInstance()->GetJoypad()->GetJoyStickRepeat(CJoypad::JOYPAD_LEFT_THUMB, CJoypad::JOYSTICK_DLEFT) == true ||
			CManager::GetInstance()->GetJoypad()->GetJoyStickRepeat(CJoypad::JOYPAD_LEFT_THUMB, CJoypad::JOYSTICK_DRIGHT) == true)
		{
			SetNextMotion(MOTION_DASH);
		}
	};
	//void GoalCheck();						//ゴールしているかチェック
	void DeadCheck();
	static const float MOVE_SPEED;			//移動スピードの設定
	float fGravity;							//重力
	float m_fWeaponRadius;
	int m_nLife;			//体力
	int m_nStamina;			//スタミナ
	static const int MAX_LIFE;
	static const int MAX_STAMINA;
	bool bStop;				//デバッグ用移動量無効
	bool m_bAttack;			//攻撃中か否か


	CModelParts* m_apModelParts[MAX_MODELPARTS];

	char* m_pModelFileName[MAX_MODELPARTS];
	int m_ModelParts;	//モデルパーツ数
	int m_CurKey;		//現在のキー番号
	int m_CurMotion;	//現在のモーション番号
	int m_KeySetNum;	//キーセット数
	int m_MotionNum;	//モーション最大数
	int m_NowFrame;		//現在のフレーム
	float m_SecZrot;
	struct Key
	{
		//位置
		D3DXVECTOR3 pos;
		//向き
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
	CReticle* m_pReticle;
	void ReticleController();
	D3DXVECTOR3 CameraPosDigit();
};

#endif