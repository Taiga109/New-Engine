#pragma once
#include "FbxModel.h"
#include "Camera.h"

#include <Windows.h>
#include <wrl.h>
#include <d3d12.h>
#include <DirectXMath.h>
#include <d3dx12.h>
#include <string>
#include "Light.h"

class Object3dFBX
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
	struct Material
	{

		XMFLOAT3 ambient; //�A���r�G���g�e���x
		XMFLOAT3 diffuse; //�f�B�t���[�Y�e���x
		XMFLOAT3 specular; //�X�y�L�����[�e���x
		float alpha; //�A���t�@

		Material()
		{
			ambient = { 0.3f, 0.3f, 0.3f }; //�A���r�G���g�e���x
			diffuse = { 0.0f, 0.0f, 0.0f }; //�f�B�t���[�Y�e���x
			specular = { 0.0f, 0.0f, 0.0f }; //�X�y�L�����[�e���x
			alpha = 1.0f; //�A���t�@
		}
	};

	// �萔�o�b�t�@�p�f�[�^�\����B0
	struct ConstBufferDataB0
	{
		XMMATRIX viewproj;    // �r���[�v���W�F�N�V�����s��
		XMMATRIX world; // ���[���h�s��
		XMFLOAT3 cameraPos;//�J�������W
	};

	struct ConstBufferDataB4
	{
		XMFLOAT3 ambient; // �A���r�G���g�W��
		XMFLOAT3 diffuse; // �f�B�t���[�Y�W��
		XMFLOAT3 specular; // �X�y�L�����[�W��
		float alpha;   // �A���t�@
	};

	//�{�[���̍ő吔
	static const int MAX_BONES = 64;

	//�萔�o�b�t�@�p�f�[�^�\����(�X�L�j���O)
	struct ConstBufferDataSkin
	{
		XMMATRIX bones[MAX_BONES];
	};



public: // �ÓI�����o�֐�
	//setter
	static void SetDevice(ID3D12Device* device) { Object3dFBX::device = device; }
	static void SetCamera(Camera* camera) { Object3dFBX::camera = camera; }

private: // �ÓI�����o�ϐ�
// �f�o�C�X
	static ID3D12Device* device;
	// �R�}���h���X�g
	static ID3D12GraphicsCommandList* cmdList;
	//�J����
	static Camera* camera;
	// ���[�g�V�O�l�`��
	static ComPtr<ID3D12RootSignature> rootsignature;
	// �p�C�v���C���X�e�[�g�I�u�W�F�N�g
	static	ComPtr<ID3D12PipelineState> pipelinestate;
	//�萔�o�b�t�@(�X�L��)
	ComPtr<ID3D12Resource> constBuffSkin;
	// �萔�o�b�t�@
	ComPtr<ID3D12Resource> constBuff;

	// �}�e���A��
	Material material;

public: //�����o�ϐ�
	void Initialize();

	//�X�V
	void Update();

	//���f���Z�b�g
	void SetModel(FbxModel* model) { this->model = model; }

	void Draw(ID3D12GraphicsCommandList* cmdList);
	//�A�j���[�V�����J�n
	void PlayAnimation();
	static void CreateGraphicsPipeline();
	//���C�g�Z�b�g
	static void SetLight(Light* light) {
		Object3dFBX::light = light;
	}
protected:
	ComPtr<ID3D12Resource> constBuffTransform;
	static Light* light;
	float s = 0.01;
	// ���[�J���X�P�[��
	XMFLOAT3 scale = { s,s,s };
	// X,Y,Z�����̃��[�J����]�p
	XMFLOAT3 rotation = { 0,0,0 };
	// ���[�J�����W
	XMFLOAT3 position = { 0,0,0 };
	// ���[�J�����[���h�ϊ��s��
	XMMATRIX matWorld;
	//���f��
	FbxModel* model = nullptr;
	//1�t���[���̎���
	FbxTime frameTime;
	//�A�j���[�V�����J�n����
	FbxTime startTime;
	//�A�j���[�V�����I������
	FbxTime endTime;
	//���ݎ���(�A�j���[�V����)
	FbxTime currentTime;
	//�A�j���[�V�����Đ���
	bool isPlay = false;
public:

};

