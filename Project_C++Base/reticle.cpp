//===============================================================================
//
//  C++�g����2D(watermelon.cpp)
//								����F���n�O��
// 
//===============================================================================
#include "reticle.h"
#include "manager.h"

const float CReticle::Poly_Size = 25.0f;

//==========================================================================================
//�R���X�g���N�^
//==========================================================================================
CReticle::CReticle()
{
	int nIdx = CManager::GetInstance()->GetTexture()->Regist("data\\TEXTURE\\reticle000.png");
	BindTexture(CManager::GetInstance()->GetTexture()->GetAddress(nIdx));

}

//==========================================================================================
//�f�X�g���N�^
//==========================================================================================
CReticle::~CReticle()
{

}

//==========================================================================================
//����������
//==========================================================================================
void CReticle::Init()
{
	CObject::SetType(TYPE_BILLBOARD);
	CBillboard::Init();
}

//==========================================================================================
//�I������
//==========================================================================================
void CReticle::Uninit()
{
	CBillboard::Uninit();
}

//==========================================================================================
//�X�V����
//==========================================================================================
void CReticle::Update()
{
	CBillboard::Update();
}

//==========================================================================================
//�`�揈��
//==========================================================================================
void CReticle::Draw()
{
	LPDIRECT3DDEVICE9 pDevice = CManager::GetInstance()->GetRenderer()->GetDevice();;

	//���Z�����̐ݒ�
	pDevice->SetRenderState(D3DRS_BLENDOP, D3DBLENDOP_ADD);
	pDevice->SetRenderState(D3DRS_SRCBLEND, D3DBLEND_INVDESTCOLOR);
	pDevice->SetRenderState(D3DRS_DESTBLEND, D3DBLEND_INVSRCCOLOR);
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
CReticle* CReticle::Create(D3DXVECTOR3 pos)
{
	CReticle* reticle = new CReticle;

	reticle->SetPolygonParam(pos, Poly_Size, Poly_Size);
	reticle->Init();
	return reticle;
}