#pragma once
#include <Windows.h>
#include <wrl.h>
#include <d3d12.h>
#include <DirectXMath.h>

class Light
{
private:
	// Microsoft::WRL::���ȗ�
	template <class T> using ComPtr = Microsoft::WRL::ComPtr<T>;
	// DirectX::���ȗ�
	using XMFLOAT2 = DirectX::XMFLOAT2;
	using XMFLOAT3 = DirectX::XMFLOAT3;
	using XMFLOAT4 = DirectX::XMFLOAT4;
	using XMVECTOR = DirectX::XMVECTOR;
	using XMMATRIX = DirectX::XMMATRIX;
public:

	struct ConstBufferData
	{
		XMVECTOR lightv;
		XMFLOAT3 lightcolor;
	};

	static void StaticInitialize(ID3D12Device* device);

	void Initialize();

	void TransferConstBuffer();

	void SetLightDir(const XMVECTOR& lightdir);

	void SetLightColor(const XMFLOAT3& lightcolor);

	void Update();

	void Draw(ID3D12GraphicsCommandList* cmdList, UINT rootParameterIndex);

	static Light* Create();

private:
	static ID3D12Device* device;

	ComPtr<ID3D12Resource> constBuff;
	//���C�g��������
	XMVECTOR lightdir = { 1,0,0,0 };

	XMFLOAT3 lightcolor = { 1,1,1 };
	//�_�[�e�B�t���O
	bool dirty = false;

};
