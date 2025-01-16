//===============================================================================
//
//  C++使った3D(result.cpp)
//								制作：元地弘汰
// 
//===============================================================================

#include "manager.h"
#include "fade.h"
#include "object.h"
#include "result.h"


#include "r_player.h"
#include "r_boss.h"

#include "eff_smoke.h"
#include "sky_bg.h"
#include "mesh_cylinder.h"
#include "mesh_ground.h"

//==========================================================================================
//コンストラクタ
//==========================================================================================
CResult::CResult()
{
	
}

//==========================================================================================
//デストラクタ
//==========================================================================================
CResult::~CResult()
{

}

//==========================================================================================
//初期化処理
//==========================================================================================
HRESULT CResult::Init()
{
	CScene::Init();
	CResultBG::Create();
	m_pScore = CScore::Create({ SCREEN_WIDTH - 580.0f,SCREEN_HEIGHT - 80.0f,0.0f });
	m_pScore->LoadLastScore();

	m_pGOUI = CGameOverUI::Create({ SCREEN_WIDTH - 250.0f,SCREEN_HEIGHT - 80.0f,0.0f }, m_bSelect);
	CResultPlayer::Create({ 70.0f,530.0f,-170.0f });
	CResultBoss::Create({ -200.0f, 0.0f, 0.0f }, {0.0f,2.0f,0.0f});

	CMeshCylinder::Create({ 0.0f,1000.0f,0.0 });

	CMeshGround::Create({ 500.0f, -200.0f, 0.0f });
	CManager::GetInstance()->GetCamera()->SetFreeCam({ 0.0f,120.0f,-100 }, { -400.0f,300.0f,500.0f }, 1);

	CManager::GetInstance()->GetCamera()->SetFreeCam({ 0.0f,700.0f,-500 }, { 0.0f,500.0f,0.0f }, 160);

	CManager::GetInstance()->GetSound()->PlaySound(CSound::SOUND_LABEL_BGM_RESULT);
	return S_OK;
}

//==========================================================================================
//終了処理
//==========================================================================================
void CResult::Uninit()
{
	if (m_pScore != nullptr)
	{
		m_pScore->Uninit();
		delete m_pScore;
		m_pScore = nullptr;
	}
	CScene::Uninit();
}

//==========================================================================================
//更新処理
//==========================================================================================
void CResult::Update()
{
	if (CManager::GetInstance()->GetKeyboard()->CKeyboard::GetTrigger(DIK_RETURN) || CManager::GetInstance()->GetJoypad()->GetTrigger(CJoypad::JOYPAD_A))
	{
		if (!m_bSelect)
		{
			CManager::GetInstance()->GetFade()->SetFade(CFade::FADE_IN, CScene::MODE_GAME);
		}
		else
		{
			CManager::GetInstance()->GetFade()->SetFade(CFade::FADE_IN, CScene::MODE_TITLE);
		}
	}
	if (CManager::GetInstance()->GetKeyboard()->CKeyboard::GetTrigger(DIK_4))
	{
		CManager::GetInstance()->GetCamera()->SetFreeCam({ 0.0f,120.0f,-300 }, { 0.0f,300.0f,500.0f }, 160);
	}
	if (CManager::GetInstance()->GetJoypad()->GetJoyStickTrigger(CJoypad::JOYPAD_LEFT_THUMB, CJoypad::JOYSTICK_DRIGHT) ||
		CManager::GetInstance()->GetJoypad()->GetJoyStickTrigger(CJoypad::JOYPAD_LEFT_THUMB, CJoypad::JOYSTICK_DLEFT) ||
		CManager::GetInstance()->GetJoypad()->GetTrigger(CJoypad::JOYPAD_DPAD_LEFT) ||
		CManager::GetInstance()->GetJoypad()->GetTrigger(CJoypad::JOYPAD_DPAD_RIGHT))
	{
		m_bSelect = !m_bSelect;
		m_pGOUI->ThisDelete();
		m_pGOUI = CGameOverUI::Create({ SCREEN_WIDTH - 250.0f,SCREEN_HEIGHT - 80.0f,0.0f }, m_bSelect);
	}

	CEffSmoke::Create({ -300.0f,-180.0f,300.0f }, 3, 240);
	CEffSmoke::Create({ 200.0f,-100.0f,600.0f }, 3, 190);
	CEffSmoke::Create({ 500.0f, 0.0f,200.0f }, 3, 150);

	CScene::Update();
}

//==========================================================================================
//描画処理
//==========================================================================================
void CResult::Draw()
{
	CScene::Draw();
}


//==========================================================================================
//枠の初期化処理
//==========================================================================================
void CResultBG::Init()
{
	int nIdx = CManager::GetInstance()->GetTexture()->Regist("data\\TEXTURE\\result.png");
	BindTexture(CManager::GetInstance()->GetTexture()->GetAddress(nIdx), 1, 1);

	CObject::SetType(TYPE_2D_UI);
	CObject2D::Init();
}


//==========================================================================================
//枠の生成処理
//==========================================================================================
CResultBG* CResultBG::Create()
{
	CResultBG* bg = new CResultBG;

	bg->SetPolygonParam({SCREEN_WIDTH * 0.5f,SCREEN_HEIGHT * 0.5f,0.0f}, SCREEN_HEIGHT, SCREEN_WIDTH);
	bg->Init();

	return bg;
}
