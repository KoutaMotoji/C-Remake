//===============================================================================
//
//  C++égÇ¡ÇΩ3D(game.h)
//								êßçÏÅFå≥ínçOëø
// 
//===============================================================================
#ifndef _GAME_H_
#define _GAME_H_

#include "scene.h"

class CGame : public CScene
{
public:
	CGame();
	~CGame()override;
	HRESULT Init()override;
	void Uninit()override;
	void Update()override;
	void Draw()override;

private:
	void LoadMapData();
	void SetBGObject();

	static const int BG_OBJ_CNT;
};

#endif