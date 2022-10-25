#pragma once

#include "SafeDelete.h"
#include "DirectXCommon.h"
#include <DirectXMath.h>
#include "Input.h"
#include "Sprite.h"
//#include "Object3d.h"
#include "DebugText.h"
#include "CollisionPrimitive.h"
#include <stdlib.h>
#include <time.h>
#include "Audio.h"
#include "Camera.h"
#include "DebugCamera.h"
#include "Object3dFBX.h"
#include "Light.h"
#include "player.h"
#include "3d/Object3d.h"
#include "CollisionManager.h"
#include "3d/ParticleManager.h"

//#include "Light.h"
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
	void Initialize(DirectXCommon* dxCommon, Input* input, Audio* audio);

	/// <summary>
	/// 毎フレーム処理
	/// </summary>
	void Update();

	/// <summary>
	/// 描画
	/// </summary>
	void Draw();

	void move(Input* input);

private: // メンバ変数
	DirectXCommon* dxCommon = nullptr;
	Input* input = nullptr;
	//DebugCamera* Dcamera = nullptr;
	Camera* camera = nullptr;
	DebugText debugText;
	Sprite* spriteBG = nullptr;
	Light* light = nullptr;
	FbxModel* model1 = nullptr;
	FbxModel* enemymodel = nullptr;
	player* object1 = nullptr;
	Object3dFBX* enemy = nullptr;

	Object3dFBX* sphere_fbx = nullptr;
	FbxModel* sphere_fbxmodel = nullptr;

	Model* dome = nullptr;
	Object3d* domeobj = nullptr;
	Model* groundmodel = nullptr;
	Object3d* groundobj = nullptr;

	Model* spheremodel = nullptr;
	Object3d* sphereobj = nullptr;

	CollisionManager* collisionmaneger = nullptr;
	ParticleManager* particleMan = nullptr;
	/// <summary>
	/// ゲームシーン用
	/// </summary>

	XMFLOAT3 scale = { 0.1,0.1,0.1 };
	XMFLOAT3 pos = {0,0,0};
	XMFLOAT3 enescale = { 50,50,50 };
	bool atackani = false;
	bool moveani = false;
	int animeNum = 4;
	int beforanimeNun = animeNum;
	int count = 0;
	int Endtime = 120;
	
	
};

