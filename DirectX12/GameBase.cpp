#include "GameBase.h"

#include "fbxsdk.h"
#include "FBXLoader.h"


void GameBase::Initialize()
{

	// ゲームウィンドウの作成
	win = new WinApp();
	win->CreateGameWindow();
#ifdef _DEBUG
	//デバックレイヤーをオンに
	ID3D12Debug1* debugController;
	if (SUCCEEDED(D3D12GetDebugInterface(IID_PPV_ARGS(&debugController))))
	{
		debugController->EnableDebugLayer();
		debugController->SetEnableGPUBasedValidation(TRUE);
	}
#endif // DEBUG

	//DirectX初期化処理
	dxCommon = new DirectXCommon();
	dxCommon->Initialize(win);

	//fbx初期化
	FBXLoader::GetInstance()->Initialize(dxCommon->GetDevice());
	
#pragma region 汎用機能初期化

	//入力の初期化
	input = new Input();
	input->Initialize(win->GetInstance(), win->GetHwnd());


	// スプライト静的初期化
	if (!Sprite::StaticInitialize(dxCommon->GetDevice(), WinApp::window_width, WinApp::window_height))
	{
		assert(0);
	}
	//ポストエフェクト用テクスチャの読み込み
	//Sprite::LoadTexture(100, L"Resources/white1x1.png");
	//ポストエフェクトの初期化
	postEffect = new PostEffect();
	postEffect->Initialize();
	// 3Dオブジェクト静的初期化
	Object3d::StaticInitialize(dxCommon->GetDevice());
	//ライト静的初期化
	Light::StaticInitialize(dxCommon->GetDevice());

	//オーディオ初期化
	audio = new Audio();
	if (!audio->Initialize())
	{
		assert(0);
	}
#pragma endregion 汎用機能初期化

	// ゲームシーンの初期化
	gameScene = new GameScene();
	gameScene->Initialize(dxCommon, input, audio);

}

void GameBase::Update()
{
	// メッセージ処理
	if (win->ProcessMessage())
	{
		endflag = true;
		return;
	}
#pragma region DirectX毎フレーム処理

	// 入力関連の毎フレーム処理
	input->Update();
	// ゲームシーンの毎フレーム処理
	gameScene->Update();

#pragma endregion DirectX毎フレーム処理
}

void GameBase::Draw()
{
#pragma region グラフィックスコマンド

	//レンダーテクスチャへの描画
	//postEffect->PreDrawScene(dxCommon->GetCommandList());

	//postEffect->PostDrawScene(dxCommon->GetCommandList());
	// 描画開始
	dxCommon->PreDraw();
	//ポストエフェクトの描画
	//postEffect->Draw(dxCommon->GetCommandList(),input);
	// ゲームシーンの描画

	gameScene->Draw();
	// 描画終了
	dxCommon->PostDraw();

#pragma endregion グラフィックスコマンド
}

void GameBase::Finalize()
{
// 各種解放
	safe_delete(gameScene);
	safe_delete(input);
	safe_delete(dxCommon);
	safe_delete(audio);
	safe_delete(postEffect);
	FBXLoader::GetInstance()->Finalize();
	// ゲームウィンドウの破棄
	win->TerminateGameWindow();
	safe_delete(win);

}
