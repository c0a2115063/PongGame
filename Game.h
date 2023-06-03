#pragma once
#include "SDL.h"

struct Vector2
{
	float x;
	float y;
};

class Game {
public:
	Game();
	/*�����o�[�ϐ�*/
	//Game�N���X������������
	//bool = �Q�[�����[�v�𑱍s����ۂ��������B
	bool Initialize();
	//�Q�[�����[�v���s
	void RunLoop();
	//�Q�[���I��
	void Shutdown();
private:
	//�Q�[�����[�v��3�̃X�e�b�v
	//���͏���
	void ProcessInput();
	//�Q�[���X�V
	void UpdateGame();
	//�o�͐���
	void GenerateOutput();
	//SDL�����E�B���h�E
	SDL_Window* mWindow;
	//SDL����郌���_���[
	SDL_Renderer* mRenderer;
	//�Q�[���̑��s�𑱍s����
	bool mIsRunning;


	//�p�h���̈ʒu
	Vector2 mPaddlePos;
	//�{�[���̈ʒu
	Vector2 mBallPos;
};