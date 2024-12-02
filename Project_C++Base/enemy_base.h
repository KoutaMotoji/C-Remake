//===============================================================================
//
//  C++�g����2D(enemy_basic.h)
//								����F���n�O��
// 
//===============================================================================
#ifndef _ENEMY_TERRA_H_
#define _ENEMY_TERRA_H_

#include "main.h"
#include "objectX.h"

class CEnemyBase :public CObjectX
{
public:
	CEnemyBase();				//�R���X�g���N�^
	~CEnemyBase()override;		//�f�X�g���N�^
	void Init()override;		//������
	void Uninit()override;		//�I��
	void Update()override;		//�X�V
	void Draw()override;		//�`��
	static CEnemyBase* Create(D3DXVECTOR3 pos);

	void Damaged();

protected:
	bool m_bMove;
	D3DXVECTOR3 m_DefPos;
private:
};



#endif