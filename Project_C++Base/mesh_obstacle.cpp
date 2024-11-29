//===============================================================================
//
//  C++�g����2D(enemy_basic.cpp)
//								����F���n�O��
// 
//===============================================================================
#include "mesh_obstacle.h"
#include "player_observer.h"
#include "mesh_Boss_Terra.h"

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
		"data\\MODEL\\pail.x",
		"data\\MODEL\\boss_spawner.x"

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
	if (PlayerDistanceCheck())
	{
		Release();
		return;
	}
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
//�`�揈��
//==========================================================================================
bool CMeshObstacle::PlayerDistanceCheck()
{
	if (CManager::GetInstance()->GetScene()->GetSceneMode() == CScene::MODE_GAME)
	{
		return (CObjectX::GetPos().z - CPlayerObserver::GetPlayerPos().z < -OBJ_DESTROY_DIS);
	}
	return false;
}

//==========================================================================================
//��������
//==========================================================================================
CMeshObstacle* CMeshObstacle::Create(D3DXVECTOR3 pos,int Type)
{
	CMeshObstacle* enemy;

	switch (Type)
	{
	case 7:
		enemy = new CBossEmitter;
		break;
	default:
		enemy = new CMeshObstacle;
		break;
	}

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
	CMeshObstacle* enemy;

	switch (Type)
	{
	case 7:
		enemy = new CBossEmitter;
		break;
	default:
		enemy = new CMeshObstacle;
		break;
	}
	enemy->BindModel(modelName[Type]);

	enemy->SetModelParam(pos);
	enemy->SetRot(rot);
	enemy->SetSize(scale);
	enemy->Init();

	return enemy;
}

//---------------------------------------------------------------------------------------------------------------------------------
//����I�u�W�F�z�u�p�ݒ�


//�������I�[�o�[���[�h
void CScoreItemEmitter::Init()
{
	if (CManager::GetInstance()->GetScene()->GetSceneMode() == CScene::MODE_GAME)
	{
		m_bSceneCheck = true;
	}
}

//�X�V�I�[�o�[���[�h
void CScoreItemEmitter::Update()
{
	CMeshObstacle::Update();
}

//�������I�[�o�[���[�h
void CBossEmitter::Init()
{
	if (CManager::GetInstance()->GetScene()->GetSceneMode() == CScene::MODE_GAME)
	{
		m_bSceneCheck = true;
	}
}

//�X�V�I�[�o�[���[�h
void CBossEmitter::Update()
{
	if (m_bSceneCheck)
	{
		if (PlayerLength())
		{
			CBossTerra::Create(CObjectX::GetPos());

			Release();
			return;
		}
	}
	CMeshObstacle::Update();
}

bool CBossEmitter::PlayerLength()
{
	return (CObjectX::GetPos().z - CPlayerObserver::GetPlayerPos().z < BOSS_EMITTE_DIS);
}

//---------------------------------------------------------------------------------------------------------------------------------