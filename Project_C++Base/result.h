//===============================================================================
//
//  C++�g����3D(result.h)
//								����F���n�O��
// 
//===============================================================================
#ifndef _RESULT_H_
#define _RESULT_H_

#include "scene.h"

class CResult : public CScene
{
public:
	CResult();
	~CResult()override;
	HRESULT Init()override;
	void Uninit()override;
	void Update()override;
	void Draw()override;
};

#endif