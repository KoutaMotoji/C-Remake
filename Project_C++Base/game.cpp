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
#include "mesh_cylinder.h"
#include "tree_billboard.h"
#include "boss_reticle.h"

#include "fog.h"
#include "game.h"
#include "map_edit.h"
#include "player_observer.h"
#include "mesh_ground.h"

#include "playerX.h"

#include <random>

const int CGame::BG_OBJ_CNT = 40;


//==========================================================================================
//コンストラクタ
//==========================================================================================
CGame::CGame() : m_obs(nullptr)
{

}

//==========================================================================================
//デストラクタ
//==========================================================================================
CGame::~CGame()
{

}

//==========================================================================================
//初期化処理
//==========================================================================================
HRESULT CGame::Init()
{
	CScene::Init();

	CFog::SetFogLinear(4500.0f,15000.0f);
	CPlayerX::Create({ 0.0f,0.0f,0.0f });
	CPlayerObserver::GetInstance()->PlayerSearch();

	CMeshCylinder::Create({ 0.0f,1000.0f,0.0f });
	CMeshGround::Create({ 0.0f,-1000.0f,0.0f });
	CMeshGround::Create({ 0.0f,-1000.0f,5940*2 });
	CMeshGround::Create({ 0.0f,-1000.0f,5940 * 4 });

	CMapEdit::SetLoadMap();
	MakeRandTree();

	CManager::GetInstance()->GetCamera()->SetCameraHeigjt(50.0f);
	CManager::GetInstance()->GetCamera()->DefuseFreeCam();

	LoadMapData();
	SetBGObject();
	return S_OK;
}


//==========================================================================================
//終了処理
//==========================================================================================
void CGame::Uninit()
{
	CFog::FinishFog();
	CPlayerObserver::GetInstance()->PlayerObsDestroy();

	CScene::Uninit();
}

//==========================================================================================
//更新処理
//==========================================================================================
void CGame::Update()
{
#if _DEBUG

	if (CManager::GetInstance()->GetKeyboard()->CKeyboard::GetTrigger(DIK_RETURN))
	{
		CManager::GetInstance()->GetFade()->SetFade(CFade::FADE_IN, CScene::MODE_RESULT);
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
void CGame::Draw()
{
	CScene::Draw();
}

//==========================================================================================
//マップデータを読み込んで配置処理
//==========================================================================================
void CGame::LoadMapData()
{
	/*
	CMapEdit::SetInfo ObjInfo[MAX_EDITOBJ];
	int nGetMaxObj;
	FILE* pFile;
	pFile = fopen("data\\TEXT\\Data001.txt", "r");
	if (pFile != nullptr)
	{
		int nGetCnt = 0;
		fscanf(pFile, "%d\n", &nGetCnt);
		nGetMaxObj = nGetCnt;
		D3DXVECTOR3 GetPos;
		int nGetType;
		for (int i = 0; i < nGetCnt; i++)
		{
			fscanf(pFile, "%d\n", &nGetType);
			fscanf(pFile, "%f,", &GetPos.x);
			fscanf(pFile, "%f,", &GetPos.y);
			fscanf(pFile, "%f\n", &GetPos.z);

			ObjInfo[i].pos = GetPos;
			ObjInfo[i].SelType = nGetType;
		}
		fclose(pFile);
	}
	else
	{
		assert(pFile ==nullptr);
	}
	for (int j = 0; j < nGetMaxObj; j++)
	{
		switch (ObjInfo[j].SelType)
		{
		case CMapEdit::Sel_3DBlock:
			CBlockX::Create(ObjInfo[j].pos,0);
			break;
		case CMapEdit::Sel_3DBlock2:
			CBlockX::Create(ObjInfo[j].pos, 1);
			break;
		case CMapEdit::Sel_3DEnemy:
			CEnemyBasic::Create(ObjInfo[j].pos, 100);
			break;
		case CMapEdit::Sel_3DEnemy2:
			CEnemyThrow::Create(ObjInfo[j].pos, 20);
			break;
		case CMapEdit::Sel_Start:
			CStart::Create(ObjInfo[j].pos);
			break;
		case CMapEdit::Sel_Goal:
			CGoal::Create(ObjInfo[j].pos);
			break;
		case CMapEdit::Sel_Ground:
			CBlockX::Create(ObjInfo[j].pos, 2);
			break;
		case CMapEdit::Sel_3DEnemy3:
			CEnemyFly::Create(ObjInfo[j].pos, 20);
			break;
		}
	}*/
}

//==========================================================================================
//背景にオブジェクトを置いちゃう処理
//==========================================================================================
void CGame::SetBGObject()
{
	////乱数生成
	//std::random_device rnd;				// 非決定的な乱数生成器でシード生成機を生成
	//std::mt19937 mt(rnd());				//  メルセンヌツイスターの32ビット版、引数は初期シード
	//std::uniform_int_distribution<> rand_x(-1600, 4000);     // [-1200, 1200] 範囲の一様乱数
	//std::uniform_int_distribution<> rand_z(300, 2000);		 // [400, 1200] 範囲の一様乱数
	//std::uniform_int_distribution<> type(0, 3);				 // [0, 3] 範囲の一様乱数

	//for (int i = 0; i < BG_OBJ_CNT; i++)
	//{
	//	CStageBg::Create({ (float)(rand_x(mt)),-300,(float)(rand_z(mt)) },type(mt));
	//}
}

//==========================================================================================
//景色用の木をランダムで設置する処理
//==========================================================================================
void CGame::MakeRandTree()
{
	//乱数生成
	std::random_device rnd;				// 非決定的な乱数生成器でシード生成機を生成
	std::mt19937 mt(rnd());				//  メルセンヌツイスターの32ビット版、引数は初期シード
	std::uniform_int_distribution<> rand_x(1500, 5000);     // [1500, 5000] 範囲の一様乱数
	std::uniform_int_distribution<> rand_z(-200, 10000);		 // [-200, 10000] 範囲の一様乱数

	std::uniform_int_distribution<> type(0, 2);				 // [0, 2] 範囲の一様乱数
	for (int i = 0; i < MAX_TREESET_NUM * 0.5; ++i)
	{
		CTreeBillboard::Create({ (float)rand_x(mt),0.0f,(float)rand_z(mt) }, type(mt));
	}
	for (int i = 0; i < MAX_TREESET_NUM * 0.5; ++i)
	{

		CTreeBillboard::Create({ (float)rand_x(mt) * -1,0.0f,(float)rand_z(mt) }, type(mt));
	}
}