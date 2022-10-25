#pragma once
#include "Object3dFBX.h"
#include "ParticleManager.h"
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



protected:

};

