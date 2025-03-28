//===============================================================================
//
//  ���U���g��ʉ��o�̉��G�t�F�N�g(eff_smoke.cpp)
//								����F���n�O��
// 
//===============================================================================
#include "eff_smoke.h"
#include "manager.h"

namespace
{
	//���������̏���E�����̐ݒ�

	int XZ_RAND_MIN = -8;
	int XZ_RAND_MAX = 8;

	int Y_RAND_MIN = 10;
	int Y_RAND_MAX = 30;

	int ROTV_RAND_MIN = 800;
	int ROTV_RAND_MAX = 1500;

	int ADDSIZE_RAND_MIN = 80;
	int ADDSIZE_RAND_MAX = 150;

	float F_CLAC_NUM = 0.15f;

};


CEffSmoke::CEffSmoke(int nPriority) :CBillboard(nPriority), m_nTime(0)
{
	//�e�N�X�`���̓o�^�E���蓖��
	int nIdx = CManager::GetInstance()->GetTexture()->Regist("data\\TEXTURE\\smoke.png");
	BindTexture(CManager::GetInstance()->GetTexture()->GetAddress(nIdx), { 1,1 });
}

CEffSmoke::~CEffSmoke()
{

}

//==========================================================================================
//����������
//==========================================================================================
void CEffSmoke::Init()
{
	CObject::SetType(TYPE_BILLBOARD);
	m_moveValue = SetRandValue();
	CBillboard::Init();
}

//==========================================================================================
//�I������
//==========================================================================================
void CEffSmoke::Uninit()
{
	CBillboard::Uninit();
}

//==========================================================================================
//�X�V����
//==========================================================================================
void CEffSmoke::Update()
{
	--m_nLife;
	if (m_nLife < 0)	//�c�����Ԃ�0�ȉ��̎�
	{
		//�I�u�W�F�N�g�����
		CObject::Release();
		return;
	}

	//���o�p����
	CBillboard::AddPos(m_moveValue);				
	CBillboard::AddRot({ 0.0f,0.0f,m_fRotValue });
	CBillboard::AddScale(0.05f);

	CBillboard::Update();
}

//==========================================================================================
//�`�揈��
//==========================================================================================
void CEffSmoke::Draw()
{
	LPDIRECT3DDEVICE9 pDevice = CManager::GetInstance()->GetRenderer()->GetDevice();;

	// �@���̎������K����L����
	pDevice->SetRenderState(D3DRS_NORMALIZENORMALS, TRUE);
	pDevice->SetRenderState(D3DRS_CULLMODE, D3DCULL_NONE);	//�J�����O�𗼖ʂ�

	//�A���t�@�e�X�g�ݒ�
	pDevice->SetRenderState(D3DRS_ALPHATESTENABLE, TRUE);
	pDevice->SetRenderState(D3DRS_ALPHAREF, 0);
	pDevice->SetRenderState(D3DRS_ALPHAFUNC, D3DCMP_GREATER);

	CBillboard::Draw();

	//�ʏ�̍����ɖ߂��ݒ�
	pDevice->SetRenderState(D3DRS_BLENDOP, D3DBLENDOP_ADD);
	pDevice->SetRenderState(D3DRS_SRCBLEND, D3DBLEND_SRCALPHA);
	pDevice->SetRenderState(D3DRS_DESTBLEND, D3DBLEND_INVSRCALPHA);
	// �@���̎������K���𖳌���
	pDevice->SetRenderState(D3DRS_NORMALIZENORMALS, FALSE);
	pDevice->SetRenderState(D3DRS_CULLMODE, D3DCULL_CCW);	//�J�����O�����ǂ�

}

//==========================================================================================
//��������
//==========================================================================================
CEffSmoke* CEffSmoke::Create(D3DXVECTOR3 pos, float Radius,int nLife)
{
	CEffSmoke* Effect = new CEffSmoke;

	Effect->SetPolygonParam(pos, Radius, Radius);
	Effect->Init();
	Effect->m_nLife = nLife;
	Effect->m_nTime = 0;
	return Effect;
}

//==========================================================================================
//��������
//==========================================================================================
D3DXVECTOR3 CEffSmoke::SetRandValue()
{
	D3DXVECTOR3 vec;
	CEffSmoke* Effect = new CEffSmoke;

	std::random_device rnd;			// �񌈒�I�ȗ���������ŃV�[�h�����@�𐶐�
	std::mt19937 mt(rnd());			//  �����Z���k�c�C�X�^�[��32�r�b�g�ŁA�����͏����V�[�h
	std::uniform_int_distribution<> rand_x(XZ_RAND_MIN, XZ_RAND_MAX);		// [-8, 8] �͈͂̈�l����
	std::uniform_int_distribution<> rand_y(Y_RAND_MIN, Y_RAND_MAX);		// [10, 30] �͈͂̈�l����
	std::uniform_int_distribution<> rand_z(XZ_RAND_MIN, XZ_RAND_MAX);		// [-8, 8] �͈͂̈�l����
	std::uniform_int_distribution<> rotV(ROTV_RAND_MIN, ROTV_RAND_MAX);	// [800, 1500] �͈͂̈�l����
	std::uniform_int_distribution<> addSize(ADDSIZE_RAND_MIN, ADDSIZE_RAND_MAX);	// [80, 150] �͈͂̈�l����

	vec = {
		(float)(rand_x(mt))* F_CLAC_NUM,
		(float)(rand_y(mt))* F_CLAC_NUM,
		(float)(rand_z(mt))* F_CLAC_NUM
	};

	m_fRotValue = ((float)rotV(mt) * 0.0001);
	AddScale((float)(addSize(mt) * 0.008f));
	return vec;
}