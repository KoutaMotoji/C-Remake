//===============================================================================
//
//  C++�g����2D(watermelon.cpp)
//								����F���n�O��
// 
//===============================================================================
#include "particle3D.h"
#include "manager.h"

//==========================================================================================
//�R���X�g���N�^
//==========================================================================================
CParticle3D::CParticle3D():m_bSizeDown(true)
{
	int nIdx = CManager::GetInstance()->GetTexture()->Regist("data\\TEXTURE\\shadow000.jpg");
	BindTexture(CManager::GetInstance()->GetTexture()->GetAddress(nIdx));

}

//==========================================================================================
//�f�X�g���N�^
//==========================================================================================
CParticle3D::~CParticle3D()
{

}

//==========================================================================================
//����������
//==========================================================================================
void CParticle3D::Init()
{
	CObject::SetType(TYPE_BILLBOARD);
	CBillboard::Init();
}

//==========================================================================================
//�I������
//==========================================================================================
void CParticle3D::Uninit()
{
	CBillboard::Uninit();
}

//==========================================================================================
//�X�V����
//==========================================================================================
void CParticle3D::Update()
{
	if (m_bSizeDown)
	{
		CBillboard::AddScale(-m_MinutSize);
	}

	if (m_nLifeTime > 0)
	{
		m_nLifeTime--;
	}
	else
	{
		CObject::Release();
		return;
	}
	CBillboard::Update();
}

//==========================================================================================
//�`�揈��
//==========================================================================================
void CParticle3D::Draw()
{
	LPDIRECT3DDEVICE9 pDevice = CManager::GetInstance()->GetRenderer()->GetDevice();;

	//���Z�����̐ݒ�
	pDevice->SetRenderState(D3DRS_BLENDOP, D3DBLENDOP_ADD);
	pDevice->SetRenderState(D3DRS_SRCBLEND, D3DBLEND_SRCALPHA);
	pDevice->SetRenderState(D3DRS_DESTBLEND, D3DBLEND_ONE);
	//�A���t�@�e�X�g�ݒ�
	pDevice->SetRenderState(D3DRS_ALPHATESTENABLE, TRUE);
	pDevice->SetRenderState(D3DRS_ALPHAREF, 0);
	pDevice->SetRenderState(D3DRS_ALPHAFUNC, D3DCMP_GREATER);

	//Z�A���t�@
	//pDevice->SetRenderState(D3DRS_ZFUNC, D3DCMP_ALWAYS);
	pDevice->SetRenderState(D3DRS_ZWRITEENABLE, FALSE);

	CBillboard::Draw();

	//�ʏ�̍����ɖ߂��ݒ�
	pDevice->SetRenderState(D3DRS_BLENDOP, D3DBLENDOP_ADD);
	pDevice->SetRenderState(D3DRS_SRCBLEND, D3DBLEND_SRCALPHA);
	pDevice->SetRenderState(D3DRS_DESTBLEND, D3DBLEND_INVSRCALPHA);

	//Z�A���t�@
	pDevice->SetRenderState(D3DRS_ZFUNC, D3DCMP_LESSEQUAL);
	pDevice->SetRenderState(D3DRS_ZWRITEENABLE, TRUE);
	pDevice->SetRenderState(D3DRS_ALPHATESTENABLE, FALSE);
}

//==========================================================================================
//��������
//==========================================================================================
CParticle3D* CParticle3D::Create(D3DXVECTOR3 pos, D3DXCOLOR col, float Radius,int LifeTime,bool bSizeDown)
{
	CParticle3D* particle = new CParticle3D;

	particle->SetPolygonParam(pos, Radius, Radius,col);
	particle->Init();
	particle->m_nLifeTime = LifeTime;
	float f = (1.0f / LifeTime);
	particle->m_MinutSize = f;
	particle->m_bSizeDown = bSizeDown;
	return particle;
}