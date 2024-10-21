//===============================================================================
//
//  C++�g����2D(start.cpp)
//								����F���n�O��
// 
//===============================================================================
#include "collision.h"

//==========================================================================================
//�R���X�g���N�^
//==========================================================================================
CCollision::CCollision()
{

}

//==========================================================================================
//�f�X�g���N�^
//==========================================================================================
CCollision::~CCollision()
{

}


//==========================================================================================
//�~�`�����蔻��
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

