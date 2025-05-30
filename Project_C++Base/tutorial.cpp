//===============================================================================
//
//  チュートリアルシーン(tutorial.cpp)
//								制作：元地弘汰
// 
//===============================================================================

#include "manager.h"
#include "fade.h"
#include "object.h"
#include "sky_bg.h"

#include "enemy_base.h"
#include "tu_sky.h"

#include "fog.h"
#include "tutorial.h"
#include "map_edit.h"
#include "player_observer.h"
#include "mesh_ground.h"

#include "playerX.h"

namespace TutorialSceneInfo		//チュートリアルシーン用定数まとめ
{
	int TIME_TARGETOBJ = 240;
	int HALFTIME_TARGETOBJ = TIME_TARGETOBJ * 0.5f;

	float TargetToPlauerDistance = 6000.0f;
	D3DXVECTOR2 EnemyPosBeside[2] =
	{
		{
			600.0f,
			400.0f
		},
		{
			-600.0f,
			400.0f
		}
	};
	float MESH_Y_POS = 1000.0f;
	float GROUND_Z_SIZE = 5940.0f;
	float GROUND_Z_SIZE_D = 5940.0f * 2;
	float GROUND_Z_SIZE_Q = 5940.0f * 4;
	D3DXCOLOR SET_COLOR = { 1.0f,1.0f,1.0f,0.7f };
};


CTutorial::CTutorial():m_nSetTimer(0)
{
}

CTutorial::~CTutorial()
{

}

//==========================================================================================
//初期化処理
//==========================================================================================
HRESULT CTutorial::Init()
{
	using namespace TutorialSceneInfo;
	CScene::Init();

	CPlayerX::Create({ 0.0f,0.0f,0.0f });
	CPlayerObserver::GetInstance()->PlayerSearch();

	CTutorialSky::Create({ 0.0f,MESH_Y_POS,0.0f });
	CMeshGround::Create({ 0.0f,-MESH_Y_POS,0.0f },1);
	CMeshGround::Create({ 0.0f,-MESH_Y_POS,GROUND_Z_SIZE_D },1);
	CMeshGround::Create({ 0.0f,-MESH_Y_POS,GROUND_Z_SIZE_Q },1);

	CEnemyBase::Create({ EnemyPosBeside[1].x,EnemyPosBeside[1].y, CPlayerObserver::GetInstance()->GetPlayerPos().z + TargetToPlauerDistance },1);

	CTu_MoveButton::Create();

	CManager::GetInstance()->GetCamera()->SetCameraHeigjt(50.0f);
	CManager::GetInstance()->GetCamera()->DefuseFreeCam();

	CManager::GetInstance()->GetSound()->PlaySound(CSound::SOUND_LABEL_BGM_TUTORIAL);
	return S_OK;
}

//==========================================================================================
//終了処理
//==========================================================================================
void CTutorial::Uninit()
{
	CPlayerObserver::GetInstance()->PlayerObsDestroy();

	CScene::Uninit();
}

//==========================================================================================
//更新処理
//==========================================================================================
void CTutorial::Update()
{
	using namespace TutorialSceneInfo;
#if _DEBUG
	if (CManager::GetInstance()->GetKeyboard()->CKeyboard::GetTrigger(DIK_RETURN))
	{
		CManager::GetInstance()->GetFade()->SetFade(CFade::FADE_IN, CScene::MODE_TITLE);
		return;
	}
	if (CManager::GetInstance()->GetKeyboard()->CKeyboard::GetTrigger(DIK_F3))
	{
		CManager::GetInstance()->GetFade()->SetFade(CFade::FADE_IN, CScene::MODE_MAPEDIT);
		return;
	}
#endif // _DEBUG
	++m_nSetTimer;
	if (m_nSetTimer == TIME_TARGETOBJ)
	{
		CEnemyBase::Create({EnemyPosBeside[1].x,EnemyPosBeside[1].y, CPlayerObserver::GetInstance()->GetPlayerPos().z + TargetToPlauerDistance },1);
		m_nSetTimer = 0;
	}
	else if(m_nSetTimer == HALFTIME_TARGETOBJ)
	{
		CEnemyBase::Create({EnemyPosBeside[0].x,EnemyPosBeside[0].y, CPlayerObserver::GetInstance()->GetPlayerPos().z + TargetToPlauerDistance },1);
	}
	CScene::Update();
}

//==========================================================================================
//描画処理
//==========================================================================================
void CTutorial::Draw()
{
	CScene::Draw();
}

//----------------------------------------------------------------------------------------------------------

//==========================================================================================
//初期化
//==========================================================================================
void CTu_MoveButton::Init()
{
	int nIdx = CManager::GetInstance()->GetTexture()->Regist("data\\TEXTURE\\returnGauge.png");
	BindTexture(CManager::GetInstance()->GetTexture()->GetAddress(nIdx), 1, 1);

	CObject::SetType(TYPE_3D_TITLEOBJ);

	CTu_MoveButtonBack::Create(CObject2D::GetPos());
	CObject2D::Init();
	CObject2D::SetColor(TutorialSceneInfo::SET_COLOR);
}

//==========================================================================================
//更新
//==========================================================================================
void CTu_MoveButton::Update()
{
	if (CManager::GetInstance()->GetKeyboard()->GetRepeat(DIK_RETURN) == true ||
		CManager::GetInstance()->GetJoypad()->GetRepeat(CJoypad::JOYPAD_START) == true)
	{
		++m_Gauge;
	}
	if (CManager::GetInstance()->GetKeyboard()->GetRelease(DIK_RETURN) == true && m_Gauge <= PUSHING_TIME ||
		CManager::GetInstance()->GetJoypad()->GetRelease(CJoypad::JOYPAD_START) == true && m_Gauge <= PUSHING_TIME)
	{
		m_Gauge = 0;
	}

	CObject2D::SetGauge(m_Gauge);

	if (m_Gauge > PUSHING_TIME)
	{
		CManager::GetInstance()->GetFade()->SetFade(CFade::FADE_IN, CScene::MODE_TITLE);
		return;
	}
	CObject2D::Update();
}


//==========================================================================================
//生成処理
//==========================================================================================
CTu_MoveButton* CTu_MoveButton::Create()
{
	CTu_MoveButton* background = new CTu_MoveButton;
	D3DXVECTOR3 pos = { SCREEN_WIDTH * 0.5f,PushGaugeHeight * 0.5f,0.0f };
	background->SetPolygonParam(pos, PushGaugeHeight, PushGaugeWidth, PUSHING_TIME, false);
	background->Init();
	return background;
}

//==========================================================================================
//初期化
//==========================================================================================
void CTu_MoveButtonBack::Init()
{
	int nIdx = CManager::GetInstance()->GetTexture()->Regist("data\\TEXTURE\\returnGaugeBack.png");
	BindTexture(CManager::GetInstance()->GetTexture()->GetAddress(nIdx), 1, 1);

	CObject::SetType(TYPE_3D_TITLEOBJ);
	CObject2D::Init();
	CObject2D::SetColor(TutorialSceneInfo::SET_COLOR);
}

//==========================================================================================
//生成処理
//==========================================================================================
CTu_MoveButtonBack* CTu_MoveButtonBack::Create(D3DXVECTOR3 pos)
{
	CTu_MoveButtonBack* background = new CTu_MoveButtonBack;

	background->SetPolygonParam(pos, PushGaugeHeight, PushGaugeWidth);
	background->Init();
	return background;
}