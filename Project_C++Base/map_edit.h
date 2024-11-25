//===============================================================================
//
//  C++�g����3D(game.h)
//								����F���n�O��
// 
//===============================================================================
#ifndef _MAP_EDIT_H_
#define _MAP_EDIT_H_

#include "scene.h"
#include "objectX.h"

#define MAX_EDITOBJ	(1024)

constexpr int MAX_OBJNUM = 4;

class CMapEdit : public CScene
{
public:
	typedef struct
	{
		D3DXVECTOR3 pos;
		int SelType;
	}SetInfo;
	enum
	{
		Sel_3DBlock = 0,
		Sel_3DBlock2,
		Sel_3DEnemy,
		Sel_3DEnemy2,
		Sel_Start,
		Sel_Goal,
		Sel_Ground,
		Sel_3DEnemy3,
		Sel_MAX
	};
	CMapEdit();
	~CMapEdit()override;
	HRESULT Init()override;
	void Uninit()override;
	void Update()override;
	void Draw()override;
	void LoadFile();	//�t�@�C������ǂݍ���Ŕz�u(�ꊇ)

	D3DXVECTOR3 GetThisPos() { return m_thisPos; };
private:
	void SaveFile();	//�z�u����ۑ�
	void EditObj();		//�I�u�W�F�N�g��z�u
	void SelectObjType();
	void SelectObject();
	void SetObject();	//Enter�����������̃I�u�W�F�N�g����


	CObjectX* m_SelectObject;
	CObjectX* m_LastObj;
	const float MOVE_SCALE;

	D3DXVECTOR3 m_thisPos;
	int m_thisType;
	int m_MaxObj;
	SetInfo ObjInfo[MAX_EDITOBJ];

	//�f�o�b�O�\���p�t�H���g
	LPD3DXFONT m_pFont;
};

#endif