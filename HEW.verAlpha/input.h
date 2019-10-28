/*==================================
	
	[input.h]
	Author : �o���đ�

==================================*/

#pragma once

//�C���N���[�h�t�@�C��
#include <Windows.h>
#define DIRECTINPUT_VERSION (0x0800)
#include <dinput.h>

//�}�N����`	
#define	NUM_KEY_MAX			(256)
//�Q�[���p�b�h�p�̐ݒ�l
#define DEADZONE		2500			// �e����25%�𖳌��]�[���Ƃ���
#define RANGE_MAX		1000			// �L���͈͂̍ő�l
#define RANGE_MIN		-1000			// �L���͈͂̍ŏ��l

//�Q�[���p�b�h�iXbox��PS4�j�̓��͂̃}�N��
//	��	����	
//!	�ԁ@Xbox�̂�
//"	��	PS4�̂�	

#define LEFTSTICK_UP			0x00000001l	//	Xbox��PS4:���X�e�B�b�N��(.IY<0)
#define LEFTSTICK_DOWN			0x00000002l	//	Xbox��PS4:���X�e�B�b�N��(.IY>0)
#define LEFTSTICK_LEFT			0x00000004l	//	Xbox��PS4:���X�e�B�b�N��(.IX<0)
#define LEFTSTICK_RIGHT			0x00000008l	//	Xbox��PS4:���X�e�B�b�N�E(.IX>0)
#define XboxRIGHTSTICK_UP		0x04000000l	//! Xbox:�E�X�e�B�b�N��(.lRz<16383)
#define XboxRIGHTSTICK_DOWN		0x10000000l	//! Xbox:�E�X�e�B�b�N��(.lRz>49150)
#define XboxRIGHTSTICK_LEFT		0x20000000l	//! Xbox:�E�X�e�B�b�N�E(.lZ<16383)
#define XboxRIGHTSTICK_RIGHT	0x40000000l	//! Xbox:�E�X�e�B�b�N��(.lZ>49150)
#define PS4RIGHTSTICK_UP		0x00000010l	//" PS4:�E�X�e�B�b�N��(.lRz<16383)
#define PS4RIGHTSTICK_DOWN		0x00000020l	//" PS4:�E�X�e�B�b�N��(.lRz>49150)
#define PS4RIGHTSTICK_RIGHT		0x00000040l //" PS4:�E�X�e�B�b�N�E(.lZ<16383)
#define PS4RIGHTSTICK_LEFT		0x00000080l //" PS4:�E�X�e�B�b�N��(.lZ>49150)
#define TRIGGER_LT				0x00000100l //! Xbox:LT�g���K�[(.lZ>49150)
#define TRIGGER_RT				0x00000200l //! Xbox:RT�g���K�[(.lZ<16383)
#define TRIGGER_L2				0x00000400l //" PS4 :L2�g���K�[(.lRx>10000)
#define TRIGGER_R2				0x00000800l //" PS4 :R2�g���K�[(.lRy>10000)
#define BUTTON_1				0x00008000l	//	Xbox:�x�{�^��	PS4�F���^��(.rgbButtons[3]&0x80)
#define BUTTON_2				0x00004000l	//	Xbox:�w�{�^��	PS4�F�Z�{�^��(.rgbButtons[2]&0x80)
#define BUTTON_3				0x00002000l	//	Xbox:�a�{�^��	PS4�F�~�{�^��(.rgbButtons[1]&0x80)
#define BUTTON_4				0x00001000l	//	Xbox:�`�{�^��	PS4�F���{�^��(.rgbButtons[0]&0x80)
#define BUTTON_LB				0x00010000l	//	Xbox:LB�{�^��	PS4�FL1�{�^��(.rgbButtons[4]&0x80)
#define BUTTON_RB				0x00020000l	//	Xbox:RB�{�^��	PS4�FR1�{�^��(.rgbButtons[5]&0x80)
#define BUTTON_BACK				0x00040000l	//	Xbox:BACK�{�^��	PS4�FOPTION�{�^��(.rgbButtons[6]&0x80)
#define BUTTON_START			0x00080000l	//	XboxSTART�{�^��	PS4�FSHARE�{�^��(.rgbButtons[7]&0x80)
#define BUTTON_L3				0x00100000l	//! Xbox:L3�{�^��(.rgbButtons[8]&0x80)
#define BUTTON_R3				0x00200000l	//! Xbox:R3�{�^��(.rgbButtons[9]&0x80)
#define BUTTON_UP				0x00400000l	//	Xbox��PS4:�����L�[��(rgdwPOV[0] = 0)
#define BUTTON_DOWN				0x00800000l //	Xbox��PS4:�����L�[��(.rgdwPOV[0] = 18000)
#define BUTTON_LEFT				0x01000000l //	Xbox��PS4:�����L�[��(.rgdwPOV[0] = 27000)
#define BUTTON_RIGHT			0x02000000l //	Xbox��PS4:�����L�[�E(.rgdwPOV[0] = 9000)
#define GAMEPADMAX				4			//	�����ɐڑ�����W���C�p�b�h�̍ő吔���Z�b�g

class Input
{
private:
	//�L�[�{�[�h
	static LPDIRECTINPUTDEVICE8	g_pDevKeyboard;
	static BYTE					g_aKeyState[NUM_KEY_MAX];
	static BYTE					g_aKeyStateTrigger[NUM_KEY_MAX];
	static BYTE					g_aKeyStateRelease[NUM_KEY_MAX];

	//�Q�[���p�b�h
	static LPDIRECTINPUTDEVICE8	g_pGamePad[GAMEPADMAX];		// �p�b�h�f�o�C�X
	static DWORD				g_padState[GAMEPADMAX];		// �p�b�h���i�����Ή��j
	static DWORD				g_padTrigger[GAMEPADMAX];
	static int					g_padCount;					// ���o�����p�b�h�̐�
public:
	Input();
	~Input();
	//#	�L�[�{�[�h
	static bool KB_Init(HINSTANCE hInstance, HWND hWnd);	//�L�[�{�[�h�̏���������
	static void Uninit();									//�L�[�{�[�h�̏I������
	static void KB_Update();								//�L�[�{�[�h�̍X�V����
	static bool KB_IsPress(int nKey);						//�L�[�{�[�h�������Ă����
	static bool KB_IsTrigger(int nKey);						//�L�[�{�[�h���������u��
	static bool KB_IsRelease(int nKey);						//�L�[�{�[�h�𗣂����u��
	 
	//#	�Q�[���p�b�h
	static BOOL CALLBACK SearchGamePadCallback(LPDIDEVICEINSTANCE lpddi, LPVOID);
	static bool GP_Init(HINSTANCE hInstance, HWND hWnd);	//�Q�[���p�b�h�̏�����
	//static void GP_Uninit();								//�Q�[���p�b�h�̏I������
	static void GP_Update();								//�Q�[���p�b�h�̍X�V����
	static BOOL GP_IsPress(int padNo, DWORD button);		//�Q�[���p�b�h�̃{�^���������Ă����
	static BOOL GP_IsTrigger(int padNo, DWORD button);		//�Q�[���p�b�h�̃{�^�����������u��
};