//===============================================================================
//
//  C++�g����2D(enemy_basic.cpp)
//								����F���n�O��
// 
//===============================================================================
#include "mesh_obstacle.h"
#include "playerX.h"


#include "manager.h"
#include "game.h"

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
	D3DXVECTOR3 pos = CObjectX::GetPos();
	CObjectX::Update();
}

//==========================================================================================
//�`�揈��
//==========================================================================================
void CMeshObstacle::Draw()
{
	CObjectX::Draw();
}

//==========================================================================================
//��������
//==========================================================================================
CMeshObstacle* CMeshObstacle::Create(D3DXVECTOR3 pos,int Type)
{
	CMeshObstacle* enemy = new CMeshObstacle;
	switch (Type)
	{
	case 0:
		enemy->BindModel("data\\MODEL\\gate000.x");
		break;
	case 1:
		enemy->BindModel("data\\MODEL\\statue000.x");
		break;
	case 2:
		enemy->BindModel("data\\MODEL\\Building000.x");
		break;
	case 3:
		enemy->BindModel("data\\MODEL\\Building001.x");
		break;
	default:
		break;
	}


	enemy->SetModelParam(pos);
	enemy->Init();

	return enemy;
}
