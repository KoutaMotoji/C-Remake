//===============================================================================
//
//  C++�g����2D(watermelon.cpp)
//								����F���n�O��
// 
//===============================================================================
#include "bullet3D.h"
#include "particle3D.h"

#include "manager.h"


//==========================================================================================
//�R���X�g���N�^
//==========================================================================================
CBullet3D::CBullet3D() :m_nLife(1), Poly_Size(0.0f),m_EffectSize(0.0f)
{
	int nIdx = CManager::GetInstance()->GetTexture()->Regist("data\\TEXTURE\\shadow000.jpg");
	BindTexture(CManager::GetInstance()->GetTexture()->GetAddress(nIdx));

}

//==========================================================================================
//�f�X�g���N�^
//==========================================================================================
CBullet3D::~CBullet3D()
{

}

//==========================================================================================
//����������
//==========================================================================================
void CBullet3D::Init()
{
	CObject::SetType(TYPE_BILLBOARD);
	CBillboard::Init();
}

//==========================================================================================
//�I������
//==========================================================================================
void CBullet3D::Uninit()
{
	CBillboard::Uninit();
}

//==========================================================================================
//�X�V����
//==========================================================================================
void CBullet3D::Update()
{
	if (m_nLife > 0)
	{
		CBillboard::AddPos(m_move);
		CParticle3D::Create(CBillboard::GetPos(), m_col, Poly_Size, m_EffectSize);
		m_nLife--;
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
void CBullet3D::Draw()
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


	CBillboard::Draw();

	//�ʏ�̍����ɖ߂��ݒ�
	pDevice->SetRenderState(D3DRS_BLENDOP, D3DBLENDOP_ADD);
	pDevice->SetRenderState(D3DRS_SRCBLEND, D3DBLEND_SRCALPHA);
	pDevice->SetRenderState(D3DRS_DESTBLEND, D3DBLEND_INVSRCALPHA);
}

//==========================================================================================
//��������
//==========================================================================================
CBullet3D* CBullet3D::Create(D3DXVECTOR3 pos, D3DXVECTOR3 move, D3DXCOLOR col,int nLife,float Radius,float EffectSize)
{
	CBullet3D* bullet = new CBullet3D;

	bullet->SetPolygonParam(pos, Radius, Radius,col);
	bullet->Init();
	bullet->m_move = move * 10;
	bullet->m_col = col;
	bullet->m_nLife = nLife;
	bullet->Poly_Size = Radius;
	bullet->m_EffectSize = EffectSize;
	return bullet;
}