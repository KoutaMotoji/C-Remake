//===============================================================================
//
//  C++�g����2D(block.cpp)
//								����F���n�O��
// 
//===============================================================================
#include "player_UI.h"

#include "player_observer.h"
#include "manager.h"

//�ÓI�����o������
const float CGaugeLife::OBJ_HEIGHT = 70.0f;
const float CGaugeLife::OBJ_WIDTH = SCREEN_WIDTH * 0.7f;

//==========================================================================================
//�R���X�g���N�^
//==========================================================================================
CGaugeLife::CGaugeLife(int nPriority) :CObject2D(nPriority)
{

}

//==========================================================================================
//�f�X�g���N�^
//==========================================================================================
CGaugeLife::~CGaugeLife()
{

}

//==========================================================================================
//����������
//==========================================================================================
void CGaugeLife::Init()
{
	int nIdx = CManager::GetInstance()->GetTexture()->Regist("data\\TEXTURE\\hp_bar.png");
	BindTexture(CManager::GetInstance()->GetTexture()->GetAddress(nIdx), 1, 1);

	CGaugeLiFrame::Create(CObject2D::GetPos(), OBJ_WIDTH, OBJ_HEIGHT);
	CGaugeLiBack::Create(CObject2D::GetPos(), OBJ_WIDTH, OBJ_HEIGHT);

	CObject::SetType(TYPE_2D_UI);
	CObject2D::Init();
}

//==========================================================================================
//�I������
//==========================================================================================
void CGaugeLife::Uninit()
{
	CObject2D::Uninit();
}

//==========================================================================================
//�X�V����
//==========================================================================================
void CGaugeLife::Update()
{
	CGaugeLife::SetGauge();
	CObject2D::Update();
}

//==========================================================================================
//�`�揈��
//==========================================================================================
void CGaugeLife::Draw()
{
	CObject2D::Draw();
}

//==========================================================================================
//��������
//==========================================================================================
CGaugeLife* CGaugeLife::Create(int nMaxGauge)
{
	CGaugeLife* gauge = new CGaugeLife;
	D3DXVECTOR3 pos = { OBJ_WIDTH * 0.5f,SCREEN_HEIGHT - (OBJ_HEIGHT * 0.5f),0.0f };
	gauge->SetPolygonParam(pos, OBJ_HEIGHT, OBJ_WIDTH, nMaxGauge, false);
	gauge->Init();
	return gauge;
}

//==========================================================================================
//���l���擾���Ĕ��f
//==========================================================================================
void CGaugeLife::SetGauge()
{
	int nNowGauge = CPlayerObserver::GetPlayerLife();
	CObject2D::SetGauge(nNowGauge);
}

//----------------------------------------------------------------------------------------------------------------------------------
//�g�E���ݒ�p

//==========================================================================================
//�g�̏���������
//==========================================================================================
void CGaugeLiFrame::Init()
{
	int nIdx = CManager::GetInstance()->GetTexture()->Regist("data\\TEXTURE\\hp_frame.png");
	BindTexture(CManager::GetInstance()->GetTexture()->GetAddress(nIdx), 1, 1);

	CObject::SetType(TYPE_2D_UI);
	CObject2D::Init();
}


//==========================================================================================
//�g�̐�������
//==========================================================================================
CGaugeLiFrame* CGaugeLiFrame::Create(D3DXVECTOR3 pos, float fWidth, float fHeight)
{
	CGaugeLiFrame* gauge = new CGaugeLiFrame;
	gauge->SetPolygonParam(pos, fHeight, fWidth);
	gauge->Init();
	return gauge;
}

//==========================================================================================
//��둤�̏���������
//==========================================================================================
void CGaugeLiBack::Init()
{
	int nIdx = CManager::GetInstance()->GetTexture()->Regist("data\\TEXTURE\\hp_back.png");
	BindTexture(CManager::GetInstance()->GetTexture()->GetAddress(nIdx), 1, 1);

	CObject::SetType(TYPE_2D_UI);
	CObject2D::Init();
}

//==========================================================================================
//��둤�̐�������
//==========================================================================================
CGaugeLiBack* CGaugeLiBack::Create(D3DXVECTOR3 pos, float fWidth, float fHeight)
{
	CGaugeLiBack* gauge = new CGaugeLiBack;
	gauge->SetPolygonParam(pos, fHeight, fWidth, { 0.2f,0.4f,0.9f,1.0f });
	gauge->Init();
	return gauge;
}