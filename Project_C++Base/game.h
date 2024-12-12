//===============================================================================
//
//  C++égÇ¡ÇΩ3D(game.h)
//								êßçÏÅFå≥ínçOëø
// 
//===============================================================================
#ifndef _GAME_H_
#define _GAME_H_

#include "scene.h"
#include "mesh_obstacle.h"

constexpr int MAX_TREESET_NUM = 260;

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
	void MakeRandTree();

	static const int BG_OBJ_CNT;
	CMeshObstacle* m_obs;

};

#endif