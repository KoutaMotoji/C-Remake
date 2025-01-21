//===============================================================================
//
//  C++égÇ¡ÇΩ3D(title.h)
//								êßçÏÅFå≥ínçOëø
// 
//===============================================================================
#ifndef _TITLE_H_
#define _TITLE_H_

#include "scene.h"
#include "t_player.h"
#include "objectX.h"

class CTitle : public CScene
{
public:
	CTitle();
	~CTitle()override;
	HRESULT Init()override;
	void Uninit()override;
	void Update()override;
	void Draw()override;
private:
	void UpdateAnim();
	int m_AnimTimer;
	bool m_bNowAnim;
	CTitlePlayer* m_tPl;
};

class CT_Obj : public CObjectX
{
public:
	CT_Obj() {};
	~CT_Obj()override = default;

	static CT_Obj* Create(D3DXVECTOR3 pos, D3DXVECTOR3 rot);
};

#endif