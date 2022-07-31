#include "GameScene.h"
#include "Model.h"
#include <cassert>
#include <sstream>
#include <iomanip>
#include "Collision.h"
#include "FBXLoader.h"
#include "Object3dFBX.h"
#include "imgui.h"
#include "Vector3.h"

using namespace DirectX;

GameScene::GameScene()
{
}

GameScene::~GameScene()
{
	//safe_delete(object1);
	//safe_delete(model1);
	safe_delete(light);
	safe_delete(object);
	safe_delete(model);
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
	// 3Dオブジェクトにカメラをセット
	Object3d::SetCamera(camera);
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
	//.objの名前を指定してモデルを読み込む
	model = model->CreateFromObj("sphere");
	model2 = model2->CreateFromObj("sphere");
	// 3Dオブジェクト生成
	object = Object3d::Create(model);
	object2 = Object3d::Create(model2);
	//object->SetModel(model);
	object1 = new Object3dFBX;
	object1->Initialize();
	object1->SetModel(model1);

	camera->SetTarget({ 0,0,0 });
	camera->SetDistance({ 60 });
	light = Light::Create();
	light->SetLightColor({ 1.0f,1.0f,1.0f });
	Object3dFBX::SetLight(light);
	object1->PlayAnimation();

	object->SetPosition({ -15.0f, 0.0f, 0.0f });
	object2->SetPosition({ -15.0f, -10.0f, 0.0f });
	float s = 1.0;
	object->SetScale({ s, s, s });
	object2->SetScale({ s, s, s });
	easefin = { 40,-10.0,0.0 };
	ease = { -15.0f, -10.0f, 0.0f };

}
void GameScene::Update()
{


	XMFLOAT3 obj1_pos =
		object->GetPosition();
	XMFLOAT3 obj2_pos =
		object2->GetPosition();

	if (input->PushKey(DIK_SPACE))
	{
		start = true;
	}
	if (start == true)
	{
		if (flag == false)
		{
			nowtime += 0.1;
			
			time = min(nowtime / endtime, 1);
			if (obj1_pos.x <= 40)
			{
				obj1_pos.x += a;
			}
			
			obj2_pos = easeInOutQuad(ease, easefin, time);
			//obj2_pos.x -= a;
		}

		else
		{
			//flag = true;
			///*a2 = m1 * a / m2;
			//v1 = (m1 * -0.1) / (m1 + m2);*/
			//v1 = e * a;
			//v2 = v1 + 0.3;
			//obj1_pos.x += -v1;
			//obj2_pos.x += v2;

		}
	}


	object->SetPosition(obj1_pos);
	object2->SetPosition(obj2_pos);

	camera->Update();
	light->Update();
	object->Update();
	object2->Update();

	object1->Update();

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
	Object3d::PreDraw(cmdList);

	// 3Dオブクジェクトの描画
	// 
	//object1->Draw(cmdList);
	object->Draw();

	object2->Draw();
	/// <summary>
	/// ここに3Dオブジェクトの描画処理を追加できる
	/// </summary>
	//imgui 描画前処理

	ImGui::Begin("Rendering Test Menu");
	ImGui::SetWindowPos(ImVec2(0, 0));
	/*ImGui::SetWindowSize(
		ImVec2(500,200), ImGuiCond_::ImGuiCond_FirstUseEver
	);*/
	ImGui::SetWindowSize(ImVec2(500, 200));
	ImGui::End();


	// 3Dオブジェクト描画後処理
	Object3d::PostDraw();
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

