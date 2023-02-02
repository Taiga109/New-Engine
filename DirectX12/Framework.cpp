#include "Framework.h"

void Framework::Initialize(DirectXCommon* dxCommon, Audio* audio)
{
	input = Input::GetInstance();
	// nullptrチェック
	assert(dxCommon);
	assert(input);
	// カメラ生成
	//Dcamera = new DebugCamera(WinApp::window_width, WinApp::window_height, input);
	camera = new Camera(WinApp::window_width, WinApp::window_height);
	this->dxCommon = dxCommon;
	// デバッグテキスト初期化
	debugText.Initialize(debugTextTexNumber);

	// デバッグテキスト用テクスチャ読み込み
	if (!Sprite::LoadTexture(debugTextTexNumber, L"Resources/debugfont.png")) {
		assert(0);
		return;
	}
	
	// 背景スプライト生成
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
