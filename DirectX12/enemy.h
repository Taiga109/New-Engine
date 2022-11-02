#pragma once
#include "Object3dFBX.h"
#include "ParticleManager.h"
#include "player.h"

using namespace DirectX;

class Enemy :public Object3dFBX
{
private: // エイリアス
// Microsoft::WRL::を省略
	template <class T> using ComPtr = Microsoft::WRL::ComPtr<T>;
	// DirectX::を省略
	using XMFLOAT2 = DirectX::XMFLOAT2;
	using XMFLOAT3 = DirectX::XMFLOAT3;
	using XMFLOAT4 = DirectX::XMFLOAT4;
	using XMMATRIX = DirectX::XMMATRIX;

	enum class Enemy_Phase
	{
		move,
		attack,
		idol,
	};

public:
	//3Dオブジェクト生成
	static Enemy* Create(FbxModel* model = nullptr);

public:

	bool Initialize()override;

	void Update()override;

	void OnCollisionFBX(const CollisionInfo_FBX& info)override;

	const int& GetLife() { return Life; }

private:

	int Life = 3;

	XMFLOAT3 pos = { 0,0,0 };
	bool turn = false;;
	Enemy_Phase phase= Enemy_Phase::move;
	
	player* Player;
	bool CheckFlag = false;
};

