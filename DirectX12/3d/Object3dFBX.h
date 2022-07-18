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
private: // エイリアス
// Microsoft::WRL::を省略
	template <class T> using ComPtr = Microsoft::WRL::ComPtr<T>;
	// DirectX::を省略
	using XMFLOAT2 = DirectX::XMFLOAT2;
	using XMFLOAT3 = DirectX::XMFLOAT3;
	using XMFLOAT4 = DirectX::XMFLOAT4;
	using XMMATRIX = DirectX::XMMATRIX;
public:
	// 定数バッファ用データ構造体B0
	struct ConstBufferDataB0
	{
		XMMATRIX viewproj;    // ビュープロジェクション行列
		XMMATRIX world; // ワールド行列
		XMFLOAT3 cameraPos;//カメラ座標
	};
	struct ConstBufferDataB4
	{
		XMFLOAT3 m_ambient ; // アンビエント係数
		XMFLOAT3 m_diffuse; // ディフューズ係数
		XMFLOAT3 m_specular ; // スペキュラー係数
		float m_alpha;   // アルファ
	};
	
	//ボーンの最大数
	static const int MAX_BONES = 32;

	//定数バッファ用データ構造体(スキニング)
	struct ConstBufferDataSkin
	{
		XMMATRIX bones[MAX_BONES];
	};

	XMFLOAT3 ambient = { 1.0f, 0.5f, 1.0f }; //アンビエント影響度
	XMFLOAT3 diffuse = { 0.0f, 0.0f, 0.0f }; //ディフューズ影響度
	XMFLOAT3 specular = { 0.0f, 0.0f, 0.0f }; //スペキュラー影響度
	float alpha = 1.0f; //アルファ
	
public: // 静的メンバ関数
	//setter
	static void SetDevice(ID3D12Device* device) { Object3dFBX::device = device; }
	static void SetCamera(Camera* camera) { Object3dFBX::camera = camera; }

private: // 静的メンバ変数
// デバイス
	static ID3D12Device* device;
	// コマンドリスト
	static ID3D12GraphicsCommandList* cmdList;
	//カメラ
	static Camera* camera;
	// ルートシグネチャ
	static ComPtr<ID3D12RootSignature> rootsignature;
	// パイプラインステートオブジェクト
	static	ComPtr<ID3D12PipelineState> pipelinestate;
	//定数バッファ(スキン)
	ComPtr<ID3D12Resource> constBuffSkin;
	// 定数バッファ
	ComPtr<ID3D12Resource> constBuff;
	
public: //メンバ変数
	void Initialize();

	//更新
	void Update();

	//モデルセット
	void SetModel(FbxModel* model) { this->model = model; }

	void Draw(ID3D12GraphicsCommandList* cmdList);
	//アニメーション開始
	void PlayAnimation();
	static void CreateGraphicsPipeline();
	//ライトセット
	static void SetLight(Light* light) {
		Object3dFBX::light = light;
	}
protected:
	ComPtr<ID3D12Resource> constBuffTransform;
	static Light* light;
	// ローカルスケール
	XMFLOAT3 scale = { 1,1,1 };
	// X,Y,Z軸回りのローカル回転角
	XMFLOAT3 rotation = { 0,0,0 };
	// ローカル座標
	XMFLOAT3 position = { 0,0,0 };
	// ローカルワールド変換行列
	XMMATRIX matWorld;
	//モデル
	FbxModel* model = nullptr;
	//1フレームの時間
	FbxTime frameTime;
	//アニメーション開始時間
	FbxTime startTime;
	//アニメーション終了時間
	FbxTime endTime;
	//現在時間(アニメーション)
	FbxTime currentTime;
	//アニメーション再生中
	bool isPlay = false;
	
	
};

