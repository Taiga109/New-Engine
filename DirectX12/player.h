#pragma once
#include "Input.h"
#include "DirectXCommon.h"
#include <stdlib.h>
#include <time.h>
#include "Vector3.h"
#include "Object3dFBX.h"
#include <DirectXMath.h>
#include "FbxModel.h"
#include "DirectXCommon.h"

class player
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

	void Initialize(Object3dFBX* fbx, FbxModel* model);

	void move(Input* input, Object3dFBX* fbx);

	void update(Object3dFBX* fbx, Input* input);

	void Draw(Object3dFBX* fbx, ID3D12GraphicsCommandList* cmdlist);
	// モデルスケールの取得
	const XMFLOAT3& GetScale() { return scale; }
	// モデルスケールの設定
	void SetScale(XMFLOAT3 scale) { this->scale = scale; }
	// 回転角の取得
	const XMFLOAT3& GetRotation() { return rotation; }
	// 回転角の設定
	void SetRotation(XMFLOAT3 rotation) { this->rotation = rotation; }
	// 座標の取得
	const XMFLOAT3& GetPosition() { return pos; }
	// 座標の設定
	void SetPosition(XMFLOAT3 position) { this->pos = pos; }

protected:

	XMFLOAT3 pos = { 0,0,0 };
	XMFLOAT3 scale = { 0.5,0.5,0.5 };
	XMFLOAT3 rotation = { 0,0,0 };
	//移動用
	float moveSpead = 0.1;

	//スタート位置
	XMFLOAT3 startPos = { 0,0,0 };
};

