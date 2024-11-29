//===============================================================================
//
//  C++使った2D(bg.cpp)
//								制作：元地弘汰
// 
//===============================================================================
#include "t_UI.h"
#include "manager.h"

//静的メンバ初期化

//==========================================================================================
//コンストラクタ
//==========================================================================================
CTitleUI::CTitleUI(int nPriority) :CObject2D(nPriority)
{

}

//==========================================================================================
//デストラクタ
//==========================================================================================
CTitleUI::~CTitleUI()
{

}

//==========================================================================================
//初期化処理
//==========================================================================================
void CTitleUI::Init()
{

}

//==========================================================================================
//終了処理
//==========================================================================================
void CTitleUI::Uninit()
{
	CObject2D::Uninit();
}

//==========================================================================================
//更新処理
//==========================================================================================
void CTitleUI::Update()
{
	if (CManager::GetInstance()->GetKeyboard()->GetTrigger(DIK_RETURN) == true ||
		CManager::GetInstance()->GetJoypad()->GetTrigger(CJoypad::JOYPAD_A) == true)
	{
		Release();
		return;
	}
	CObject2D::Update();
}

//==========================================================================================
//描画処理
//==========================================================================================
void CTitleUI::Draw()
{
	CObject2D::Draw();
}

//==========================================================================================
//生成処理
//==========================================================================================
CTitleUI* CTitleUI::Create(D3DXVECTOR3 pos,int Type, D3DXVECTOR2 PolySize)
{
	CTitleUI* background;

	switch (Type)
	{
	case 0:
		background = new CTitleLogo;
		break;
	case 1:
		background = new CTitleButton;
		break;
	default:
		background = new CTitleUI;
		break;
	}
	background->SetPolygonParam(pos, PolySize.y, PolySize.x);
	background->Init();
	return background;
}

//----------------------------------------------------------------------------------------------------------
//UI切り替え用

//初期化オーバーロード
void CTitleLogo::Init()
{
	int nIdx = CManager::GetInstance()->GetTexture()->Regist("data\\TEXTURE\\title_logo.png");
	BindTexture(CManager::GetInstance()->GetTexture()->GetAddress(nIdx), 1, 1);

	CObject::SetType(TYPE_3D_TITLEOBJ);
	CObject2D::Init();
}

//更新オーバーロード
void CTitleLogo::Update()
{
	CTitleUI::Update();
}

//初期化オーバーロード
void CTitleButton::Init()
{
	int nIdx = CManager::GetInstance()->GetTexture()->Regist("data\\TEXTURE\\title_ui.png");
	BindTexture(CManager::GetInstance()->GetTexture()->GetAddress(nIdx), 1, 1);

	CObject::SetType(TYPE_3D_TITLEOBJ);
	CObject2D::Init();
}

//更新オーバーロード
void CTitleButton::Update()
{
	AlphableUI();
	CTitleUI::Update();
}

void CTitleButton::AlphableUI()
{
	float speed = SWAP_SPEED;

	if (m_LocalCol.a <= 0.0f ||
		m_LocalCol.a >= 1.0f)
	{
		m_bColSwitch = m_bColSwitch ? false : true;
	}
	if (m_bColSwitch)
	{
		m_LocalCol.a -= speed;
	}
	else
	{
		m_LocalCol.a += speed;
	}
	CObject2D::SetColor(m_LocalCol);
}
//----------------------------------------------------------------------------------------------------------