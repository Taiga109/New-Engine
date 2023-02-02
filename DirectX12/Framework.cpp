#include "Framework.h"

void Framework::Initialize(DirectXCommon* dxCommon, Audio* audio)
{
	input = Input::GetInstance();
	// nullptr�`�F�b�N
	assert(dxCommon);
	assert(input);
	// �J��������
	//Dcamera = new DebugCamera(WinApp::window_width, WinApp::window_height, input);
	camera = new Camera(WinApp::window_width, WinApp::window_height);
	this->dxCommon = dxCommon;
	// �f�o�b�O�e�L�X�g������
	debugText.Initialize(debugTextTexNumber);

	// �f�o�b�O�e�L�X�g�p�e�N�X�`���ǂݍ���
	if (!Sprite::LoadTexture(debugTextTexNumber, L"Resources/debugfont.png")) {
		assert(0);
		return;
	}
	
	// �w�i�X�v���C�g����
	spriteBG = Sprite::Create(1, { 0.0f,0.0f });
}

void Framework::Update()
{
	
}

void Framework::Draw()
{

}

void Framework::Finalize()
{
	
}
