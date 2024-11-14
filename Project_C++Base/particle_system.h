//===============================================================================
//
//  C++使った3D(particle_system.h)
//								制作：元地弘汰
// 
//===============================================================================

#ifndef _PARTICLE_SYSTEM_H_
#define _PARTICLE_SYSTEM_H_

#include "main.h"
#include "object.h"

using namespace std;

/// <summary>
/// パーティクルシステムのクラス
/// </summary>
class CParticleSystem : public CObject
{
public:
	~CParticleSystem() {};
	void Init()override {};		//初期化
	void Uninit()override {};		//終了
	void Update()override {};		//更新
	void Draw()override {};		//描画
private:
	D3DXVECTOR3 m_pos;	//位置
	int m_nNum;			//パーティクル数
	float m_fGap;		//中心と外側のギャップ
};


//==========================================================================================================================
/// <summary>
/// パーティクルの射出方法を管理するクラス群
/// </summary>
class CEmitte_Type
{
public:
	virtual ~CEmitte_Type() = default;
	virtual void SetEmitte() {};
};

//継続的に発射する
class CEmitte_Loop
{

};

//一瞬で爆発的に発射する
class CEmitte_Bomb
{

};
//==========================================================================================================================

//==========================================================================================================================
/// <summary>
/// パーティクルの発射形状を管理するクラス群
/// </summary>
class CEmitte_Form
{
public:
	virtual ~CEmitte_Form() = default;
	virtual void DoEmitte() = 0;
};

class CEmitte_Line : public CEmitte_Form
{
public:
	void DoEmitte()override;
};

class CEmitte_Sphere : public CEmitte_Form
{
public:
	void DoEmitte()override;
};

class CEmitte_Cone : public CEmitte_Form
{
public:
	void DoEmitte()override;
};
//==========================================================================================================================




#endif