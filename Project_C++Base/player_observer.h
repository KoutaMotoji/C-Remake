//===============================================================================
//
//  プレイヤー監視クラス(Block.h)
//								制作：元地弘汰
// 
//===============================================================================
#ifndef _PLAYER_OBSERVER_H_
#define _PLAYER_OBSERVER_H_

#include "main.h"
#include "playerX.h"

//カメラクラス
class CPlayerObserver
{
public:
	CPlayerObserver();
	static void PlayerSearch();
	static void PlayerObsDestroy();
	static D3DXVECTOR3 GetPlayerPos();
	static CPlayerX* GetPlayer();
	static D3DXVECTOR3 GetPlayerMove();
private:
	static CPlayerX* pPlayer;
};

#endif 
