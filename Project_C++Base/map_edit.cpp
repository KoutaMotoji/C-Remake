//===============================================================================
//
//  C++�g����3D(result.cpp)
//								����F���n�O��
// 
//===============================================================================

#include "manager.h"
#include "fade.h"
#include "object.h"
#include "map_edit.h"
#include "playerX.h"

#include "mesh_obstacle.h"

//==========================================================================================
//�R���X�g���N�^
//==========================================================================================
CMapEdit::CMapEdit():m_MaxObj(0),MOVE_SCALE(20.0f)
{
	for (int i = 0; i < MAX_EDITOBJ; i++)
	{
		ObjInfo[i].pos = { 0.0f,0.0f,0.0f };
		ObjInfo[i].SelType = Sel_MAX;
	}
	m_SelectObject = nullptr;
}

//==========================================================================================
//�f�X�g���N�^
//==========================================================================================
CMapEdit::~CMapEdit()
{

}

//==========================================================================================
//����������
//==========================================================================================
HRESULT CMapEdit::Init()
{
	CScene::Init();
	LoadFile();
	m_thisPos = { 0.0f,0.0f,0.0f };
	m_thisType = Sel_3DBlock;
	SelectObject();
	return S_OK;
}

//==========================================================================================
//�I������
//==========================================================================================
void CMapEdit::Uninit()
{
	if (m_SelectObject != nullptr)
	{
		m_SelectObject->Release();
	}
	if (m_LastObj != nullptr)
	{
		m_LastObj->Release();
	}
	CScene::Uninit();
}

//==========================================================================================
//�X�V����
//==========================================================================================
void CMapEdit::Update()
{
	D3DXVECTOR3 CameraPos;
	if (CManager::GetInstance()->GetCamera()->GetPlayerPos() != nullptr)
	{
		CameraPos = CManager::GetInstance()->GetCamera()->GetPlayerPos();
	}
	else
	{
		assert(!(CameraPos = CManager::GetInstance()->GetCamera()->GetPlayerPos()));
	}

	CameraPos = m_thisPos;
	EditObj();
	CManager::GetInstance()->GetCamera()->SetPlayerPos(CameraPos);

	CScene::Update();
}

//==========================================================================================
//�`�揈��
//==========================================================================================
void CMapEdit::Draw()
{
	CScene::Draw();
}

//==========================================================================================
//�I�u�W�F�N�g�z�u����
//==========================================================================================
void CMapEdit::EditObj()
{
	if (CManager::GetInstance()->GetKeyboard()->GetTrigger(DIK_UPARROW) == true)
	{
		m_thisPos.y += MOVE_SCALE;
	}
	if (CManager::GetInstance()->GetKeyboard()->GetTrigger(DIK_DOWNARROW) == true)
	{
		m_thisPos.y -= MOVE_SCALE;
	}
	if (CManager::GetInstance()->GetKeyboard()->GetTrigger(DIK_LEFTARROW) == true)
	{
		m_thisPos.x -= MOVE_SCALE;
	}
	if (CManager::GetInstance()->GetKeyboard()->GetTrigger(DIK_RIGHTARROW) == true)
	{
		m_thisPos.x += MOVE_SCALE;
	}
	if (CManager::GetInstance()->GetKeyboard()->GetTrigger(DIK_RETURN) == true)
	{
		SetObject();
	}
	m_SelectObject->SetPos(m_thisPos);
	SelectObjType();
	if (CManager::GetInstance()->GetKeyboard()->GetTrigger(DIK_F1) == true)
	{
		SaveFile();
	}
	if (CManager::GetInstance()->GetKeyboard()->GetTrigger(DIK_F2) == true)
	{
		LoadFile();
	}
	if (CManager::GetInstance()->GetKeyboard()->GetTrigger(DIK_F3) == true)
	{
		SaveFile();

		CManager::GetInstance()->GetFade()->SetFade(CFade::FADE_IN, CScene::MODE_GAME);
	}
}

//==========================================================================================
//�O���t�@�C���ɏ����o������
//==========================================================================================
void CMapEdit::SaveFile()
{
	FILE* pFile;
	pFile = fopen("data\\TEXT\\Data001.txt", "w");
	if (pFile != nullptr)
	{
		fprintf(pFile, "%d\n", m_MaxObj);

		for (int i = 0; i < m_MaxObj; ++i)
		{
			fprintf(pFile, "%d\n", ObjInfo[i].SelType);
			fprintf(pFile, "%.2f,", ObjInfo[i].pos.x);
			fprintf(pFile, "%.2f,", ObjInfo[i].pos.y);
			fprintf(pFile, "%.2f\n", ObjInfo[i].pos.z);
		}
		fclose(pFile);
	}
}

//==========================================================================================
//�O���t�@�C������ǂݍ��ޏ�������
//==========================================================================================
void CMapEdit::LoadFile()
{
	FILE* pFile;
	pFile = fopen("data\\TEXT\\Data001.txt", "r");
	if (pFile != nullptr)
	{
		int nGetCnt = 0;
		fscanf(pFile, "%d\n", &nGetCnt);
		m_MaxObj = nGetCnt;
		D3DXVECTOR3 GetPos;
		int nGetType;
		for (int i = 0; i < nGetCnt; ++i)
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
	for (int j = 0; j < m_MaxObj; ++j)
	{
		CMeshObstacle::Create(ObjInfo[j].pos, ObjInfo[j].SelType);
	}

}
//==========================================================================================
//�I�u�W�F�N�g�̎�ނ�I�����鏈��
//==========================================================================================
void CMapEdit::SelectObject()
{
	if (m_SelectObject != nullptr)
	{
		m_SelectObject->Release();
	}

	m_SelectObject = CMeshObstacle::Create(m_thisPos, m_thisType);
}
//==========================================================================================
//�I�u�W�F�N�g��ݒu���鏈��
//==========================================================================================
void CMapEdit::SetObject()
{
	CMeshObstacle::Create(m_thisPos, m_thisType);
	ObjInfo[m_MaxObj].pos = m_thisPos;
	ObjInfo[m_MaxObj].SelType = m_thisType;
	++m_MaxObj;
}

//==========================================================================================
//�I�u�W�F�N�g�̎�ނ�ς��鏈��
//==========================================================================================
void CMapEdit::SelectObjType()
{
	if (CManager::GetInstance()->GetKeyboard()->GetTrigger(DIK_1) == true)
	{
		--m_thisType;
		if (m_thisType < 0)
		{
			m_thisType = MAX_OBJNUM - 1;
		}
		SelectObject();
	}
	else if (CManager::GetInstance()->GetKeyboard()->GetTrigger(DIK_2) == true)
	{
		++m_thisType;
		if (m_thisType > MAX_OBJNUM - 1)
		{
			m_thisType = 0;
		}
		SelectObject();
	}
}