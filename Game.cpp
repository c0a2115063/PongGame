#include "Game.h";

const int thickness = 15;  //�ǂ̌���
const float paddleH = 100.0f;


Game::Game() 
	:mWindow(nullptr)
	,mRenderer(nullptr)
	,mIsRunning(true)

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
	//SDL�̃O���t�B�b�N�p�R�[�h��p����B
	//�����_���[�F2D/3D��킸�O���t�B�b�N�X��`�悷��V�X�e��
	mRenderer = SDL_CreateRenderer(
		mWindow, //�쐬���郌���_���[�̕`��ΏۂƂȂ�E�B���h�E�ւ̃|�C���^
		-1,      //�ʏ��-1
		SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC
	);

	if (!mRenderer) {
		SDL_Log("�����_���[�̍쐬�Ɏ��s���܂������F%s", SDL_GetError());
	}
	mPaddlePos.x = 10.0f;
	mPaddlePos.y = 768.0f / 2.0f;
	mBallPos.x = 1024.0f / 2.0f;
	mBallPos.y = 768.0f / 2.0f;
	return true;
}

void Game::RunLoop() {
	while (mIsRunning) //�Q�[�����[�v���J��Ԃ����s���邪
	{
		ProcessInput();
		UpdateGame();
		GenerateOutput();

	}//mIsRunning��false�ɂȂ�����J��Ԃ����~�߂�
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
//1.5.4 Pong�̃I�u�W�F�N�g���Ƃ��āA�����`�̕`����������
//GenerateOutput�̒��ŕ`����s���B
void Game::GenerateOutput() {
	SDL_SetRenderDrawColor(
		mRenderer,
		0,   // R
		0,   // G
		255, // B
		255  // A
	);
	SDL_RenderClear(mRenderer); //�o�b�N�o�b�t�@�����݂̕`��F�ŃN���A����

	//SDL�œh��Ԃ��ꂽ�����`
	//�ǂ̕`�悷��
	SDL_SetRenderDrawColor(mRenderer, 255, 255, 255, 255);

	//SDL_Rect�\���̂��g���āA�T�C�Y���w�肷��K�v������B
	SDL_Rect wall{
		0,		//�������x
		0,		//�������y
		1024,	//��
		thickness//����
	};
	//�����`��`��
	SDL_RenderFillRect(mRenderer, &wall);

	//���̕�
	wall.y = 768 - thickness;
	SDL_RenderFillRect(mRenderer, &wall);

	//�E�̕�
	wall.x = 1024 - thickness;
	wall.y = 0;
	wall.w = thickness;
	wall.h = 1024;
	SDL_RenderFillRect(mRenderer, &wall);

	//SDL_Rect�͍���̍��W�Œ�`����@�p�h����`��
	SDL_Rect paddle{
		static_cast<int>(mPaddlePos.x),
		static_cast<int>(mPaddlePos.y - paddleH / 2),
		thickness,
		static_cast<int>(paddleH)
	};
	SDL_RenderFillRect(mRenderer, &paddle);


	//SDL_Rect�͍���̍��W�Œ�`����B�{�[����`��
	SDL_Rect ball{
		static_cast<int>(mBallPos.x - thickness / 2),
		static_cast<int>(mBallPos.y - thickness / 2),
		thickness,
		thickness
	};
	SDL_RenderFillRect(mRenderer, &ball);
	SDL_RenderPresent(mRenderer);//�t�����g�o�b�t�@�ƃo�b�N�o�b�t�@����������
}


void Game::Shutdown() { //Initialize�̋t���s��
	SDL_DestroyWindow(mWindow); //SDL_Window��j��
	SDL_DestroyRenderer(mRenderer);//SDL_Renderer��j��
	SDL_Quit();					//SDL���I��点��
}