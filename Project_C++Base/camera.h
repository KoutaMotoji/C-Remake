//===============================================================================
//
//  3Dゲーム基礎(Block.h)
//								制作：元地弘汰
// 
//===============================================================================
#ifndef _CAMERA_H_
#define _CAMERA_H_

#include "main.h"

//カメラクラス
class CCamera
{
public:
	CCamera();
	~CCamera();
	HRESULT Init();
	void Uninit();
	void Update();
	void SetCamera();
	void SetCameraDistance(float distance) { m_camDistance = distance; };
	float GetCameraDistance() { return m_camDistance; };
	D3DXVECTOR3& GetPlayerPos();
	void SetPlayerPos(D3DXVECTOR3 pos);
	float GetRotZ();
	void SetShake(int nFlame, float fShake);
private:
	D3DXVECTOR3 m_posV, m_posR, m_posU,m_rot,m_PlayerPos;
	D3DXMATRIX m_mtxProjection, m_mtxView;
	float m_fRotZ;
	float m_camDistance;
	int m_nShakeFlame;
	float m_fShalePower;
};

#endif 
