#include "Game.h"
//C++�v���O�����ł�������Main�֐�!

int main(int argc, char** argv) {
	Game game; //�C���X�^���X�����B
	bool success = game.Initialize();
	if (success) {
		game.RunLoop();
	}
	game.Shutdown();
	return 0;
}