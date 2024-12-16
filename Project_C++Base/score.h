//===============================================================================
//
//  C++�g����3D(score.h)
//								����F���n�O��
// 
//===============================================================================
#ifndef _SCORE_H_
#define _SCORE_H_

#include "main.h"
#include "number.h"

static constexpr int MAX_DIGIT = 8;
static constexpr float MAX_HEIGHT = 40.0f;
static constexpr float MAX_WIDTH = 70.0f;

class CScore
{
public:
	CScore();		//�R���X�g���N�^
	~CScore();		//�f�X�g���N�^
	void Init();		//������
	void Uninit();		//�I��
	void Update();		//�X�V
	void Draw();		//�`��
	static CScore* Create();
	
	void LoadLastScore() { m_Score = SaveScore; GetLastNum(); }
	void ResetScore() { m_Score += 0; GetLastNum(); };
	void SetScore(int nScore) { m_Score = nScore; GetLastNum(); SaveScore = m_Score; }
	void AddScore(int nScore) { m_Score += nScore; GetLastNum(); SaveScore = m_Score;}
private:
	void GetLastNum();
	int m_Score;

	static const D3DXVECTOR3 DEFAULT_POSITION;
	static int SaveScore;
	CNumber* m_number[MAX_DIGIT];
};

#endif