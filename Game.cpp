#include "Game.h";

Game::Game() 
	:mWindow(nullptr)
	,mRenderer(nullptr)
	,mIsRunning(true)

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
	//SDLのグラフィック用コードを用いる。
	//レンダラー：2D/3D問わずグラフィックスを描画するシステム
	mRenderer = SDL_CreateRenderer(
		mWindow, //作成するレンダラーの描画対象となるウィンドウへのポインタ
		-1,      //通常は-1
		SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC
	);

	if (!mRenderer) {
		SDL_Log("レンダラーの作成に失敗しました￥：%s", SDL_GetError());
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
	SDL_DestroyRenderer(mRenderer);//SDL_Rendererを破棄
	SDL_Quit();					//SDLを終わらせる
}


void Game::ProcessInput() {
	SDL_Event event;
	//キューにイベントがあれば繰り返す
	while (SDL_PollEvent(&event)) {
		switch (event.type)
		{
		case SDL_QUIT:
			mIsRunning = false;
			break;
		}
	}
	//SDL_GetKeyboardStateでキーボード全体の状態を把握するという方法がある。
	//キーボードの現在の状態が格納された配列へのポイントを返す。
	const Uint8* state = SDL_GetKeyboardState(NULL);

	//キーに対応するSDL_SCANCODE列挙型の値を使う
	if (state[SDL_SCANCODE_ESCAPE]) {
		mIsRunning = false;
	}
}

void Game::UpdateGame() {

}

void Game::GenerateOutput() {
	SDL_SetRenderDrawColor(
		mRenderer,
		0,   // R
		0,   // G
		255, // B
		255  // A
	);
	SDL_RenderClear(mRenderer); //バックバッファを現在の描画色でクリアする
	SDL_RenderPresent(mRenderer);//フロントバッファとバックバッファを交換する
}