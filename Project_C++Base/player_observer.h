//===============================================================================
//
//  �v���C���[�Ď��N���X(Block.h)
//								����F���n�O��
// 
//===============================================================================
#ifndef _PLAYER_OBSERVER_H_
#define _PLAYER_OBSERVER_H_

#include "main.h"
#include "playerX.h"

//�J�����N���X
class CPlayerObserver
{
public:
	CPlayerObserver();
	static void PlayerSearch();
	static D3DXVECTOR3 GetPlayerPos() { return pPlayer->GetPos(); }
private:
	static CPlayerX* pPlayer;
};

#endif 
