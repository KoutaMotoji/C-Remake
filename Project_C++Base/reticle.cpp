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

	////Z�A���t�@
	//pDevice->SetRenderState(D3DRS_ZFUNC, D3DCMP_ALWAYS);
	//pDevice->SetRenderState(D3DRS_ZWRITEENABLE, FALSE);

	CBillboard::Draw();

	////Z�A���t�@
	//pDevice->SetRenderState(D3DRS_ZFUNC, D3DCMP_LESSEQUAL);
	//pDevice->SetRenderState(D3DRS_ZWRITEENABLE, TRUE);
	//pDevice->SetRenderState(D3DRS_ALPHATESTENABLE, FALSE);
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