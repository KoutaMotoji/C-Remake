//===============================================================================
//
//  C++�g����2D(playerX.h)
//								����F���n�O��
// 
//===============================================================================
#ifndef _GAUGE_BOSS_LIFE_H_
#define _GAUGE_BOSS_LIFE_H_

#include "billboard.h"

class CGaugeBoss : public CBillboard
{
public:
	CGaugeBoss();
	~CGaugeBoss();

	void Init()override;		//������
	void Uninit()override;		//�I��
	void Update()override;		//�X�V
	void Draw()override;		//�`��

	static CGaugeBoss* Create(D3DXVECTOR3 pos,D3DXVECTOR2 size,int MaxValue);
private:

};


#endif