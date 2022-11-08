#pragma once
#include "player.h"
#include "ParticleManager.h"
#include "SphereCollider.h"
#include "Object3dFBX.h"

using namespace DirectX;

class PlayerAttack :public Object3dFBX
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

	void Initialize(float Radius);

	void OnCollisionFBX(const CollisionInfo_FBX& info);

	void SetAttackFlag(bool flag) {
		this->Attackflag;
	}


private:
	bool Attackflag = false;
};

