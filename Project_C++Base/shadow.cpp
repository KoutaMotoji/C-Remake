//===============================================================================
//
//  C++使った2D(shadow.cpp)
//								制作：元地弘汰
// 
//===============================================================================
#include "shadow.h"
#include "manager.h"
#include "mesh_ground.h"
#include "player_observer.h"

//==========================================================================================
//初期化
//==========================================================================================
void CShadow::Init()
{
	int nIdx = CManager::GetInstance()->GetTexture()->Regist("data\\TEXTURE\\shadow000.jpg");
	BindTexture(CManager::GetInstance()->GetTexture()->GetAddress(nIdx));
	CObject3D::Init();
}

//==========================================================================================
//初期化
//==========================================================================================
void CShadow::Draw()
{
	LPDIRECT3DDEVICE9 pDevice = CManager::GetInstance()->GetRenderer()->GetDevice();

	//アルファテスト設定
	pDevice->SetRenderState(D3DRS_ALPHATESTENABLE, TRUE);
	pDevice->SetRenderState(D3DRS_ALPHAREF, 0);
	pDevice->SetRenderState(D3DRS_ALPHAFUNC, D3DCMP_GREATER);

	//減算合成の設定
	pDevice->SetRenderState(D3DRS_BLENDOP, D3DBLENDOP_REVSUBTRACT);
	pDevice->SetRenderState(D3DRS_SRCBLEND, D3DBLEND_SRCALPHA);
	pDevice->SetRenderState(D3DRS_DESTBLEND, D3DBLEND_ONE);

	//Zアルファ
	pDevice->SetRenderState(D3DRS_ZFUNC, D3DCMP_ALWAYS);
	pDevice->SetRenderState(D3DRS_ZWRITEENABLE, FALSE);

	CObject3D::Draw();

	//通常の合成に戻す設定
	pDevice->SetRenderState(D3DRS_BLENDOP, D3DBLENDOP_ADD);
	pDevice->SetRenderState(D3DRS_SRCBLEND, D3DBLEND_SRCALPHA);
	pDevice->SetRenderState(D3DRS_DESTBLEND, D3DBLEND_INVSRCALPHA);
	pDevice->SetRenderState(D3DRS_ALPHATESTENABLE, FALSE);

	//Zアルファ
	pDevice->SetRenderState(D3DRS_ZFUNC, D3DCMP_LESSEQUAL);
	pDevice->SetRenderState(D3DRS_ZWRITEENABLE, TRUE);
	pDevice->SetRenderState(D3DRS_ALPHATESTENABLE, FALSE);
}

//==========================================================================================
//生成処理
//==========================================================================================
CShadow* CShadow::Create(D3DXVECTOR3 pos)
{
	CShadow* shadow = new CShadow;

	shadow->SetPolygonParam(pos, DEF_RADIUS, DEF_RADIUS);
	shadow->Init();

	return shadow;
}

//==========================================================================================
//生成処理
//==========================================================================================
void CShadow::SetShadowGround(D3DXVECTOR3 pos)
{
	// 地形判定
	BOOL  bIsHit = false;
	float fLandDistance;
	DWORD dwHitIndex = 0U;
	float fHitU;
	float fHitV;
	D3DXMATRIX mWorld;
	D3DXVECTOR3 vStartl;
	D3DXVECTOR3 vDirl;
	D3DXVECTOR3 vEnd;
	D3DXVECTOR3 objpos = pos;
	LPD3DXMESH pMesh = nullptr;
	for (int j = 0; j < SET_PRIORITY; ++j) {
		for (int i = 0; i < MAX_OBJECT; i++) {
			CObject* pObj = CObject::GetObjects(j, i);
			if (pObj != nullptr) {
				CObject::TYPE type = pObj->GetType();
				if (type == CObject::TYPE::TYPE_3D_MESHOBJECT) {
					CMeshGround* pTest = dynamic_cast<CMeshGround*>(pObj);
					if (pTest != nullptr) {
						if (pTest != nullptr) {
							// 地形判定

							LPD3DXMESH pMesh = nullptr;
							D3DXVECTOR3 dir = D3DXVECTOR3(0.0f, -1.0f, 0.0f);

							pMesh = pTest->GetMesh();
							vEnd = objpos + dir;
							D3DXMATRIX objMtx = pTest->GetMatrix();

							// レイを当てる対象のマトリックスの逆行列を取得し、始点と終点の座標に対して座標変換を行い、位置・回転・大きさの補間をする
							D3DXMatrixInverse(&mWorld, NULL, &objMtx);
							D3DXVec3TransformCoord(&vStartl, &objpos, &mWorld);
							D3DXVec3TransformCoord(&vEnd, &vEnd, &mWorld);

							vDirl = vEnd - vStartl;
							D3DXVec3Normalize(&vDirl, &vDirl);
							pMesh = pTest->GetMesh();
							D3DXIntersect(pMesh, &vStartl, &vDirl, &bIsHit, &dwHitIndex, &fHitU, &fHitV, &fLandDistance, nullptr, nullptr);

							if (bIsHit)
							{
								// 当たったインデックスバッファ取得
								WORD dwHitVertexNo[3];
								WORD* pIndex;
								HRESULT hr = pMesh->LockIndexBuffer(0, (void**)&pIndex);
								
								for (int nIdxIdx = 0; nIdxIdx < 3; nIdxIdx++)
								{
									dwHitVertexNo[nIdxIdx] = pIndex[dwHitIndex * 3 + nIdxIdx];
								}

								pMesh->UnlockIndexBuffer();

								// 当たったポリゴン取得
								VERTEX_3D* pVertex;
								hr = pMesh->LockVertexBuffer(0, (void**)&pVertex);

								////レイと交差しているポリゴンの3頂点の外積を出して法線ベクトルを求め、それにポリゴンを沿わせる
								//D3DXVECTOR3 VecCross;
								//D3DXVECTOR3 vecA = (pVertex[dwHitVertexNo[0]].pos - pVertex[dwHitVertexNo[2]].pos);
								//D3DXVECTOR3 vecB = (pVertex[dwHitVertexNo[1]].pos - pVertex[dwHitVertexNo[2]].pos);

								//D3DXVec3Cross(&VecCross, &vecA, &vecB);
								//D3DXVec3Normalize(&VecCross, &VecCross);

								//dir.y = 1.0f;
								//D3DXVECTOR3 VecAx1;
								//D3DXVec3Cross(&VecAx1, &dir, &VecCross);
								//float R1 = (D3DXVec3Dot(&dir, &VecCross)) / sqrtf(D3DXVec3LengthSq(&dir)) * sqrtf(D3DXVec3LengthSq(&VecCross));
								//m_fValueRot = acos(R1);
								//m_quat = { 0, 0, 0, 1 };
								//D3DXQuaternionRotationAxis(&m_quat, &VecAx1, m_fValueRot);

								////クオータニオンから回転マトリックスを作成
								//D3DXMatrixRotationQuaternion(
								//	&m_mtxRot,
								//	&m_quat);

								float size = 2.0 + (4.0f / fLandDistance);

								CObject3D::SetPos({ objpos.x,objpos.y - fLandDistance,objpos.z });
								//CObject3D::SetRot(VecAx1);
								CObject3D::SetSize(size);

								pMesh->UnlockVertexBuffer();
							}
						}
					}
				}
			}
		}
	}
}