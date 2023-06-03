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
	/*メンバー変数*/
	//Gameクラスを初期化する
	//bool = ゲームループを続行する否かを示す。
	bool Initialize();
	//ゲームループ実行
	void RunLoop();
	//ゲーム終了
	void Shutdown();
private:
	//ゲームループの3つのステップ
	//入力処理
	void ProcessInput();
	//ゲーム更新
	void UpdateGame();
	//出力生成
	void GenerateOutput();
	//SDLが作るウィンドウ
	SDL_Window* mWindow;
	//SDLが作るレンダラー
	SDL_Renderer* mRenderer;
	//ゲームの続行を続行する
	bool mIsRunning;


	//パドルの位置
	Vector2 mPaddlePos;
	//ボールの位置
	Vector2 mBallPos;
};