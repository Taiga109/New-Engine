#include "GameScene.h"
#include <cassert>
#include <sstream>
#include <iomanip>
#include "Collision.h"
#include "FBXLoader.h"
#include "Object3dFBX.h"
#include "imgui.h"


//skydome

using namespace DirectX;

GameScene::GameScene()
{
}

GameScene::~GameScene()
{
	//safe_delete(object1);
	//safe_delete(model1);
	safe_delete(dome);
	safe_delete(domeobj);
	safe_delete(light);
}

void GameScene::Initialize(DirectXCommon* dxCommon, Input* input, Audio* audio)
{
	// nullptrチェック
	assert(dxCommon);
	assert(input);
	// カメラ生成
	//Dcamera = new DebugCamera(WinApp::window_width, WinApp::window_height, input);
	camera = new Camera(WinApp::window_width, WinApp::window_height);
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
	model1 = FBXLoader::GetInstance()->LoadModelFromFile("model4");
	//enemymodel = FBXLoader::GetInstance()->LoadModelFromFile("robo_6");

	// 3Dオブジェクト生成
	object1 = new Object3dFBX;
	object1->Initialize();
	object1->SetModel(model1);
	enemy = new Object3dFBX;
	enemy->Initialize();
	//enemy->SetModel(enemymodel);

	dome = dome->CreateFromObj("skydome",false);
	domeobj = Object3d::Create(dome);
	domeobj->SetCamera(camera);
	domeobj->SetLight(light);

	groundmodel = groundmodel->CreateFromObj("ground",false);
	groundobj = Object3d::Create(groundmodel);
	groundobj->SetCamera(camera);
	groundobj->SetLight(light);
	//player->Initialize(object1, model1);

	//camera->SetDistance({ 50.0f });
	//camera->SetEye({ 0,60,-70 });
	camera->SetTarget({ 0,1,0 });
	camera->SetUp({ 0,1,0 });
	light = Light::Create();
	light->SetLightColor({ 1.0f,1.0f,1.0f });
	Object3dFBX::SetLight(light);
	object1->iniAnimation();
	object1->PlayAnimation(animeNum);
	//0 パンチ1アッパー　
	//2横蹴り3蹴り
	//4 idol
	//5手を振る
	//6歩き
	domeobj->SetPosition({ 0,0,0 });
	//domeobj->SetScale({ 1,1,1 });
	object1->SetPosition({ 0,0,-20 });
	object1->SetScale(scale);
	enemy->SetScale(scale);
	pos = object1->GetPos();
	camera->SetEye({ pos });
}
void GameScene::Update()
{
	//ブランチ

	groundobj->Update();
	domeobj->Update();
	light->Update();
	//player->update(object1, input);
	object1->Update();
	//enemy->Update();
	camera->Update();
	pos = object1->GetPos();
	camera->SetEye({ pos.x + 5,pos.y + 20,pos.z - 20 });
	camera->SetTarget({ pos.x + 5,pos.y + 15,pos.z + 10 });
	if (input->PushKey(DIK_D) || input->PushKey(DIK_A)
		|| input->PushKey(DIK_S) || input->PushKey(DIK_W))
	{
		if (input->PushKey(DIK_D))
		{
			if (input->PushKey(DIK_W))
			{
				object1->SetRotation({ 0,45,0 });
			}
			else if (input->PushKey(DIK_S))
			{
				object1->SetRotation({ 0,135,0 });
			}
			else
			{
				object1->SetRotation({ 0,90,0 });
			}

		}
		else if (input->PushKey(DIK_A))
		{
			if (input->PushKey(DIK_W))
			{
				object1->SetRotation({ 0,-45,0 });
			}
			else if (input->PushKey(DIK_S))
			{
				object1->SetRotation({ 0,-135,0 });
			}
			else
			{
				object1->SetRotation({ 0,-90,0 });
			}
		}
		else if (input->PushKey(DIK_W))
		{
			object1->SetRotation({ 0,0,0 });
		}
		else if (input->PushKey(DIK_S))
		{
			object1->SetRotation({ 0,180,0 });
		}

		move(input);
	}
	//移動終わったら変更
	else if (moveani == true && animeNum == 6)
	{
		moveani = false;

		animeNum = 4;
	}
	//移動中なら変える
	if (moveani)
	{
		animeNum = 6;
	}

	//攻撃１
	{
		if (input->TriggerMouse(Left) && atackani == false)
		{
			atackani = true;
			animeNum = 0;
		}
		else if (atackani == true && input->TriggerMouse(Left))
		{
			if (beforanimeNun == 0)
			{
				animeNum = 1;
				count = 0;
			}
			else if (beforanimeNun == 1)
			{
				animeNum = 0;
				count = 0;
			}

		}
		else if (atackani == true && count > Endtime)
		{
			atackani = false;
			count = 0;
			animeNum = 4;
		}
		if (atackani == true)
		{
			count++;
		}
	}
	//攻撃２
	{
		if (input->TriggerMouse(Right) && atackani == false)
		{
			atackani = true;
			animeNum = 2;
		}
		else if (atackani == true && input->TriggerMouse(Right))
		{
			if (beforanimeNun == 2)
			{
				animeNum = 3;
				count = 0;
			}
			else if (beforanimeNun == 3)
			{
				animeNum = 2;
				count = 0;
			}

		}
	}
	//アニメーション番号変更
	if (beforanimeNun != animeNum)
	{
		//object1->PlayAnimation(animeNum);
		object1->AnimetionBlend(beforanimeNun, animeNum);
		beforanimeNun = animeNum;
	}
	object1->SetPosition(pos);
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
	domeobj->Draw();
	//object1->Draw(cmdList);
	//enemy->Draw(cmdList);
	groundobj->Draw();
	//player->Draw(object1,cmdList);
	/// <summary>
	/// ここに3Dオブジェクトの描画処理を追加できる
	/// </summary>
	//imgui 描画前処理

	//ImGui::Begin("Rendering Test Menu");
	//ImGui::SetWindowPos(ImVec2(0, 0));
	///*ImGui::SetWindowSize(
	//	ImVec2(500,200), ImGuiCond_::ImGuiCond_FirstUseEver
	//);*/
	//ImGui::SetWindowSize(ImVec2(500, 200));
	//ImGui::End();


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

void GameScene::move(Input* input)
{
	moveani = true;
	float moveSpead = 0.1;
	if (input->PushKey(DIK_A))	//左
	{
		pos.x -= moveSpead;
	}
	else if (input->PushKey(DIK_D))	//右
	{
		pos.x += moveSpead;
	}
	if (input->PushKey(DIK_S))	//後ろ
	{
		pos.z -= moveSpead;
	}
	else if (input->PushKey(DIK_W))	//前
	{
		pos.z += moveSpead;
	}
}

