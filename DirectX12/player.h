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
private: // �G�C���A�X
// Microsoft::WRL::���ȗ�
	template <class T> using ComPtr = Microsoft::WRL::ComPtr<T>;
	// DirectX::���ȗ�
	using XMFLOAT2 = DirectX::XMFLOAT2;
	using XMFLOAT3 = DirectX::XMFLOAT3;
	using XMFLOAT4 = DirectX::XMFLOAT4;
	using XMMATRIX = DirectX::XMMATRIX;

public:

	void Initialize(Object3dFBX* fbx, FbxModel* model);

	void move(Input* input, Object3dFBX* fbx);

	void update(Object3dFBX* fbx, Input* input);

	void Draw(Object3dFBX* fbx, ID3D12GraphicsCommandList* cmdlist);
	// ���f���X�P�[���̎擾
	const XMFLOAT3& GetScale() { return scale; }
	// ���f���X�P�[���̐ݒ�
	void SetScale(XMFLOAT3 scale) { this->scale = scale; }
	// ��]�p�̎擾
	const XMFLOAT3& GetRotation() { return rotation; }
	// ��]�p�̐ݒ�
	void SetRotation(XMFLOAT3 rotation) { this->rotation = rotation; }
	// ���W�̎擾
	const XMFLOAT3& GetPosition() { return pos; }
	// ���W�̐ݒ�
	void SetPosition(XMFLOAT3 position) { this->pos = pos; }

protected:

	XMFLOAT3 pos = { 0,0,0 };
	XMFLOAT3 scale = { 0.5,0.5,0.5 };
	XMFLOAT3 rotation = { 0,0,0 };
	//�ړ��p
	float moveSpead = 0.1;

	//�X�^�[�g�ʒu
	XMFLOAT3 startPos = { 0,0,0 };
};

