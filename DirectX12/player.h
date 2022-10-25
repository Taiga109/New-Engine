#pragma once
#include "Object3dFBX.h"
#include "ParticleManager.h"
using namespace DirectX;

class player :public Object3dFBX
{
private: // エイリアス
// Microsoft::WRL::を省略
	template <class T> using ComPtr = Microsoft::WRL::ComPtr<T>;
	// DirectX::を省略
	using XMFLOAT2 = DirectX::XMFLOAT2;
	using XMFLOAT3 = DirectX::XMFLOAT3;
	using XMFLOAT4 = DirectX::XMFLOAT4;
	using XMMATRIX = DirectX::XMMATRIX;

public:
	//3Dオブジェクト生成
	static player* Create(FbxModel* model = nullptr);

public:

	bool Initialize()override;
	
	void Update()override;

	void OnCollisionFBX(const CollisionInfo_FBX& info)override;

	
	//// モデルスケールの取得
	//const XMFLOAT3& GetScale() { return scale; }
	//// モデルスケールの設定
	//void SetScale(XMFLOAT3 scale) { this->scale = scale; }
	// 回転角の取得
	//const XMFLOAT3& GetRotation() { return rotation; }
	//
	//
	//// 座標の設定
	//void SetPosition(XMFLOAT3 position)override { this->position = position; }

protected:

	//XMFLOAT3 pos = { 0,0,0 };
	//XMFLOAT3 scale = { 0.5,0.5,0.5 };
	////XMFLOAT3 rotation = { 0,0,0 };
	////移動用
	//float moveSpead = 0.1;
	//
	////スタート位置
	//XMFLOAT3 startPos = { 0,0,0 };
};

