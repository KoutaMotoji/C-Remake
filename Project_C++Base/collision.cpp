//===============================================================================
//
//  C++使った2D(start.cpp)
//								制作：元地弘汰
// 
//===============================================================================
#include "collision.h"

//==========================================================================================
//コンストラクタ
//==========================================================================================
CCollision::CCollision()
{

}

//==========================================================================================
//デストラクタ
//==========================================================================================
CCollision::~CCollision()
{

}


//==========================================================================================
//円形当たり判定
//==========================================================================================
bool CCollision::CircleCollosion(D3DXVECTOR3 MainPos, D3DXVECTOR3 SubPos, D3DXVECTOR3 MainRadius, D3DXVECTOR3 SubRadious)
{
	float fLengthX = MainPos.x - SubPos.x;
	float fLengthY = MainPos.y - SubPos.y;

	float CenterDistance = sqrtf((fLengthX * fLengthX) + (fLengthY * fLengthY));
	float fAngle = ((MainRadius.x + SubRadious.x) + (MainRadius.y + MainRadius.y)) * 0.5f;

	if (CenterDistance <= fAngle)
	{
		return true;
	}

	return false;
}

//==========================================================================================
//飛ばしたレイとメッシュの判定
//==========================================================================================
bool CCollision::MeshToIntersectCollision(LPD3DXMESH pMesh, D3DXVECTOR3 pos, D3DXVECTOR3 dir, float CheckDistance)
{
	// 地形判定
	BOOL  bIsHit = false;
	float fLandDistance;
	DWORD dwHitIndex = 0U;
	float fHitU;
	float fHitV;

	D3DXIntersect(pMesh, &pos, &dir, &bIsHit, &dwHitIndex, &fHitU, &fHitV, &fLandDistance, nullptr, nullptr);

	return (bIsHit && fLandDistance <= CheckDistance);
}

//==========================================================================================
//飛ばしたレイとメッシュの判定(交差距離を渡すオーバーロード)
//==========================================================================================
bool CCollision::MeshToIntersectCollision(float* Distance,LPD3DXMESH pMesh, D3DXVECTOR3 pos, D3DXVECTOR3 dir, float CheckDistance)
{
	// 地形判定
	BOOL  bIsHit = false;
	float fLandDistance;
	DWORD dwHitIndex = 0U;
	float fHitU;
	float fHitV;

	D3DXIntersect(pMesh, &pos, &dir, &bIsHit, &dwHitIndex, &fHitU, &fHitV, &fLandDistance, nullptr, nullptr);
	*Distance = fLandDistance;
	return (bIsHit && fLandDistance <= CheckDistance);
}