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



protected:

};

