//===============================================================================
//
//  �Q�[���I�[�o�[�V�[����UI�\������(go_UI.cpp)
//								����F���n�O��
// 
//===============================================================================
#include "go_UI.h"
#include "manager.h"

namespace
{
	D3DXVECTOR2 PolySize = {
		500.0f,
		120.0f
	};
};


CGameOverUI::CGameOverUI(int nPriority) :CObject2D(nPriority)
{
	//�e�N�X�`���̓o�^
	m_TexIdx[0] = CManager::GetInstance()->GetTexture()->Regist("data\\TEXTURE\\GO_select_A.png");
	m_TexIdx[1] = CManager::GetInstance()->GetTexture()->Regist("data\\TEXTURE\\GO_select_B.png");
}

CGameOverUI::~CGameOverUI()
{

}

//==========================================================================================
//����������
//==========================================================================================
void CGameOverUI::Init()
{
	CObject2D::Init();
}

//==========================================================================================
//�I������
//==========================================================================================
void CGameOverUI::Uninit()
{
	CObject2D::Uninit();
}

//==========================================================================================
//�X�V����
//==========================================================================================
void CGameOverUI::Update()
{
	CObject2D::Update();
}

//==========================================================================================
//�`�揈��
//==========================================================================================
void CGameOverUI::Draw()
{
	CObject2D::Draw();
}

//==========================================================================================
//��������
//==========================================================================================
CGameOverUI* CGameOverUI::Create(D3DXVECTOR3 pos,bool bSwitch)
{
	CGameOverUI* background = new CGameOverUI();

	background->SetPolygonParam(pos, PolySize.y, PolySize.x);
	background->Init();
	//�^�C�v���ƂɃe�N�X�`�������蓖��
	background->BindTexture(CManager::GetInstance()->GetTexture()->GetAddress(background->m_TexIdx[(int)bSwitch]),1,1);
	return background;
}

void CGameOverUI::ThisDelete()
{
	Release();
}