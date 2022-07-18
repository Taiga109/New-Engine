#include "GameScene.h"
#include "Model.h"
#include <cassert>
#include <sstream>
#include <iomanip>
#include "Collision.h"
#include "FBXLoader.h"
#include "Object3dFBX.h"
#include "imgui.h"


using namespace DirectX;

GameScene::GameScene()
{
}

GameScene::~GameScene()
{
	//safe_delete(object1);
	//safe_delete(model1);
	safe_delete(light);
}

void GameScene::Initialize(DirectXCommon* dxCommon, Input* input, Audio* audio)
{
	// nullptrチェック
	assert(dxCommon);
	assert(input);
	// カメラ生成
	camera = new DebugCamera(WinApp::window_width, WinApp::window_height, input);
	this->dxCommon = dxCommon;
	this->input = input;

	Object3dFBX::SetDevice(dxCommon->GetDevice());
	Object3dFBX::SetCamera(camera);
	Object3dFBX::CreateGraphicsPipeline();
	// デバッグテキスト用テクスチャ読み込み
	if (!Sprite::LoadTexture(debugTextTexNumber, L"Resources/debugfont.png")) {
		assert(0);
		return;
	}
	// デバッグテキスト初期化
	debugText.Initialize(debugTextTexNumber);

	// 前景スプライト生成

	// テクスチャ読み込み
	/*if (!Sprite::LoadTexture(3, L"Resources/ui.png")) {
		assert(0);
		return;
	}*/

	// テクスチャ読み込み
	if (!Sprite::LoadTexture(1, L"Resources/background.png")) {
		assert(0);
		return;
	}
	// 背景スプライト生成
	spriteBG = Sprite::Create(1, { 0.0f,0.0f });
	model1 = FBXLoader::GetInstance()->LoadModelFromFile("boneTest");
	// 3Dオブジェクト生成
	object1 = new Object3dFBX;
	object1->Initialize();
	object1->SetModel(model1);

	camera->SetTarget({ 0,0,0 });
	camera->SetDistance({ 20.0f});
	light = Light::Create();
	light->SetLightColor({ 1.0f,1.0f,1.0f });
	Object3dFBX::SetLight(light);
	object1->PlayAnimation();
	
	
}
void GameScene::Update()
{
	light->Update();
	
	object1->Update();
	camera->Update();
	{
		static XMVECTOR lightDir = { 0,1,5,0 };

		light->SetLightDir(lightDir);
	}
}

void GameScene::Draw()
{
	// コマンドリストの取得
	ID3D12GraphicsCommandList* cmdList = dxCommon->GetCommandList();
	
#pragma region 背景スプライト描画
	//// 背景スプライト描画前処理
	//Sprite::PreDraw(cmdList);
	//// 背景スプライト描画
	//spriteBG->Draw();
	///// <summary>
	///// ここに背景スプライトの描画処理を追加できる
	///// </summary>

	//// スプライト描画後処理
	//Sprite::PostDraw();
	//// 深度バッファクリア
	dxCommon->ClearDepthBuffer();
#pragma endregion

#pragma region 3Dオブジェクト描画
	// 3Dオブジェクト描画前処理
	//Object3d::PreDraw(cmdList);

	// 3Dオブクジェクトの描画
	object1->Draw(cmdList);
	/// <summary>
	/// ここに3Dオブジェクトの描画処理を追加できる
	/// </summary>
	//imgui 描画前処理
	/*ImGui_ImplDX12_NewFrame();
	ImGui_ImplWin32_NewFrame();
	ImGui::NewFrame();
	ImGui::Begin("Rendering Test Menu");
	ImGui::SetWindowSize(
		ImVec2(600, 800), ImGuiCond_::ImGuiCond_FirstUseEver
	);
	ImGui::End();
	ImGui::Render();
	cmdList->SetDescriptorHeaps(
		1, dxCommon->GetHeapforImgui().GetAddressOf());
	ImGui_ImplDX12_RenderDrawData(ImGui::GetDrawData(), cmdList);*/
	// 3Dオブジェクト描画後処理
	//Object3d::PostDraw();
#pragma endregion

#pragma region 前景スプライト描画
	// 前景スプライト描画前処理
	Sprite::PreDraw(cmdList);

	/// <summary>
	/// ここに前景スプライトの描画処理を追加できる
	/// </summary>

	//// 描画
	//sprite1->Draw();
	//sprite2->Draw();

	// デバッグテキストの描画
	debugText.DrawAll(cmdList);

	
	// スプライト描画後処理
	Sprite::PostDraw();
#pragma endregion
}

