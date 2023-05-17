#include "Game.h"
//C++プログラムでも入口はMain関数!

int main(int argc, char** argv) {
	Game game; //インスタンスを作る。
	bool success = game.Initialize();
	if (success) {
		game.RunLoop();
	}
	game.Shutdown();
	return 0;
}