//===============================================================================
//
//  C++�g����2D(watermelon.cpp)
//								����F���n�O��
// 
//===============================================================================
#include "boss_reticle.h"
#include "manager.h"

//==========================================================================================
//�R���X�g���N�^
//==========================================================================================
CBossReticle::CBossReticle()
{
	int nIdx = CManager::GetInstance()->GetTexture()->Regist("data\\TEXTURE\\reticle001.png");
	BindTexture(CManager::GetInstance()->GetTexture()->GetAddress(nIdx));

}

//==========================================================================================
//�f�X�g���N�^
//==========================================================================================
CBossReticle::~CBossReticle()
{

}

//==========================================================================================
//����������
//==========================================================================================
void CBossReticle::Init()
{
	CObject::SetType(TYPE_BILLBOARD);
	CBillboard::Init();
}

//==========================================================================================
//�I������
//==========================================================================================
void CBossReticle::Uninit()
{
	CBillboard::Uninit();
}

//==========================================================================================
//�X�V����
//==========================================================================================
void CBossReticle::Update()
{
	CBillboard::Update();
}

//==========================================================================================
//�`�揈��
//==========================================================================================
void CBossReticle::Draw()
{
	LPDIRECT3DDEVICE9 pDevice = CManager::GetInstance()->GetRenderer()->GetDevice();
	--m_nLife;
	CBillboard::AddRot({ 0.0f,0.0f,m_RotateSpeed });
	CBillboard::AddScale(-Poly_MinutSize);
	CBillboard::Draw();
}

//==========================================================================================
//��������
//==========================================================================================
CBossReticle* CBossReticle::Create(D3DXVECTOR3 pos, float Radius, int nLife, float Rotate)
{
	CBossReticle* reticle = new CBossReticle;

	reticle->SetPolygonParam(pos, Radius, Radius);
	reticle->Init();
	reticle->m_nLife = nLife;
	reticle->Poly_MinutSize = 1.0f / nLife;
	reticle->m_RotateSpeed = Rotate;
	return reticle;
}