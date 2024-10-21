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
		SOUND_LABEL_TITLEBGM = 0,
		SOUND_LABEL_GAMEBGM,
		SOUND_LABEL_RESULTBGM,
		SOUND_LABEL_ATTACK,
		SOUND_LABEL_RUSH,
		SOUND_LABEL_DAMAGED,
		SOUND_LABEL_SWING,
		SOUND_LABEL_SELECT,
		SOUND_LABEL_MAX,
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
		{"data/SOUND/TitleBGM.wav", -1},		//BGM1
		{"data/SOUND/GameBGM.wav",		-1},	//BGM2
		{"data/SOUND/ResultBGM.wav", -1},		//BGM3
		{"data/SOUND/Attack.wav", 0},			//�U��SE
		{"data/SOUND/Rush.wav", 0},
		{"data/SOUND/Damaged.wav", 0},
		{"data/SOUND/Swing.wav", 0},
		{"data/SOUND/Select.wav", 0},

	};
};

#endif
