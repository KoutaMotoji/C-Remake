//===============================================================================
//
//  C++�g����3D(game.h)
//								����F���n�O��
// 
//===============================================================================
#ifndef _TUTORIAL_H_
#define _TUTORIAL_H_

#include "scene.h"
#include "mesh_obstacle.h"

class CTutorial : public CScene
{
public:
	CTutorial();
	~CTutorial()override;
	HRESULT Init()override;
	void Uninit()override;
	void Update()override;
	void Draw()override;

private:
	int m_nSetTimer;
};

#endif