//===============================================================================
//
//  3DÉQÅ[ÉÄäÓëb(collision.h)
//								êßçÏÅFå≥ínçOëø
// 
//===============================================================================
#ifndef _COLLISION_H_
#define _COLLISION_H_

#include "main.h"

#define MAX_LIGHT	(3)
class CCollision
{
public:
	CCollision();
	~CCollision();
	
	bool CircleCollosion(D3DXVECTOR3 MainPos, D3DXVECTOR3 SubPos, D3DXVECTOR3 MainRadius, D3DXVECTOR3 SubRadious);
};

#endif 
