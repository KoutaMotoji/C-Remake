//===============================================================================
//
//  3D�Q�[����b(camera.h)
//								����F���n�O��
// 
//===============================================================================
#include "camera.h"
#include "manager.h"
#include "playerX.h"

CCamera::CCamera():m_nShakeFlame(0),m_fShalePower(0.0f)
{

}

CCamera::~CCamera()
{

}

//������
HRESULT CCamera::Init(void)
{
	m_posV = D3DXVECTOR3(0.0f, 100.0f, -500.0f);
	m_posR = D3DXVECTOR3(0.0f,0.0f,0.0f);
	m_posU = D3DXVECTOR3(0.0f,1.0f,0.0f);
	m_rot = D3DXVECTOR3(0.0f, 0.0f, 0.0f);
	m_PlayerPos = { 0.0f,0.0f,0.0f };
	m_camDistance = 700.0f;
	m_fRotZ = 0.2f;
	return S_OK;
}

//�I��
void CCamera::Uninit(void)
{

}

//�X�V
void CCamera::Update(void)
{
#if _DEBUG


	if (CManager::GetInstance()->GetJoypad()->GetJoyStickR(CJoypad::JOYSTICK_DLEFT) == true)
	{
		m_fRotZ += 0.05f;
		if (m_fRotZ > D3DX_PI)
		{
			m_fRotZ = -D3DX_PI;
		}
	}

	if (CManager::GetInstance()->GetJoypad()->GetJoyStickR(CJoypad::JOYSTICK_DRIGHT) == true)
	{
		m_fRotZ -= 0.05f;
		if (m_fRotZ < -1 * D3DX_PI)
		{
			m_fRotZ = D3DX_PI;
		}
	}
#endif // _DEBUG

	float m_Dis = ( m_camDistance);
	m_posV.x = sinf(D3DX_PI + m_fRotZ) * sqrtf(m_Dis * m_Dis + (m_Dis * 0.1f) * (m_Dis * 0.1f)) / 2.0f + m_PlayerPos.x;
	m_posV.z = cosf(D3DX_PI + m_fRotZ) * sqrtf(m_Dis * m_Dis + (m_Dis * 0.1f) * (m_Dis * 0.1f)) / 2.0f + m_PlayerPos.z;
	m_posV.y = m_PlayerPos.y + 50.0f;

	m_posR.x = m_PlayerPos.x;
	m_posR.z = m_PlayerPos.z;
	m_posR.y = m_PlayerPos.y + 50.0f;
	if (CManager::GetInstance()->GetKeyboard()->GetTrigger(DIK_6) == true)
	{
		SetShake(60, 30);
	}
}

//�ݒ�
void CCamera::SetCamera(void)
{
	D3DXVECTOR3 adjust = { 0.0f,0.0f,0.0f };
	if (m_nShakeFlame > 0)
	{
		m_nShakeFlame--;
		float randShake = (rand() % ((200) + (int)m_fShalePower * 100)) / 10;
		adjust.x = randShake;
		adjust.z = randShake;
	}
	LPDIRECT3DDEVICE9 pDevice;
	//�f�o�C�X�̎擾
	pDevice = CManager::GetInstance()->GetRenderer()->GetDevice();
	//�v���W�F�N�V�����}�g���b�N�X��������
	D3DXMatrixIdentity(&m_mtxProjection);
	//�v���W�F�N�V�����}�g���b�N�X���쐬
	D3DXMatrixPerspectiveFovLH(&m_mtxProjection,
								D3DXToRadian(45.0f),
								(float)SCREEN_WIDTH/(float)SCREEN_HEIGHT,
								10.0f,
								20000.0f);
	//�v���W�F�N�V�����}�g���b�N�X�̐ݒ�
	pDevice->SetTransform(D3DTS_PROJECTION,
		&m_mtxProjection);

	//�r���[�}�g���b�N�X�̏�����
	D3DXMatrixLookAtLH(&m_mtxView,
						&m_posV,
						&m_posR,
						&m_posU);
	//�r���[�}�g���b�N�X�̐ݒ�
	pDevice->SetTransform(D3DTS_VIEW,
							&m_mtxView);
	
}

D3DXVECTOR3& CCamera::GetPlayerPos()
{
	return m_PlayerPos;
}

void CCamera::SetPlayerPos(D3DXVECTOR3 pos)
{
	m_PlayerPos = pos;
}

float CCamera::GetRotZ()
{
	return m_fRotZ;
}

void CCamera::SetShake(int nFlame, float fShake)
{
	m_nShakeFlame = nFlame;
	m_fShalePower = fShake;
}