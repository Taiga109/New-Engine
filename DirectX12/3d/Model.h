#pragma once

#include <Windows.h>
#include <wrl.h>
#include <d3d12.h>
#include <DirectXMath.h>
#include <d3dx12.h>

#include <vector>
#include <string>
#include <unordered_map>
#include "Mesh.h"

class Model
{
private: // �G�C���A�X
// Microsoft::WRL::���ȗ�
	template <class T> using ComPtr = Microsoft::WRL::ComPtr<T>;
	// DirectX::���ȗ�
	using XMFLOAT2 = DirectX::XMFLOAT2;
	using XMFLOAT3 = DirectX::XMFLOAT3;
	using XMFLOAT4 = DirectX::XMFLOAT4;
	using XMMATRIX = DirectX::XMMATRIX;



private: // �萔
	static const std::string baseDirectory;
	// �f�o�C�X
	static ID3D12Device* device;
	// �f�X�N���v�^�T�C�Y
	static UINT descriptorHandleIncrementSize;
public: // �ÓI�����o�֐�
	// �ÓI������
	static void StaticInitialize(ID3D12Device* device);

	static Model* CreateFromObj(const std::string& modelname, bool smoothing = false);


public: // �����o�֐�
	//�f�X�g���N�^
	~Model();

	void Initialize(const std::string& modelname, bool smooshing);
	// �`��
	void Draw(ID3D12GraphicsCommandList* cmdList);

	//���b�V���R���e�i
	inline const std::vector<Mesh*>& GetMeshes() { return meshes; }

private: // �����o�ϐ�
	//���O
	std::string name;
	//���b�V���R���e�i
	std::vector<Mesh*> meshes;
	//�}�e���A���R���e�i
	std::unordered_map<std::string, Material*> materials;
	//�f�t�H���g�}�e���A��
	Material* defaultMaterial = nullptr;
	//�f�X�N���v�^�q�[�v
	ComPtr<ID3D12DescriptorHeap> descHeap;
private:// �ÓI�����o�֐�
// �}�e���A���ǂݍ���
	void LoadMaterial(const std::string& directoryPath, const std::string& filename);

	/// �}�e���A���o�^
	void AddMaterial(Material* material);

	/// �f�X�N���v�^�q�[�v�̐���
	void CreateDescriptorHeap();

	/// �e�N�X�`���ǂݍ���
	void LoadTextures();
};