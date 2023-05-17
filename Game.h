#pragma once
#include "SDL.h"

class Game {
public:
	Game();
	//ゲームを初期化する
	bool Initalize();
	//ゲームオーバーまでゲームループを実行する
	void RunLoop();
	//ゲームをシャットダウンする
	void Shutdown();

private:
	//ゲームループの為のヘルパー関数群
	void ProcessInput();
	void UpdateGame();
	void GenerateOutput();

	// SDLが作るウィンドウ
	SDL_Window* mWindow;
	// ゲームの続行を指示する
	bool mIsRuuning;
};