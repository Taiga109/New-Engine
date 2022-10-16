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

	
	//// ���f���X�P�[���̎擾
	//const XMFLOAT3& GetScale() { return scale; }
	//// ���f���X�P�[���̐ݒ�
	//void SetScale(XMFLOAT3 scale) { this->scale = scale; }
	// ��]�p�̎擾
	//const XMFLOAT3& GetRotation() { return rotation; }
	//
	//
	//// ���W�̐ݒ�
	//void SetPosition(XMFLOAT3 position)override { this->position = position; }

protected:

	//XMFLOAT3 pos = { 0,0,0 };
	//XMFLOAT3 scale = { 0.5,0.5,0.5 };
	////XMFLOAT3 rotation = { 0,0,0 };
	////�ړ��p
	//float moveSpead = 0.1;
	//
	////�X�^�[�g�ʒu
	//XMFLOAT3 startPos = { 0,0,0 };
};

