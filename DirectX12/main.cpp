﻿#include "WinApp.h"
#include "DirectXCommon.h"
#include "GameScene.h"
#include "Audio.h"
#include "fbxsdk.h"
#include "FBXLoader.h"
#include "PostEffect.h"
#include "Light.h"

//# Windowsアプリでのエントリーポイント(main関数)
int WINAPI WinMain(HINSTANCE, HINSTANCE, LPSTR, int)
{
	//ポインタ置き場
	//FbxManager* fbxmanager = FbxManager::Create();
	WinApp* win = nullptr;
	DirectXCommon* dxCommon = nullptr;
	Input* input = nullptr;
	GameScene* gameScene = nullptr;
	Audio* audio = nullptr;
	PostEffect* postEffect = nullptr;
	// ゲームウィンドウの作成
	win = new WinApp();
	win->CreateGameWindow();
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
		return 1;
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
		return 1;
	}
#pragma endregion 汎用機能初期化
	
	// ゲームシーンの初期化
	gameScene = new GameScene();
	gameScene->Initialize(dxCommon, input,audio);
	
	while (true)  // ゲームループ
	{
		// メッセージ処理
		if (win->ProcessMessage())
		{
			break;
		}

#pragma region DirectX毎フレーム処理

		// 入力関連の毎フレーム処理
		input->Update();
		// ゲームシーンの毎フレーム処理
		gameScene->Update();

#pragma endregion DirectX毎フレーム処理

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

	//解放
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

	return 0;
}
