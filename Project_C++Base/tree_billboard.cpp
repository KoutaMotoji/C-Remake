//===============================================================================
//
//  C++�g����2D(tree_billboard.h)
//								����F���n�O��
// 
//===============================================================================
#include "tree_billboard.h"
#include "test_meshCollision.h"
#include "collision.h"

#include "manager.h"


//==========================================================================================
//�R���X�g���N�^
//==========================================================================================
CTreeBillboard::CTreeBillboard(int nPriority):CBillboard(nPriority)
{
	m_snTexIdx[0] = CManager::GetInstance()->GetTexture()->Regist("data\\TEXTURE\\Tree000.png");
	m_snTexIdx[1] = CManager::GetInstance()->GetTexture()->Regist("data\\TEXTURE\\Tree001.png");
	m_snTexIdx[2] = CManager::GetInstance()->GetTexture()->Regist("data\\TEXTURE\\Tree002.png");
}

//==========================================================================================
//�f�X�g���N�^
//==========================================================================================
CTreeBillboard::~CTreeBillboard()
{

}

//==========================================================================================
//����������
//==========================================================================================
void CTreeBillboard::Init()
{
	CObject::SetType(TYPE_BILLBOARD);
	CBillboard::Init();
}

//==========================================================================================
//�I������
//==========================================================================================
void CTreeBillboard::Uninit()
{
	CBillboard::Uninit();
}

//==========================================================================================
//�X�V����
//==========================================================================================
void CTreeBillboard::Update()
{
	CBillboard::Update();
}

//==========================================================================================
//��������
//==========================================================================================
CTreeBillboard* CTreeBillboard::Create(D3DXVECTOR3 pos, int TexIdx)
{
	CTreeBillboard* tree = new CTreeBillboard();

	tree->SetPolygonParam(pos, Poly_Radius, Poly_Radius, {1.0f,1.0f,1.0f,1.0f});
	tree->BindTexture(CManager::GetInstance()->GetTexture()->GetAddress(tree->m_snTexIdx[TexIdx]));
	tree->Init();
	tree->SetPosGround(Poly_Radius);
	return tree;
}

//==========================================================================================
//�n�`���b�V���ɉ����Ĉʒu�����킹�鏈��
//==========================================================================================
void CTreeBillboard::SetPosGround(float HalfRadius)
{
	CCollision* pCollision = new CCollision();
	D3DXVECTOR3 dir = { 0.0f,1.0f,0.0f };
	float Distance = 0;

	LPD3DXMESH pMesh = nullptr;
	for (int j = 0; j < SET_PRIORITY; j++) {
		for (int i = 0; i < MAX_OBJECT; i++) {
			CObject* pObj = CObject::GetObjects(j, i);
			if (pObj != nullptr) {
				CObject::TYPE type = pObj->GetType();
				if (type == CObject::TYPE::TYPE_3D_MESHOBJECT) {
					CTestMeshCollision* pTest = dynamic_cast<CTestMeshCollision*>(pObj);
					if (pTest != nullptr) {
						pMesh = pTest->GetMesh();
						D3DXVECTOR3 pos = CBillboard::GetPos();

						D3DXVECTOR3 objpos = pos - pTest->GetPos();
						float ChedkDis = 2000.0f;
						// ----- �ڒn������ -----
						if (pCollision->MeshToIntersectCollision(&Distance,pMesh, objpos, dir, ChedkDis))
						{
							delete pCollision;
							pCollision = nullptr;

							CBillboard::AddPos({ 0.0f,Distance + HalfRadius,0.0f });
							return;
						}
					}
				}
			}
		}
	}
	if (pCollision != nullptr)
	{
		delete pCollision;
		pCollision = nullptr;
	}
}