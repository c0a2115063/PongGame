#include "Game.h";

Game::Game() 
	:mWindow(nullptr)
{
}

bool Game::Initialize() {
	//����������=true,���s=false
	//SDL_Init()�֐��ŏ���������K�v
	int sdlResult = SDL_Init(SDL_INIT_VIDEO); //SDL_INIT_VIDEO:�r�f�I�T�u�V�X�e��
	if (sdlResult != 0) {
		SDL_Log("SDL���������ł��܂���F %s", SDL_GetError());
		return false;
	}

	//�E�B���h�E�����B
	mWindow = SDL_CreateWindow(
		"Pong Game Chapter1", //�E�B���h�E�̃^�C�g��
		100, //�E�B���h�E�������x���W
		100, //�E�B���h�E�������y���W
		1024, //�E�B���h�E�̕�
		768,  //�E�B���h�E�̍���
		0    //�t���O(�ݒ肵�Ȃ�����0)
	);
	//SDL_CreateWindow�ł��Ăяo���������������Ɗm�F����
	if (!mWindow) {
		SDL_Log("�E�B���h�E�̍쐬�Ɏ��s���܂����F%s", SDL_GetError());
		return false;
	}
}

void Game::RunLoop() {
	while (mIsRunning) //�Q�[�����[�v���J��Ԃ����s���邪
	{
		ProcessInput();
		UpdateGame();
		GenerateOutput();

	}//mIsRunning��false�ɂȂ�����J��Ԃ����~�߂�
}


void Game::Shutdown() { //Initialize�̋t���s��
	SDL_DestroyWindow(mWindow); //SDL_Window��j��
	SDL_Quit();					//SDL���I��点��
}


void Game::ProcessInput() {
	SDL_Event event;
	//�L���[�ɃC�x���g������ΌJ��Ԃ�
	while (SDL_PollEvent(&event)) {
		switch (event.type)
		{
		case SDL_QUIT:
			mIsRunning = false;
			break;
		}
	}
	//SDL_GetKeyboardState�ŃL�[�{�[�h�S�̂̏�Ԃ�c������Ƃ������@������B
	//�L�[�{�[�h�̌��݂̏�Ԃ��i�[���ꂽ�z��ւ̃|�C���g��Ԃ��B
	const Uint8* state = SDL_GetKeyboardState(NULL);

	//�L�[�ɑΉ�����SDL_SCANCODE�񋓌^�̒l���g��
	if (state[SDL_SCANCODE_ESCAPE]) {
		mIsRunning = false;
	}
}

void Game::UpdateGame() {

}

void Game::GenerateOutput() {

}