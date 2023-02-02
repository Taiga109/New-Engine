#pragma once
#include "Object3dFBX.h"
#include "ParticleManager.h"
#include "SphereCollider.h"
#include "PlayerAttack.h"

using namespace DirectX;

class player :public Object3dFBX
{
private: // �G�C���A�X
// Microsoft::WRL::���ȗ�
	template <class T> using ComPtr = Microsoft::WRL::ComPtr<T>;
	// DirectX::���ȗ�
	using XMFLOAT2 = DirectX::XMFLOAT2;
	using XMFLOAT3 = DirectX::XMFLOAT3;
	using XMFLOAT4 = DirectX::XMFLOAT4;
	using XMMATRIX = DirectX::XMMATRIX;

public:
	//3D�I�u�W�F�N�g����
	static player* Create(FbxModel* model = nullptr);

public:

	bool Initialize()override;

	void Update()override;

	void OnCollisionFBX(const CollisionInfo_FBX& info)override;

	void Draw(ID3D12GraphicsCommandList* cmdList)override;
	void Attack(Input* input);

	const bool& GetAttackFlag() {
		return AttackFlag;
	}

	const int& GetLife() {
		return playerlife;
	}
	void setLife(int life) {
		this->playerlife
			= life;
	}

private:
	int playerlife = 5;
	XMFLOAT3 pos = { 0,0,0 };
	XMVECTOR offset = { 0,0,0,0 };
	float Radius = 5;
	SphereCollider* spherecoll = nullptr;

	//PlayerAttack* P_Attack = nullptr;
	int attackcount = 0;
	bool AttackFlag = false;
	bool E_AttackFlag = false;
};

