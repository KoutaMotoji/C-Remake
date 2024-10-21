//===============================================================================
//
//  C++使った2D(billboard.h)
//								制作：元地弘汰
// 
//===============================================================================
#ifndef _BILLBOARD_H_
#define _BILLBOARD_H_

#include "main.h"
#include "object.h"

class CBillboard :public CObject
{
public:
	CBillboard();				//コンストラクタ
	~CBillboard()override;		//デストラクタ
	void Init()override;		//初期化
	void Uninit()override;		//終了
	void Update()override;		//更新
	void Draw()override;		//描画


	D3DXVECTOR3 GetPos() { return m_pos; ; };
	void SetPos(D3DXVECTOR3 pos) { m_pos = pos; };
	void AddPos(D3DXVECTOR3 value) { m_pos += value; };
	D3DXVECTOR2 GetAnim() { return m_Anim; };
	void SetAnim(D3DXVECTOR2 Anim) { m_Anim = Anim; };
	void AddAnim(D3DXVECTOR2 Anim) { m_Anim += Anim; };
	D3DXVECTOR3 GetScale() { return m_scale; };								//大きさを取得
	void SetScale(float scale) { m_scale = { scale,scale,0.0f }; };			//大きさ変更
	void AddScale(float scale) { m_scale += { scale, scale,0.0f }; };		//大きさを加算
	static CBillboard* Create(D3DXVECTOR3 pos);
	void SetPolygonParam(D3DXVECTOR3 pos, float fHeight, float fWidth);					//初期設定
	void SetPolygonParam(D3DXVECTOR3 pos, float fHeight, float fWidth, D3DXCOLOR col);	//初期設定(色変更オーバーロード)

	void BindTexture(LPDIRECT3DTEXTURE9 pTex);	//作ったテクスチャ 
	void BindTexture(LPDIRECT3DTEXTURE9 pTex,D3DXVECTOR2 Slice);	//作ったテクスチャ(アニメーション用オーバーロード) 
	
private:
	LPDIRECT3DTEXTURE9 m_pTextureBillboard;
	LPDIRECT3DVERTEXBUFFER9 m_pVtxBuffBillboard;

	D3DXVECTOR3 m_pos;
	D3DXVECTOR3 m_rot;
	D3DXVECTOR3 m_scale;
	D3DXCOLOR m_col;
	D3DXVECTOR2 m_Slice;
	D3DXVECTOR2 m_Anim;
	D3DXMATRIX m_mtxWorld;
	static const int MAX_VERTEX;
	static const int MAX_POLYGON;
	float m_fAngle;
	float m_fLength;
	float m_fHeight;
	float m_fWidth;
	static const float MAX_OBJ3DHEIGHT;
	static const float MAX_OBJ3DWIDTH;
};

#endif