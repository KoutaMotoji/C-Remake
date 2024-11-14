//===============================================================================
//
//  C++�g����3D(particle_system.h)
//								����F���n�O��
// 
//===============================================================================

#ifndef _PARTICLE_SYSTEM_H_
#define _PARTICLE_SYSTEM_H_

#include "main.h"
#include "object.h"

using namespace std;

/// <summary>
/// �p�[�e�B�N���V�X�e���̃N���X
/// </summary>
class CParticleSystem : public CObject
{
public:
	~CParticleSystem() {};
	void Init()override {};		//������
	void Uninit()override {};		//�I��
	void Update()override {};		//�X�V
	void Draw()override {};		//�`��
private:
	D3DXVECTOR3 m_pos;	//�ʒu
	int m_nNum;			//�p�[�e�B�N����
	float m_fGap;		//���S�ƊO���̃M���b�v
};


//==========================================================================================================================
/// <summary>
/// �p�[�e�B�N���̎ˏo���@���Ǘ�����N���X�Q
/// </summary>
class CEmitte_Type
{
public:
	virtual ~CEmitte_Type() = default;
	virtual void SetEmitte() {};
};

//�p���I�ɔ��˂���
class CEmitte_Loop
{

};

//��u�Ŕ����I�ɔ��˂���
class CEmitte_Bomb
{

};
//==========================================================================================================================

//==========================================================================================================================
/// <summary>
/// �p�[�e�B�N���̔��ˌ`����Ǘ�����N���X�Q
/// </summary>
class CEmitte_Form
{
public:
	virtual ~CEmitte_Form() = default;
	virtual void DoEmitte() = 0;
};

class CEmitte_Line : public CEmitte_Form
{
public:
	void DoEmitte()override;
};

class CEmitte_Sphere : public CEmitte_Form
{
public:
	void DoEmitte()override;
};

class CEmitte_Cone : public CEmitte_Form
{
public:
	void DoEmitte()override;
};
//==========================================================================================================================




#endif