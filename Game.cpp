#include "Game.h";

Game::Game() 
	:mWindow(nullptr)
{
}

bool Game::Initialize() {
	//初期化成功=true,失敗=false
	//SDL_Init()関数で初期化する必要
	int sdlResult = SDL_Init(SDL_INIT_VIDEO); //SDL_INIT_VIDEO:ビデオサブシステム
	if (sdlResult != 0) {
		SDL_Log("SDLを初期化できません： %s", SDL_GetError());
		return false;
	}

	//ウィンドウを作る。
	mWindow = SDL_CreateWindow(
		"Pong Game Chapter1", //ウィンドウのタイトル
		100, //ウィンドウ左上隅のx座標
		100, //ウィンドウ左上隅のy座標
		1024, //ウィンドウの幅
		768,  //ウィンドウの高さ
		0    //フラグ(設定しない時は0)
	);
	//SDL_CreateWindowでも呼び出しが成功したこと確認する
	if (!mWindow) {
		SDL_Log("ウィンドウの作成に失敗しました：%s", SDL_GetError());
		return false;
	}
}

void Game::RunLoop() {
	while (mIsRunning) //ゲームループを繰り返し実行するが
	{
		ProcessInput();
		UpdateGame();
		GenerateOutput();
	}//mIsRunningがfalseになったら繰り返しを止める
}


void Game::Shutdown() { //Initializeの逆を行う
	SDL_DestroyWindow(mWindow); //SDL_Windowを破棄
	SDL_Quit();					//SDLを終わらせる
}


void Game::ProcessInput() {

}

void Game::UpdateGame() {

}

void Game::GenerateOutput() {

}