#pragma once
#include "Object3dFBX.h"
#include "ParticleManager.h"
#include "player.h"
#include "SphereCollider.h"
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

	void Draw(ID3D12GraphicsCommandList* cmdList)override;
	void OnCollisionFBX(const CollisionInfo_FBX& info)override;


	const int& GetLife() { return Life; }
	void SetPlayer(player* Player) { this->Player = Player; }
	void SetPlayerPos(Vector3 playerpos) { this->playerpos = playerpos; }

	const bool& GetAttackFlag() {
		return EnemyAttack;
	}
private:
	Enemy_Phase phase = Enemy_Phase::move;

	int Life = 3;

	SphereCollider* E_spherecoll = nullptr;
	float Radius = 5;
	XMVECTOR offset = { 0,0,0,0 };

	Vector3 playerpos = { 0,0,0 };
	Vector3 pos = { 0,0,0 };
	float len = 0;
	Vector3 direction = { 0,0,0 };


	player* Player = nullptr;

	bool playerAttack = false;
	bool EnemyAttack = false;
	int count = 0;
	int staycount = 0;
};

