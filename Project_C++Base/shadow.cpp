//===============================================================================
//
//  C++�g����2D(shadow.cpp)
//								����F���n�O��
// 
//===============================================================================
#include "shadow.h"
#include "manager.h"

//==========================================================================================
//������
//==========================================================================================
void CShadow::Init()
{
	int nIdx = CManager::GetInstance()->GetTexture()->Regist("data\\TEXTURE\\shadow000.jpg");
	BindTexture(CManager::GetInstance()->GetTexture()->GetAddress(nIdx));
	CObject3D::Init();
}

//==========================================================================================
//������
//==========================================================================================
void CShadow::Draw()
{
	LPDIRECT3DDEVICE9 pDevice = CManager::GetInstance()->GetRenderer()->GetDevice();

	////�A���t�@�e�X�g�ݒ�
	//pDevice->SetRenderState(D3DRS_ALPHATESTENABLE, TRUE);
	//pDevice->SetRenderState(D3DRS_ALPHAREF, 0);
	//pDevice->SetRenderState(D3DRS_ALPHAFUNC, D3DCMP_GREATER);

	//���Z�����̐ݒ�
	pDevice->SetRenderState(D3DRS_BLENDOP, D3DBLENDOP_REVSUBTRACT);
	pDevice->SetRenderState(D3DRS_SRCBLEND, D3DBLEND_SRCALPHA);
	pDevice->SetRenderState(D3DRS_DESTBLEND, D3DBLEND_ONE);

	CObject3D::Draw();

	//�ʏ�̍����ɖ߂��ݒ�
	pDevice->SetRenderState(D3DRS_BLENDOP, D3DBLENDOP_ADD);
	pDevice->SetRenderState(D3DRS_SRCBLEND, D3DBLEND_SRCALPHA);
	pDevice->SetRenderState(D3DRS_DESTBLEND, D3DBLEND_INVSRCALPHA);
	pDevice->SetRenderState(D3DRS_ALPHATESTENABLE, FALSE);
}

//==========================================================================================
//��������
//==========================================================================================
CShadow* CShadow::Create(D3DXVECTOR3 pos)
{
	CShadow* shadow = new CShadow;

	shadow->SetPolygonParam(pos, DEF_RADIUS, DEF_RADIUS);
	shadow->Init();

	return shadow;
}