#pragma once
#include "SafeDelete.h"
#include "DirectXCommon.h"
#include <DirectXMath.h>
#include "Input.h"
#include "Sprite.h"
//#include "Object3d.h"
#include "DebugText.h"
#include <stdlib.h>
#include <time.h>
#include "Audio.h"
#include "Camera.h"
#include "DebugCamera.h"
#include "Object3dFBX.h"
#include "Light.h"

#include "3d/Object3d.h"
#include "CollisionManager.h"
#include "3d/ParticleManager.h"


using namespace DirectX;

class Framework
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
	/*Framework();

	/// <summary>
	/// デストラクタ
	/// </summary>
	~Framework();*/

	/// <summary>
	/// 初期化
	/// </summary>
	virtual void Initialize(DirectXCommon* dxCommon, Audio* audio);

	/// <summary>
	/// 毎フレーム処理
	/// </summary>
	virtual void Update();

	/// <summary>
	/// 描画
	/// </summary>
	virtual void Draw();

	virtual void Finalize();
protected: // メンバ変数
	DirectXCommon* dxCommon = nullptr;
	Input* input = nullptr;
	//DebugCamera* Dcamera = nullptr;
	Camera* camera = nullptr;
	DebugText debugText;
	Sprite* spriteBG = nullptr;
	Light* light = nullptr;
};

