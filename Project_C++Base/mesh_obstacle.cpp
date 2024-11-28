//===============================================================================
//
//  C++使った2D(enemy_basic.cpp)
//								制作：元地弘汰
// 
//===============================================================================
#include "mesh_obstacle.h"
#include "player_observer.h"
#include "manager.h"
#include "game.h"


namespace {
	const char* modelName[MAX_MODELTYPE]{
		"data\\MODEL\\gate000.x",
		"data\\MODEL\\statue000.x",
		"data\\MODEL\\Building000.x",
		"data\\MODEL\\Building001.x",	
		"data\\MODEL\\tower.x",
		"data\\MODEL\\brighe.x",
		"data\\MODEL\\pail.x"

	};
};

//==========================================================================================
//コンストラクタ
//==========================================================================================
CMeshObstacle::CMeshObstacle()
{

}

//==========================================================================================
//デストラクタ
//==========================================================================================
CMeshObstacle::~CMeshObstacle()
{

}

//==========================================================================================
//初期化処理
//==========================================================================================
void CMeshObstacle::Init()
{
	CObject::SetType(TYPE_3D_OBSTACLE);
	CObjectX::Init();
}

//==========================================================================================
//終了処理
//==========================================================================================
void CMeshObstacle::Uninit()
{
	CObjectX::Uninit();
}

//==========================================================================================
//更新処理
//==========================================================================================
void CMeshObstacle::Update()
{
	
	CObjectX::Update();
}

//==========================================================================================
//描画処理
//==========================================================================================
void CMeshObstacle::Draw()
{
	if (CPlayerObserver::GetPlayerPos().z < CObjectX::GetPos().z + 10000)
	{
		CObjectX::Draw();
	}
}

//==========================================================================================
//生成処理
//==========================================================================================
CMeshObstacle* CMeshObstacle::Create(D3DXVECTOR3 pos,int Type)
{
	CMeshObstacle* enemy = new CMeshObstacle;

	enemy->BindModel(modelName[Type]);

	enemy->SetModelParam(pos);
	enemy->Init();

	return enemy;
}

//==========================================================================================
//生成処理(配置ツール用オーバーロード)
//==========================================================================================
CMeshObstacle* CMeshObstacle::Create(D3DXVECTOR3 pos, D3DXVECTOR3 rot, D3DXVECTOR3 scale, int Type)
{
	CMeshObstacle* enemy = new CMeshObstacle;

	enemy->BindModel(modelName[Type]);

	enemy->SetModelParam(pos);
	enemy->SetRot(rot);
	enemy->SetSize(scale);
	enemy->Init();

	return enemy;
}