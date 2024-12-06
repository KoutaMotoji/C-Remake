//===============================================================================
//
//  C++�g����2D(shadow.cpp)
//								����F���n�O��
// 
//===============================================================================
#include "shadow.h"
#include "manager.h"
#include "mesh_ground.h"
#include "player_observer.h"

//==========================================================================================
//������
//==========================================================================================
void CShadow::Init()
{
	int nIdx = CManager::GetInstance()->GetTexture()->Regist("data\\TEXTURE\\shadow000.jpg");
	BindTexture(CManager::GetInstance()->GetTexture()->GetAddress(nIdx));
	CObject3D::Init();
}

//==========================================================================================
//������
//==========================================================================================
void CShadow::Draw()
{
	LPDIRECT3DDEVICE9 pDevice = CManager::GetInstance()->GetRenderer()->GetDevice();

	//�A���t�@�e�X�g�ݒ�
	pDevice->SetRenderState(D3DRS_ALPHATESTENABLE, TRUE);
	pDevice->SetRenderState(D3DRS_ALPHAREF, 0);
	pDevice->SetRenderState(D3DRS_ALPHAFUNC, D3DCMP_GREATER);

	//���Z�����̐ݒ�
	pDevice->SetRenderState(D3DRS_BLENDOP, D3DBLENDOP_REVSUBTRACT);
	pDevice->SetRenderState(D3DRS_SRCBLEND, D3DBLEND_SRCALPHA);
	pDevice->SetRenderState(D3DRS_DESTBLEND, D3DBLEND_ONE);

	//Z�A���t�@
	pDevice->SetRenderState(D3DRS_ZFUNC, D3DCMP_ALWAYS);
	pDevice->SetRenderState(D3DRS_ZWRITEENABLE, FALSE);

	CObject3D::Draw();

	//�ʏ�̍����ɖ߂��ݒ�
	pDevice->SetRenderState(D3DRS_BLENDOP, D3DBLENDOP_ADD);
	pDevice->SetRenderState(D3DRS_SRCBLEND, D3DBLEND_SRCALPHA);
	pDevice->SetRenderState(D3DRS_DESTBLEND, D3DBLEND_INVSRCALPHA);
	pDevice->SetRenderState(D3DRS_ALPHATESTENABLE, FALSE);

	//Z�A���t�@
	pDevice->SetRenderState(D3DRS_ZFUNC, D3DCMP_LESSEQUAL);
	pDevice->SetRenderState(D3DRS_ZWRITEENABLE, TRUE);
	pDevice->SetRenderState(D3DRS_ALPHATESTENABLE, FALSE);
}

//==========================================================================================
//��������
//==========================================================================================
CShadow* CShadow::Create(D3DXVECTOR3 pos)
{
	CShadow* shadow = new CShadow;

	shadow->SetPolygonParam(pos, DEF_RADIUS, DEF_RADIUS);
	shadow->Init();

	return shadow;
}

//==========================================================================================
//��������
//==========================================================================================
void CShadow::SetShadowGround(D3DXVECTOR3 pos)
{
	// �n�`����
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
							// �n�`����

							LPD3DXMESH pMesh = nullptr;
							D3DXVECTOR3 dir = D3DXVECTOR3(0.0f, -1.0f, 0.0f);

							pMesh = pTest->GetMesh();
							vEnd = objpos + dir;
							D3DXMATRIX objMtx = pTest->GetMatrix();

							// ���C�𓖂Ă�Ώۂ̃}�g���b�N�X�̋t�s����擾���A�n�_�ƏI�_�̍��W�ɑ΂��č��W�ϊ����s���A�ʒu�E��]�E�傫���̕�Ԃ�����
							D3DXMatrixInverse(&mWorld, NULL, &objMtx);
							D3DXVec3TransformCoord(&vStartl, &objpos, &mWorld);
							D3DXVec3TransformCoord(&vEnd, &vEnd, &mWorld);

							vDirl = vEnd - vStartl;
							D3DXVec3Normalize(&vDirl, &vDirl);
							pMesh = pTest->GetMesh();
							D3DXIntersect(pMesh, &vStartl, &vDirl, &bIsHit, &dwHitIndex, &fHitU, &fHitV, &fLandDistance, nullptr, nullptr);

							if (bIsHit)
							{
								// ���������C���f�b�N�X�o�b�t�@�擾
								WORD dwHitVertexNo[3];
								WORD* pIndex;
								HRESULT hr = pMesh->LockIndexBuffer(0, (void**)&pIndex);
								
								for (int nIdxIdx = 0; nIdxIdx < 3; nIdxIdx++)
								{
									dwHitVertexNo[nIdxIdx] = pIndex[dwHitIndex * 3 + nIdxIdx];
								}

								pMesh->UnlockIndexBuffer();

								// ���������|���S���擾
								VERTEX_3D* pVertex;
								hr = pMesh->LockVertexBuffer(0, (void**)&pVertex);

								////���C�ƌ������Ă���|���S����3���_�̊O�ς��o���Ė@���x�N�g�������߁A����Ƀ|���S�������킹��
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

								////�N�I�[�^�j�I�������]�}�g���b�N�X���쐬
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