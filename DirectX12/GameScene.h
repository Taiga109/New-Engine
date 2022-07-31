#pragma once

#include "SafeDelete.h"
#include "DirectXCommon.h"
#include <DirectXMath.h>
#include "Input.h"
#include "Sprite.h"
#include "Object3d.h"
#include "DebugText.h"
#include "CollisionPrimitive.h"
#include <stdlib.h>
#include <time.h>
#include "Audio.h"
#include "Camera.h"
#include "DebugCamera.h"
#include "Object3dFBX.h"
#include "Light.h"
#include "Model.h"

/// <summary>
/// ゲームシーン
/// </summary>
class GameScene
{
private: // エイリアス
	// Microsoft::WRL::を省略
	template <class T> using ComPtr = Microsoft::WRL::ComPtr<T>;
	// DirectX::を省略
	using XMFLOAT2 = DirectX::XMFLOAT2;
	using XMFLOAT3 = DirectX::XMFLOAT3;
	using XMFLOAT4 = DirectX::XMFLOAT4;
	using XMMATRIX = DirectX::XMMATRIX;

private: // 静的メンバ変数
	static const int debugTextTexNumber = 0;

public: // メンバ関数

	/// <summary>
	/// コンストクラタ
	/// </summary>
	GameScene();

	/// <summary>
	/// デストラクタ
	/// </summary>
	~GameScene();

	/// <summary>
	/// 初期化
	/// </summary>
	void Initialize(DirectXCommon* dxCommon, Input* input,Audio* audio);

	/// <summary>
	/// 毎フレーム処理
	/// </summary>
	void Update();

	/// <summary>
	/// 描画
	/// </summary>
	void Draw();

private: // メンバ変数
	DirectXCommon* dxCommon = nullptr;
	Input* input = nullptr;
	DebugCamera* camera = nullptr;
	DebugText debugText;
	Sprite* spriteBG = nullptr;
	Light* light = nullptr;
	FbxModel* model1 = nullptr;
	Object3dFBX* object1 = nullptr;
	Object3d* object = nullptr;
	Model* model = nullptr;

	Object3d* object2 = nullptr;
	Model* model2 = nullptr;
	/// <summary>
	/// ゲームシーン用
	/// </summary>
	
	XMFLOAT3 ease;
	XMFLOAT3 easefin;
	float nowtime = 0;
	float endtime = 20;
	float time = 0;
	float m1 = 5;
	float m2 = 10;
	float a = 0.5;
	float v1 = 0;
	float v2 = 0;
	bool flag = false;
	float a2 = 0.1;
	bool start = false;
	float e = 0.4;
};

