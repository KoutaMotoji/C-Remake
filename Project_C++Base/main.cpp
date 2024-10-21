//===============================================================================
//
//  2D�A�N�V����Master��(main.cpp)
//								����F���n�O��
// 
//===============================================================================
#include "main.h"
#include "manager.h"

//�}�N����`
#define CLASS_NAME	"WindowClass" //�E�B���h�E�N���X�̖��O
#define WINDOW_NAME	"MetalStrike"
#define ID_BUTTON_RESET	(101)

//�v���g�^�C�v�錾
LRESULT CALLBACK WindowProc(HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam);

//�O���[�o���ϐ�
bool g_bExit = false;
int g_nCountFPS;
//============================================
//���C���֐�
//============================================
int WINAPI WinMain(_In_ HINSTANCE hInstance, _In_opt_ HINSTANCE hInstancePrev, _In_ LPSTR lpCmdLine, _In_ int nCmdShow)
{
	WNDCLASSEX wcex =
	{
		sizeof(WNDCLASSEX),
		CS_CLASSDC,
		WindowProc,
		0,
		0,
		hInstance,
		LoadIcon(NULL,IDI_APPLICATION),
		LoadCursor(NULL,IDC_ARROW),
		(HBRUSH)(COLOR_WINDOW + 1),
		NULL,
		CLASS_NAME,
		LoadIcon(NULL,IDI_APPLICATION)

	};
	
	HWND hWnd;
	MSG msg;
	RECT rect = { 0,0,SCREEN_WIDTH,SCREEN_HEIGHT };
	//�E�B���h�E�N���X�̓o�^
	RegisterClassEx(&wcex);
	//�N���C�A���g�̈���w��̃T�C�Y�ɒ���
	AdjustWindowRect(&rect, WS_OVERLAPPEDWINDOW, FALSE);
	//�E�B���h�E�𐶐�
	hWnd = CreateWindowEx(0,
		CLASS_NAME,
		WINDOW_NAME,
		WS_OVERLAPPEDWINDOW,
		CW_USEDEFAULT,
		CW_USEDEFAULT,
		(rect.right - rect.left),
		(rect.bottom - rect.top),
		NULL,
		NULL,
		hInstance,
		NULL);

	DWORD dwCurrentTime;		//���ݎ���
	DWORD dwExecLastTime;		//���ݎ������擾
	DWORD dwFrameCount;			//�t���[���J�E���g
	DWORD dwFPSLastTime;		//�Ō��FPS���v����������
	CManager* pManager = CManager::GetInstance();
	pManager->Init(hInstance, hWnd, TRUE);

	ShowWindow(hWnd, nCmdShow);
	UpdateWindow(hWnd);

	//����\��ݒ�
	timeBeginPeriod(1);
	dwCurrentTime = 0;				//����������
	dwExecLastTime = timeGetTime();	//���ݎ����擾
	dwFrameCount = 0;
	dwFPSLastTime = timeGetTime();

	//���b�Z�[�W���[�v
	while (1)
	{
		if (PeekMessage(&msg, NULL, 0, 0, PM_REMOVE) != 0)
		{//windows�̐ݒ�
			if (msg.message == WM_QUIT)
			{
				break;
			}
			else
			{
				//���b�Z�[�W�̐ݒ�
				TranslateMessage(&msg);
				DispatchMessage(&msg);
			}
		}
		else
		{//DirectX�̏���
			dwCurrentTime = timeGetTime();	//���ݎ������擾
			if ((dwCurrentTime - dwFPSLastTime) >= 500)
			{//0.5�b�o��
				//FPS���v��
				g_nCountFPS = (dwFrameCount * 1000) / (dwCurrentTime - dwFPSLastTime);
				dwFPSLastTime = dwCurrentTime;
				dwFrameCount = 0;
			}
			if((dwCurrentTime - dwExecLastTime) >= (1000/60))
			{
				dwExecLastTime = dwCurrentTime;	//�����J�n�̎�����ۑ�
				//�X�V����
				pManager->Update();
				//�`�揈��
				pManager->Draw();
				dwFrameCount++;
				if (g_bExit == true)
				{
					// �E�B���h�E��j������
					DestroyWindow(hWnd);
				}
			}
		}
	}
	//�I������
	if (pManager != nullptr)
	{
		pManager->Uninit();
		delete pManager;
		pManager = nullptr;
	}

	//����\��߂�
	timeEndPeriod(1);
	g_nCountFPS = 0;
	//�E�B���h�E�N���X�̓o�^����
	UnregisterClass(CLASS_NAME, wcex.hInstance);
	return(int)msg.wParam;
}

//==========================================================================================
//�E�B���h�E�v���V�[�W��
//==========================================================================================
LRESULT CALLBACK WindowProc(HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam)
{

	int nID;
	//HWND hWndButtonReset;
	switch (uMsg)
	{
	case WM_CLOSE:
		nID = MessageBox(hWnd, "�I�����܂����H", "�I�����b�Z�[�W", MB_YESNO | MB_ICONEXCLAMATION);
		if (nID == IDYES)
		{
			//�E�B���h�E��j������
			DestroyWindow(hWnd);
		}
		else
		{
			return 0;
		}
		break;
	case WM_KEYDOWN:
		switch (wParam)
		{
		case VK_ESCAPE:
			nID = MessageBox(hWnd, "�I�����܂����H", "�I�����b�Z�[�W", MB_YESNO | MB_ICONEXCLAMATION);
			if (nID == IDYES)
			{
				//�E�B���h�E��j������
				DestroyWindow(hWnd);
			}
			break;
		}
		break;
	case WM_LBUTTONDOWN:
		//�E�B���h�E�Ƀt�H�[�J�X�����킹��
		SetFocus(hWnd);
		break;
	case WM_DESTROY:
		//WM_QUIT���b�Z�[�W�𑗂�
		PostQuitMessage(0);
		break;
	}
	return DefWindowProc(hWnd, uMsg, wParam, lParam);
}

void SetExitGame(void)
{
	g_bExit = true;
}


