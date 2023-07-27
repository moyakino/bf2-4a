#pragma once
#include"DxLib.h"

#define BUTTONS 16

//�X�e�B�b�N
struct Stick
{
	short x;	//�����l
	short y;	//�c���l
};

class PAD_INPUT
{
private:

	static char now_key[BUTTONS]; //����̓��̓L�[
	static char old_key[BUTTONS]; //�O��̓��̓L�[
	static XINPUT_STATE input; //�p�b�h
	static Stick r_stick; //�E�X�e�B�b�N
	static Stick l_stick; //���X�e�B�b�N
private:

	//�R���X�g���N�^
	PAD_INPUT() = default;
public:

	//�p�b�h���̍X�V
	static void UpdateKey()
	{
		// ���̓L�[�擾
		GetJoypadXInputState(DX_INPUT_KEY_PAD1, &input);

		//GetJoypadAnalogInput(*XBuf, *YBuf, DX_INPUT_KEY_PAD1);

		for (int i = 0; i < BUTTONS; i++)
		{
			old_key[i] = now_key[i];
			now_key[i] = input.Buttons[i];
		}

		//�E�X�e�B�b�N
		r_stick.x = input.ThumbRX;
		r_stick.y = input.ThumbRY;

		//���X�e�B�b�N
		l_stick.x = input.ThumbLX;
		l_stick.y = input.ThumbLY;
	}

	//�{�^���������ꂽ�u��
	static bool OnButton(int button)
	{
		bool ret = (now_key[button] == 1 && old_key[button] == 0);
		return ret;
	}

	//�{�^���������Ă��
	static bool OnPressed(int button)
	{
		bool ret = (now_key[button] == 1);
		return ret;
	}

	//�{�^���𗣂����u��
	static bool OnRelease(int button)
	{
		bool ret = (now_key[button] == 0 && old_key[button] == 1);
		return ret;
	}

	//�E�X�e�B�b�N�̎擾 X���W��Y���W�𓯎��Ɏ擾���Ă���
	static Stick GetRStick()
	{
		return r_stick;
	}

	//���X�e�B�b�N�̎擾 X���W��Y���W�𓯎��Ɏ擾���Ă���
	static Stick GetLStick()
	{
		return l_stick;
	}

	//(��)�X�e�B�b�N���|����Ă��邩�̔�������
	static short int GetStickOn()
	{
		int ret = 0; 
		if (l_stick.x == 128 || l_stick.x > 128 && l_stick.x < 2000 || l_stick.x < 128 && l_stick.x > -2000) {
			ret = FALSE;
		}
		else if (l_stick.x > 2000 && l_stick.x > 128) {
			ret = TRUE;
		}
		else if (-2000 > l_stick.x && l_stick.x < 128){
			ret = TRUE;
		}

		return ret;
	}

	//���X�e�B�b�N�̎擾 �����l
	static short int GetLStickX()
	{
		return l_stick.x;
	}

	//���X�e�B�b�N�̎擾 �c���l
	static short int GetLStickY()
	{
		return l_stick.y;
	}

	static char GetOldKey(const int i)
	{
		return old_key[i];
	}

	static char GetNowKey(const int i)
	{
		return now_key[i];
	}
};

