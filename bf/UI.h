#pragma once
#define R_Cnt 30

class UI {
private:
	int Number[10];			//�X�R�A�p�z��
	int NowScore;			//���݂̍��v�X�R�A�摜�p�ϐ�
	int HiScore;			//HiScore�摜�p�ϐ�
	int Stock1;				//�c�@�摜�p�ϐ�
	int Stock2;				//�c�@��1��������ƕ`���������̕ϐ��ɐ؂�ւ���
	int Phase;
	int gScore;
	int GameOver;			//GameOver�摜�p�ϐ�
	int TotalScore;
	int PosX;
	int Cnt;
	int Respawn_Cnt;
	int fpsCnt;
	int byou;
	int GameOver_Flg;
	/*int GameOver_BGM;*/
	int Respawn_Cnt;		//�c�@�̕`��̃J�E���g
	int Remaining_lives;	//Player�����񂾂��ǂ�����Ԃ�
	int Fish_PlayerHit;		//Player�����ɓ�����A���񂾂��ǂ�����Ԃ�
	int GameOver_Flg;		//GameOver�Ȃ�TRUE
	
public:	
	static int GameOver_BGM;
	UI();
	~UI();
	void Update(int Player_zanki, int Fish_Death);
	void Draw()const;
	int GetGameOver()const;

};