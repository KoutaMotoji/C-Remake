//===============================================================================
//
//  �r�[���Փˎ��̔����G�t�F�N�g(eff_explosion.cpp)
//								����F���n�O��
// 
//===============================================================================
#include "eff_explosion.h"
#include "manager.h"

namespace
{
	int LOOP_TIME = 2;		//���t���[���ŃA�j���[�V������؂�ւ��邩
	D3DXVECTOR2 TEX_SLICE = { 8,2 };	//�e�N�X�`���̕�����
	int TEX_X = TEX_SLICE.x - 1;		//�e�N�X�`���̉�������-1
	int TEX_Y = TEX_SLICE.y - 1;		//�e�N�X�`���̏c������-1
	float DEF_POLYSIZE = 60.0f;			//�f�t�H���g���̃e�N�X�`���T�C�Y
};

CEffExplosion::CEffExplosion(int nPriority) :CBillboard(nPriority) , m_nTime(0)
{
	//�e�N�X�`���̓o�^�E���蓖��
	int nIdx = CManager::GetInstance()->GetTexture()->Regist("data\\TEXTURE\\bomb000.png");
	BindTexture(CManager::GetInstance()->GetTexture()->GetAddress(nIdx), TEX_SLICE);
}

CEffExplosion::~CEffExplosion()
{

}

//==========================================================================================
//����������
//==========================================================================================
void CEffExplosion::Init()
{
	CObject::SetType(TYPE_BILLBOARD);		//�I�u�W�F�N�g�����p�̃^�O�t��
	CManager::GetInstance()->GetSound()->PlaySound(CSound::SOUND_LABEL_GAMESE_BOMB);
	CBillboard::Init();
}

//==========================================================================================
//�I������
//==========================================================================================
void CEffExplosion::Uninit()
{
	CBillboard::Uninit();
}

//==========================================================================================
//�X�V����
//==========================================================================================
void CEffExplosion::Update()
{
	if (m_nTime > LOOP_TIME)
	{
		D3DXVECTOR2 Anim = CBillboard::GetAnim();

		m_nTime = 0;

		if (Anim.x >= TEX_X)
		{
			CBillboard::AddAnim({ -TEX_SLICE.x,1 });
		}
		if (Anim.y >= TEX_Y && Anim.x >= TEX_X)
		{
			Release();
			return;
		}
		if(Anim.x < TEX_SLICE.x &&
			Anim.y <= TEX_Y)
		{
			CBillboard::AddAnim({ 1,0 });
		}
		Anim = Anim;
	}
	else
	{
		m_nTime++;
	}
	CBillboard::Update();
}

//==========================================================================================
//�`�揈��
//==========================================================================================
void CEffExplosion::Draw()
{
	LPDIRECT3DDEVICE9 pDevice = CManager::GetInstance()->GetRenderer()->GetDevice();;

	//�[�x�o�b�t�@�𖳎����ĕ`�悷��
	pDevice->SetRenderState(D3DRS_ZFUNC, D3DCMP_ALWAYS);
	pDevice->SetRenderState(D3DRS_ZWRITEENABLE, FALSE);

	CBillboard::Draw();

	//�[�x�o�b�t�@�̐ݒ��߂�
	pDevice->SetRenderState(D3DRS_ZFUNC, D3DCMP_LESSEQUAL);
	pDevice->SetRenderState(D3DRS_ZWRITEENABLE, TRUE);
	pDevice->SetRenderState(D3DRS_ALPHATESTENABLE, FALSE);
}

//==========================================================================================
//��������
//==========================================================================================
CEffExplosion* CEffExplosion::Create(D3DXVECTOR3 pos)
{
	CEffExplosion* Effect = new CEffExplosion;

	Effect->SetPolygonParam(pos, DEF_POLYSIZE, DEF_POLYSIZE);
	Effect->Init();
	Effect->m_nTime = 0;
	return Effect;
}

//==========================================================================================
//��������
//==========================================================================================
CEffExplosion* CEffExplosion::Create(D3DXVECTOR3 pos,float Radius)
{
	CEffExplosion* Effect = new CEffExplosion;

	Effect->SetPolygonParam(pos, Radius, Radius);
	Effect->Init();
	Effect->m_nTime = 0;
	return Effect;
}
