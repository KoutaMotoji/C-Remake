//===============================================================================
//
//  C++�g����2D(field.cpp)
//								����F���n�O��
//
//===============================================================================
#include "mesh_cylinder.h"
#include "manager.h"

//�ÓI�����o������
const float CMeshCylinder::MAX_WIDTH = 700.0f;
const float CMeshCylinder::MAX_HEIGHT = 600.0f;
const int CMeshCylinder::MAX_VTX = 12;
const int CMeshCylinder::MAX_INDEX = 14;

const int CMeshCylinder::MAX_CORNER = 6;


//==========================================================================================
//�R���X�g���N�^
//==========================================================================================
CMeshCylinder::CMeshCylinder():m_nVtx(MAX_VTX), m_pos({0.0f,0.0f,0.0f}), m_rot({0.0f,0.0f,0.0f})
{

}

//==========================================================================================
//�f�X�g���N�^
//==========================================================================================
CMeshCylinder::~CMeshCylinder()
{

}

//==========================================================================================
//����������
//==========================================================================================
void CMeshCylinder::Init()
{
	//�e�|�C���^�̏�����
	m_apTexMeshCylinder = nullptr;
	m_pVtxBuffMeshCylinder = nullptr;
	m_pIdxBuffMeshCylinder = nullptr;

	CObject::SetType(TYPE_3D_FIELD);

	LPDIRECT3DDEVICE9 pDevice = CManager::GetInstance()->GetRenderer()->GetDevice();;

	//���_�o�b�t�@�̐���
	pDevice->CreateVertexBuffer(sizeof(VERTEX_3D) * MAX_VTX,
		D3DUSAGE_WRITEONLY,
		FVF_VERTEX_3D,
		D3DPOOL_MANAGED,
		&m_pVtxBuffMeshCylinder,
		NULL);

	//�C���f�b�N�X�o�b�t�@�̐���
	pDevice->CreateIndexBuffer(sizeof(WORD) * MAX_INDEX,
		D3DUSAGE_WRITEONLY,
		D3DFMT_INDEX16,
		D3DPOOL_MANAGED,
		&m_pIdxBuffMeshCylinder,
		NULL);

	VERTEX_3D* pVtx;	//���_���̃|�C���^

	m_pVtxBuffMeshCylinder->Lock(0, 0, (void**)&pVtx, 0);

	for (int i = 0; i < 2; ++i)	{
		for (int j = 0; j < MAX_CORNER; ++j)	{
			float radian = (((float)j) / (float)MAX_CORNER);
			pVtx[i + j].pos.x = m_pos.x + (cosf(radian  * 2 * D3DX_PI) * MAX_WIDTH);
			pVtx[i + j].pos.z = m_pos.z + (sinf(radian  * 2 * D3DX_PI) * MAX_WIDTH);
			pVtx[i + j].pos.y = m_pos.y + i * MAX_HEIGHT;
		}
	}
	for (int i = 0; i < MAX_VTX; ++i)
	{
		pVtx[i].nor = D3DXVECTOR3(0.0f, 1.0f, 0.0f);

		pVtx[i].col = D3DCOLOR_RGBA(255, 255, 255, 255);
	}

	m_pVtxBuffMeshCylinder->Unlock();

	int nLoop = 0;

	WORD* pIdx;	//�C���f�b�N�X���̃|�C���^

	//�C���f�b�N�X�o�b�t�@�̃��b�N
	m_pIdxBuffMeshCylinder->Lock(0, 0, (void**)&pIdx, 0);

	for (int X = 0; X < MAX_CORNER; ++X)
	{
		pIdx[nLoop] = (X + MAX_CORNER);

		++nLoop;

		pIdx[nLoop] = (X);

		++nLoop;
	}

	pIdx[nLoop] = (MAX_CORNER);

	++nLoop;

	pIdx[nLoop] = (0);

	m_pIdxBuffMeshCylinder->Unlock();
}

//==========================================================================================
//�I������
//==========================================================================================
void CMeshCylinder::Uninit()
{
	if (m_apTexMeshCylinder != nullptr)
	{
		m_apTexMeshCylinder->Release();
		m_apTexMeshCylinder = nullptr;
	}
	if (m_pIdxBuffMeshCylinder != nullptr)
	{
		m_pIdxBuffMeshCylinder->Release();
		m_pIdxBuffMeshCylinder = nullptr;
	}
	if (m_pVtxBuffMeshCylinder != nullptr)
	{
		m_pVtxBuffMeshCylinder->Release();
		m_pVtxBuffMeshCylinder = nullptr;
	}
}

//==========================================================================================
//�X�V����
//==========================================================================================
void CMeshCylinder::Update()
{

}

//==========================================================================================
//�`�揈��
//==========================================================================================
void CMeshCylinder::Draw()
{
	LPDIRECT3DDEVICE9 pDevice;
	//�f�o�C�X�̎擾
	pDevice = CManager::GetInstance()->GetRenderer()->GetDevice();
	//�v�Z�p�}�g���b�N�X
	D3DXMATRIX mtxRot, mtxTrans;
	//���[���h�}�g���b�N�X
	D3DXMatrixIdentity(&m_mtx);
	//�����𔽉f
	D3DXMatrixRotationYawPitchRoll(&mtxRot,
		m_rot.y,
		m_rot.x,
		m_rot.z);
	D3DXMatrixMultiply(&m_mtx,
		&m_mtx,
		&mtxRot);
	//�ʒu�𔽉f
	D3DXMatrixTranslation(&mtxTrans,
		m_pos.x,
		m_pos.y,
		m_pos.z);
	D3DXMatrixMultiply(&m_mtx,
		&m_mtx,
		&mtxTrans);
	//���[���h�}�g���b�N�X�̐ݒ�
	pDevice->SetTransform(D3DTS_WORLD,
		&m_mtx);
	//���_�o�b�t�@���f�[�^�X�g���[���ɐݒ�
	pDevice->SetStreamSource(0, m_pVtxBuffMeshCylinder, 0, sizeof(VERTEX_3D));
	//�C���f�b�N�X�o�b�t�@���f�[�^�X�g���[���ɐݒ�
	pDevice->SetIndices(m_pIdxBuffMeshCylinder);
	//���_�t�H�[�}�b�g�̐ݒ�
	pDevice->SetFVF(FVF_VERTEX_3D);
	//�e�N�X�`���̐ݒ�
	pDevice->SetTexture(0, m_apTexMeshCylinder);

	pDevice->SetRenderState(D3DRS_CULLMODE, D3DCULL_NONE);	//�J�����O�߂�


	//�|���S���̕`��
	pDevice->DrawIndexedPrimitive(D3DPT_TRIANGLESTRIP,
		0,
		0,
		MAX_INDEX,
		0,
		12);

	pDevice->SetRenderState(D3DRS_CULLMODE, D3DCULL_CCW);	//�J�����O�߂�

}


//==========================================================================================
//��������
//==========================================================================================
CMeshCylinder* CMeshCylinder::Create(D3DXVECTOR3 pos)
{
	CMeshCylinder* field = new CMeshCylinder;
	field->Init();
	return field;
}
