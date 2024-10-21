//===============================================================================
//
//		C++使った2D(input.h)
//								制作：元地弘汰
// 
//===============================================================================
#ifndef _INPUT_H_
#define _INPUT_H_

#include "main.h"

#define NUM_KEY_MAX (256)

class CInput
{
public:
	CInput();
	~CInput();
	virtual HRESULT Init(HINSTANCE hInstance, HWND hWnd);
	virtual void Uninit();
	virtual void Update() = 0;
protected:
	static LPDIRECTINPUT8 m_pInput;
	LPDIRECTINPUTDEVICE8 m_pDevice;
};
//
//typedef enum
//{
//	JOYPAD_DPAD_UP = 0,
//	JOYPAD_DPAD_DOWN,
//	JOYPAD_DPAD_LEFT,
//	JOYPAD_DPAD_RIGHT,
//	JOYPAD_START,
//	JOYPAD_BACK,
//	JOYPAD_LEFT_THUMB,
//	JOYPAD_RIGHT_THUMB,
//	JOYPAD_LEFT_SHOULDER,
//	JOYPAD_RIGHT_SHOULDER,
//	JOYPAD_7,
//	JOYPAD_8,
//	JOYPAD_A,
//	JOYPAD_B,
//	JOYPAD_X,
//	JOYPAD_Y,
//	JOYPAD_MAX
//}JOYKEY;
////プロトタイプ宣言
//HRESULT InitKeyboard(HINSTANCE hInstance, HWND hWnd);
//void UninitKeyboard(void);
//void UpdateKeyboard(void);
//bool GetKeyboardPress(int nKey);
//bool GetKeyboardTrigger(int nKey);
//HRESULT InitJoypad(void);
//void UninitJoypad(void);
//void UpdateJoypad(void);
//bool GetJoypadPress(JOYKEY key);
//bool GetJoypadTrigger(JOYKEY key);


#endif // !_INPUT_H_
