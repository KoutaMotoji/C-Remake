//===============================================================================
//
//  C++�g����2D(enemy_basic.cpp)
//								����F���n�O��
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
//�R���X�g���N�^
//==========================================================================================
CMeshObstacle::CMeshObstacle()
{

}

//==========================================================================================
//�f�X�g���N�^
//==========================================================================================
CMeshObstacle::~CMeshObstacle()
{

}

//==========================================================================================
//����������
//==========================================================================================
void CMeshObstacle::Init()
{
	CObject::SetType(TYPE_3D_OBSTACLE);
	CObjectX::Init();
}

//==========================================================================================
//�I������
//==========================================================================================
void CMeshObstacle::Uninit()
{
	CObjectX::Uninit();
}

//==========================================================================================
//�X�V����
//==========================================================================================
void CMeshObstacle::Update()
{
	
	CObjectX::Update();
}

//==========================================================================================
//�`�揈��
//==========================================================================================
void CMeshObstacle::Draw()
{
	if (CPlayerObserver::GetPlayerPos().z < CObjectX::GetPos().z + 10000)
	{
		CObjectX::Draw();
	}
}

//==========================================================================================
//��������
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
//��������(�z�u�c�[���p�I�[�o�[���[�h)
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