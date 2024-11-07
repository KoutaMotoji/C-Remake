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
	void AddCameraDistance(float dis) { m_camDistance = dis; };

	float GetCameraDistance() { return m_camDistance; };
	D3DXVECTOR3& GetPlayerPos();
	void SetPlayerPos(D3DXVECTOR3 pos);
	float GetRotZ();
	void SetRotz(float rot) { m_fRotZ = rot; };
	void AddRotz(float rot) { m_fRotZ += rot; };

	void SetShake(int nFlame, float fShake);
	void SetCamDefault() {
		m_posV = D3DXVECTOR3(0.0f, 100.0f, -300.0f);
		m_posR = D3DXVECTOR3(0.0f, 0.0f, 0.0f);
		m_posU = D3DXVECTOR3(0.0f, 1.0f, 0.0f);
		m_rot = D3DXVECTOR3(0.0f, 0.0f, 0.0f);
		m_PlayerPos = { 0.0f,0.0f,0.0f };
		m_camDistance = 600.0f;
		m_fRotZ = 0.0f;
	};

private:
	D3DXVECTOR3 m_posV, m_posR, m_posU,m_rot,m_PlayerPos;
	D3DXMATRIX m_mtxProjection, m_mtxView;
	float m_fRotZ;
	float m_camDistance;
	int m_nShakeFlame;
	float m_fShalePower;
};

#endif 
