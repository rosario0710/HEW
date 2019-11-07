
#include "light.h"
#include "main.h"

//!	���C�g�̎�ށ@p110

#define	NUM_LIGHT		(3)		// ���C�g�̐�(9�R�܂�)

// �O���[�o���ϐ�
Light *light = new Light;
D3DLIGHT9 g_aLight[NUM_LIGHT];		// ���C�g���

// ���C�g�̏���������
void Light::Init()
{
	light->pDevice = GetD3DDevice();		//�f�o�C�X�̎擾
	
	// D3DLIGHT9�\���̂�0�ŃN���A����
	ZeroMemory(&g_aLight[0], sizeof(D3DLIGHT9));

	// ���C�g�̃^�C�v�̐ݒ�	(�f�B���N�V���i�����C�g)
	g_aLight[0].Type = D3DLIGHT_DIRECTIONAL;

	// �g�U��
	g_aLight[0].Diffuse = D3DXCOLOR(1.0f, 1.0f, 1.0f, 1.0f);

	// ����
	g_aLight[0].Ambient = D3DXCOLOR(0.2f, 0.2f, 0.2f, 1.0f);

	// ���C�g�̕����̐ݒ�
	light->vecDir = D3DXVECTOR3(0.20f, -0.80f, 0.40f);
	D3DXVec3Normalize((D3DXVECTOR3*)&g_aLight[0].Direction, &light->vecDir);

	// ���C�g�������_�����O�p�C�v���C���ɐݒ�
	light->pDevice->SetLight(0, &g_aLight[0]);

	// ���C�g��L����
	light->pDevice->LightEnable(0, TRUE);


	// D3DLIGHT9�\���̂�0�ŃN���A����
	ZeroMemory(&g_aLight[1], sizeof(D3DLIGHT9));

	// ���C�g�̃^�C�v�̐ݒ�
	g_aLight[1].Type = D3DLIGHT_DIRECTIONAL;

	// �g�U��
	g_aLight[1].Diffuse = D3DXCOLOR(0.75f, 0.75f, 0.75f, 1.0f);

	// ����
	g_aLight[1].Ambient = D3DXCOLOR(0.2f, 0.2f, 0.2f, 1.0f);

    // ���C�g�̕����̐ݒ�
	light->vecDir = D3DXVECTOR3(-0.20f, 1.00f, -0.50f);
	D3DXVec3Normalize((D3DXVECTOR3*)&g_aLight[1].Direction, &light->vecDir);

	// ���C�g�������_�����O�p�C�v���C���ɐݒ�
	light->pDevice->SetLight(1, &g_aLight[1]);

	// ���C�g��L����
	light->pDevice->LightEnable(1, TRUE);	//���C�g�̐�

#if 0
	// D3DLIGHT9�\���̂�0�ŃN���A����
	ZeroMemory(&g_aLight[2], sizeof(D3DLIGHT9));

	// ���C�g2�̃^�C�v�̐ݒ�
	g_aLight[2].Type = D3DLIGHT_DIRECTIONAL;

	// ���C�g2�̊g�U���̐ݒ�
	g_aLight[2].Diffuse = D3DXCOLOR(0.15f, 0.15f, 0.15f, 1.0f);

	// ���C�g2�̋��ʔ��ˌ��̐ݒ�
	g_aLight[2].Ambient = D3DXCOLOR(0.2f, 0.2f, 0.2f, 1.0f);

    // ���C�g2�̕����̐ݒ�
	light->vecDir = D3DXVECTOR3(0.80f, 0.10f, 0.40f);
	D3DXVec3Normalize((D3DXVECTOR3*)&g_aLight[2].Direction, &light->vecDir);

	// ���C�g2�������_�����O�p�C�v���C���ɐݒ�
	light->pDevice->SetLight(2, &g_aLight[2]);

	// ���C�g2��L����
	light->pDevice->LightEnable(2, TRUE);

#endif
	// ���C�e�B���O���[�h�L���c�V�F�[�f�B���O����
	light->pDevice->SetRenderState(D3DRS_LIGHTING, FALSE);
}

//=============================================================================
// ���C�g�̏I������
//=============================================================================
void Light::Uninit()
{
	delete light;
}

//=============================================================================
// ���C�g�̍X�V����
//=============================================================================
void Light_Update(void)
{
}
