//===============================================================================
//
//  C++使った2D(TitleBg.h)
//								制作：元地弘汰
// 
//===============================================================================
#ifndef _TITLEUI_H_
#define _TITLEUI_H_

#include "main.h"
#include "object2D.h"

static constexpr float SWAP_SPEED = 0.02f;

class CTitleUI :public CObject2D
{
public:
	CTitleUI(int nPriority = SET_PRIORITY - 1);					//コンストラクタ
	~CTitleUI()override;			//デストラクタ
	void Init()override;		//初期化
	void Uninit()override;		//終了
	void Update()override;		//更新
	void Draw()override;		//描画

	static CTitleUI* Create(D3DXVECTOR3 pos, int Type,D3DXVECTOR2 PolySize);
private:
};

class CTitleLogo : public CTitleUI
{
public:
	void Init()override;		//初期化
	void Update()override;		//更新
};

class CTitleButton : public CTitleUI
{
public:
	CTitleButton() : m_LocalCol({ 1.0f,1.0f,1.0f,1.0f }), m_bColSwitch(false) {}
	void Init()override;		//初期化
	void Update()override;		//更新
private:
	void AlphableUI();
	bool m_bColSwitch;
	D3DXCOLOR m_LocalCol;
};

#endif