#pragma once
class Stage
{
private:
	int StageFoot[8];
	int StageLand_R;
	int StageLand_L;
	int StageSea;


	int StageSample1;
	int StageSample2;
	int StageSample3;
	int StageSample4;
	int StageSample5;


	int X_Btn;

	int Snum;

	int sFps;

public:
	//�R���X�g���N�^
	Stage();

	//�f�X�g���N�^
	~Stage();

	//�`��ȊO�̍X�V����������
	void Update();

	//�`�揈��
	void Draw() const;

};