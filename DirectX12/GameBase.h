#pragma once
#include "WinApp.h"
#include "DirectXCommon.h"
#include "GameScene.h"
#include "Audio.h"
#include "fbxsdk.h"

#include "PostEffect.h"
#include "Light.h"
#include "Object3d.h"

class GameBase
{
public:
	void Initialize();

	void Update();

	void Draw();

	void Finalize();

	bool GetEndFlag() { return endflag; }

	bool GetDxcommon() { return dxCommon; }
private:

	bool endflag;


	//ポインタ置き場
	//FbxManager* fbxmanager = FbxManager::Create();
	WinApp* win = nullptr;
	DirectXCommon* dxCommon = nullptr;
	Input* input = nullptr;
	GameScene* gameScene = nullptr;
	Audio* audio = nullptr;
	PostEffect* postEffect = nullptr;
	//FBXLoader fbxloader;
};

