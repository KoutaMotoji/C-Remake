//===============================================================================
//
//  C++使った3D(tutorial.cpp)
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

namespace TutorialSceneInfo
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

};

//==========================================================================================
//コンストラクタ
//==========================================================================================
CTutorial::CTutorial():m_nSetTimer(0)
{
}

//==========================================================================================
//デストラクタ
//==========================================================================================
CTutorial::~CTutorial()
{

}

//==========================================================================================
//初期化処理
//==========================================================================================
HRESULT CTutorial::Init()
{
	CScene::Init();

	CPlayerX::Create({ 0.0f,0.0f,0.0f });
	CPlayerObserver::GetInstance()->PlayerSearch();

	CTutorialSky::Create({ 0.0f,1000.0f,0.0f });
	CMeshGround::Create({ 0.0f,-1000.0f,0.0f },1);
	CMeshGround::Create({ 0.0f,-1000.0f,5940 * 2 },1);
	CMeshGround::Create({ 0.0f,-1000.0f,5940 * 4 },1);

	CEnemyBase::Create({ TutorialSceneInfo::EnemyPosBeside[0].x,TutorialSceneInfo::EnemyPosBeside[0].y, CPlayerObserver::GetInstance()->GetPlayerPos().z + TutorialSceneInfo::TargetToPlauerDistance },1);
	CEnemyBase::Create({ TutorialSceneInfo::EnemyPosBeside[1].x,TutorialSceneInfo::EnemyPosBeside[1].y, CPlayerObserver::GetInstance()->GetPlayerPos().z + TutorialSceneInfo::TargetToPlauerDistance },1);


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
	if (m_nSetTimer == TutorialSceneInfo::TIME_TARGETOBJ)
	{
		CEnemyBase::Create({ TutorialSceneInfo::EnemyPosBeside[1].x,TutorialSceneInfo::EnemyPosBeside[1].y, CPlayerObserver::GetInstance()->GetPlayerPos().z + TutorialSceneInfo::TargetToPlauerDistance },1);
		m_nSetTimer = 0;
	}
	else if(m_nSetTimer == TutorialSceneInfo::HALFTIME_TARGETOBJ)
	{
		CEnemyBase::Create({ TutorialSceneInfo::EnemyPosBeside[0].x,TutorialSceneInfo::EnemyPosBeside[0].y, CPlayerObserver::GetInstance()->GetPlayerPos().z + TutorialSceneInfo::TargetToPlauerDistance },1);
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