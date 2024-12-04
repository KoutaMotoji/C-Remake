//=============================================================================
//
// �T�E���h���� [sound.h]
// Author : Akira Tanaka
//
//=============================================================================
#ifndef _SOUND_H_
#define _SOUND_H_

#include "main.h"


class CSound
{
public:
	//�T�E���h�ꗗ
	typedef enum
	{
		SOUND_LABEL_TITLESE_OPEN = 0,
		SOUND_LABEL_TITLESE_LIFT,
		SOUND_LABEL_TITLESE_RIDER,
		SOUND_LABEL_TITLESE_MOVE,
		SOUND_LABEL_TITLESE_ENTER,
		SOUND_LABEL_MAX

	} SOUND_LABEL;
	CSound();								//�R���X�g���N�^
	~CSound();								//�f�X�g���N�^
	HRESULT Init(HWND hWnd);			//������
	void Uninit(void);					//�I��
	HRESULT PlaySound(SOUND_LABEL label);	//�T�E���h�Đ�
	void StopSound(SOUND_LABEL label);		//�T�E���h��~(���x���w��)
	void StopSound(void);					//�T�E���h��~(���ׂ�)

	HRESULT CheckChunk(HANDLE hFile, DWORD format, DWORD* pChunkSize, DWORD* pChunkDataPosition);
	HRESULT ReadChunkData(HANDLE hFile, void* pBuffer, DWORD dwBuffersize, DWORD dwBufferoffset);
private:
	typedef struct
	{
		const char* pFilename;	// �t�@�C����
		int nCntLoop;			// ���[�v�J�E���g
	} SOUNDINFO;
	IXAudio2* m_pXAudio2 = NULL;								// XAudio2�I�u�W�F�N�g�ւ̃C���^�[�t�F�C�X
	IXAudio2MasteringVoice* m_pMasteringVoice = NULL;			// �}�X�^�[�{�C�X
	IXAudio2SourceVoice* m_apSourceVoice[SOUND_LABEL_MAX] = {};	// �\�[�X�{�C�X
	BYTE* m_apDataAudio[SOUND_LABEL_MAX] = {};					// �I�[�f�B�I�f�[�^
	DWORD m_aSizeAudio[SOUND_LABEL_MAX] = {};					// �I�[�f�B�I�f�[�^�T�C�Y

	// �T�E���h�̏��
	SOUNDINFO m_aSoundInfo[SOUND_LABEL_MAX] =
	{
		{"data/SOUND/opener1.wav", 0},	//�J����
		{"data/SOUND/lift2.wav", 0},	//���t�g��������
		{"data/SOUND/rider1.wav", 0},	//�u�[�X�^�[���オ�鉹
		{"data/SOUND/move1.wav", 0},	//���@��������
		{"data/SOUND/Enter1.wav", 0},	//Enter�L�[�������ꂽ��

	};
};

#endif
