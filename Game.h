#pragma once
#include "SDL.h"

class Game {
public:
	Game();
	//�Q�[��������������
	bool Initalize();
	//�Q�[���I�[�o�[�܂ŃQ�[�����[�v�����s����
	void RunLoop();
	//�Q�[�����V���b�g�_�E������
	void Shutdown();

private:
	//�Q�[�����[�v�ׂ̈̃w���p�[�֐��Q
	void ProcessInput();
	void UpdateGame();
	void GenerateOutput();

	// SDL�����E�B���h�E
	SDL_Window* mWindow;
	// �Q�[���̑��s���w������
	bool mIsRuuning;
};