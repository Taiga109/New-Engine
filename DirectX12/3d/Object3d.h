#pragma once

#include <Windows.h>
#include <wrl.h>
#include <d3d12.h>
#include <DirectXMath.h>
#include <d3dx12.h>

#include "Model.h"
#include "Light.h"
#include "Camera.h"
#include "CollisionInfo.h"
class BaseCollider;

class Object3d
{
private: // �G�C���A�X
// Microsoft::WRL::���ȗ�
	template <class T> using ComPtr = Microsoft::WRL::ComPtr<T>;
	// DirectX::���ȗ�
	using XMFLOAT2 = DirectX::XMFLOAT2;
	using XMFLOAT3 = DirectX::XMFLOAT3;
	using XMFLOAT4 = DirectX::XMFLOAT4;
	using XMMATRIX = DirectX::XMMATRIX;

public: // �T�u�N���X

	//�p�C�v���C���Z�b�g
	struct PipelineSet
	{
		// ���[�g�V�O�l�`��
		ComPtr<ID3D12RootSignature> rootsignature;
		// �p�C�v���C���X�e�[�g�I�u�W�F�N�g
		ComPtr<ID3D12PipelineState> pipelinestate;
	};

	// �萔�o�b�t�@�p�f�[�^�\����B0
	struct ConstBufferDataB0
	{
		XMMATRIX viewproj;    // �r���[�v���W�F�N�V�����s��
		XMMATRIX world; // ���[���h�s��
		XMFLOAT3 cameraPos;//�J�������W
	};
	static Light* light;
private: // �萔

public: // �ÓI�����o�֐�
	// �ÓI������
	static void StaticInitialize(ID3D12Device* device, Camera* camera = nullptr);
	//�O���t�B�b�N�p�C�v���C���̐���
	static void CreateGraphicsPipeline();
	// �`��O����
	static void PreDraw(ID3D12GraphicsCommandList* cmdList);
	// �`��㏈��
	static void PostDraw();
	// 3D�I�u�W�F�N�g����
	static Object3d* Create(Model* model);
	//�J�����Z�b�g
	static void SetCamera(Camera* camera) {
		Object3d::camera = camera;
	}

	static void SetLight(Light* light) {
		Object3d::light = light;
	}

private: // �ÓI�����o�ϐ�
	// �f�o�C�X
	static ID3D12Device* device;
	// �R�}���h���X�g
	static ID3D12GraphicsCommandList* cmdList;
	//�p�C�v���C��
	static PipelineSet pipelineSet;
	//�J����
	static Camera* camera;

private:// �ÓI�����o�֐�

public: // �����o�֐�
	//�R���X�g���N�^
	Object3d() = default;
	//�f�X�g���N�^
	virtual ~Object3d();

	virtual bool Initialize();
	// ���t���[������
	virtual void Update();
	// �`��
	virtual void Draw();
	// ���f���X�P�[���̎擾
	const XMFLOAT3& GetScale() { return scale; }
	// ���f���X�P�[���̐ݒ�
	void SetScale(XMFLOAT3 scale) { this->scale = scale; }
	// ��]�p�̎擾
	const XMFLOAT3& GetRotation() { return rotation; }
	// ��]�p�̐ݒ�
	void SetRotation(XMFLOAT3 rotation) { this->rotation = rotation; }
	// ���W�̎擾
	const XMFLOAT3& GetPosition() { return position; }
	// ���W�̐ݒ�
	void SetPosition(XMFLOAT3 position) { this->position = position; }
	// ���f���̐ݒ�
	void SetModel(Model* model) { this->model = model; };

	//���[���h�s��̎擾
	const XMMATRIX& GetMatWorld() { return matWorld; }
	//�R���C�_�[�̃Z�b�g
	void SetCollider(BaseCollider* Collider);

	//�Փˎ��R�[���o�b�N�֐�
	virtual void OnCollision(const CollisionInfo& info){}
protected: // �����o�ϐ�
	ComPtr<ID3D12Resource> constBuffB0; // �萔�o�b�t�@
	// �F
	XMFLOAT4 color = { 1,1,1,1 };
	// ���[�J���X�P�[��
	XMFLOAT3 scale = { 1,1,1 };
	// X,Y,Z�����̃��[�J����]�p
	XMFLOAT3 rotation = { 0,0,0 };
	// ���[�J�����W
	XMFLOAT3 position = { 0,0,0 };
	// ���[�J�����[���h�ϊ��s��
	XMMATRIX matWorld;
	// �e�I�u�W�F�N�g
	Object3d* parent = nullptr;

	Model* model = nullptr;

	//�N���X��(�f�o�b�N�p)
	const char* name = nullptr;
	//�R���C�_�[
	BaseCollider* collider = nullptr;
};