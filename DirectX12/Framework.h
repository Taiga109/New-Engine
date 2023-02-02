#pragma once
#include "SafeDelete.h"
#include "DirectXCommon.h"
#include <DirectXMath.h>
#include "Input.h"
#include "Sprite.h"
//#include "Object3d.h"
#include "DebugText.h"
#include <stdlib.h>
#include <time.h>
#include "Audio.h"
#include "Camera.h"
#include "DebugCamera.h"
#include "Object3dFBX.h"
#include "Light.h"

#include "3d/Object3d.h"
#include "CollisionManager.h"
#include "3d/ParticleManager.h"


using namespace DirectX;

class Framework
{
private: // �G�C���A�X
// Microsoft::WRL::���ȗ�
	template <class T> using ComPtr = Microsoft::WRL::ComPtr<T>;
	// DirectX::���ȗ�
	using XMFLOAT2 = DirectX::XMFLOAT2;
	using XMFLOAT3 = DirectX::XMFLOAT3;
	using XMFLOAT4 = DirectX::XMFLOAT4;
	using XMMATRIX = DirectX::XMMATRIX;

private: // �ÓI�����o�ϐ�
	static const int debugTextTexNumber = 0;

public: // �����o�֐�

	/// <summary>
	/// �R���X�g�N���^
	/// </summary>
	/*Framework();

	/// <summary>
	/// �f�X�g���N�^
	/// </summary>
	~Framework();*/

	/// <summary>
	/// ������
	/// </summary>
	virtual void Initialize(DirectXCommon* dxCommon, Audio* audio);

	/// <summary>
	/// ���t���[������
	/// </summary>
	virtual void Update();

	/// <summary>
	/// �`��
	/// </summary>
	virtual void Draw();

	virtual void Finalize();
protected: // �����o�ϐ�
	DirectXCommon* dxCommon = nullptr;
	Input* input = nullptr;
	//DebugCamera* Dcamera = nullptr;
	Camera* camera = nullptr;
	DebugText debugText;
	Sprite* spriteBG = nullptr;
	Light* light = nullptr;
};

