//===============================================================================
//
//  C++使った3D(game.cpp)
//								制作：元地弘汰
// 
//===============================================================================

#include "manager.h"
#include "fade.h"
#include "object.h"
#include "sky_bg.h"

#include "mesh_Boss_Terra.h"
#include "tu_sky.h"

#include "fog.h"
#include "tutorial.h"
#include "map_edit.h"
#include "player_observer.h"
#include "mesh_ground.h"

#include "playerX.h"


//==========================================================================================
//コンストラクタ
//==========================================================================================
CTutorial::CTutorial()
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
	CScene::Update();
}

//==========================================================================================
//描画処理
//==========================================================================================
void CTutorial::Draw()
{
	CScene::Draw();
}