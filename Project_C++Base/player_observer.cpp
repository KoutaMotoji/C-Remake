//===============================================================================
//
//  C++�g����2D(watermelon.cpp)
//								����F���n�O��
// 
//===============================================================================
#include "player_observer.h"
#include "manager.h"

CPlayerX* CPlayerObserver::pPlayer = nullptr;

void CPlayerObserver::PlayerSearch()
{
	if (pPlayer == nullptr)
	{
		for (int j = 0; j < SET_PRIORITY; ++j) {
			for (int i = 0; i < MAX_OBJECT; i++) {
				CObject* pObj = CObject::GetObjects(j, i);
				if (pObj != nullptr) {
					CObject::TYPE type = pObj->GetType();
					if (type == CObject::TYPE::TYPE_3D_PLAYER) {
						CPlayerX* pP = dynamic_cast<CPlayerX*>(pObj);
						if (pP != nullptr)
						{
							pPlayer = pP;
						}
					}
				}
			}
		}
	}
}