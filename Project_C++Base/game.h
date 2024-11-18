//===============================================================================
//
//  C++égÇ¡ÇΩ3D(game.h)
//								êßçÏÅFå≥ínçOëø
// 
//===============================================================================
#ifndef _GAME_H_
#define _GAME_H_

#include "scene.h"
#include "test_obstacle.h"


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
	void MakeRandTree();

	static const int BG_OBJ_CNT;
	CTestObstacle* m_obs;

};

#endif