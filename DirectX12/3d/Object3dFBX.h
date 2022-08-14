#pragma once
#include "FbxModel.h"
#include "Camera.h"
#include "Light.h"
#include <Windows.h>
#include <wrl.h>
#include <d3d12.h>
#include <DirectXMath.h>
#include <d3dx12.h>
#include <string>
#include "Input.h"

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
	struct Material
	{

		XMFLOAT3 ambient; //アンビエント影響度
		XMFLOAT3 diffuse; //ディフューズ影響度
		XMFLOAT3 specular; //スペキュラー影響度
		float alpha; //アルファ

		Material()
		{
			ambient = { 0.3f, 0.3f, 0.3f }; //アンビエント影響度
			diffuse = { 0.0f, 0.0f, 0.0f }; //ディフューズ影響度
			specular = { 0.0f, 0.0f, 0.0f }; //スペキュラー影響度
			alpha = 1.0f; //アルファ
		}
	};

	// 定数バッファ用データ構造体B0
	struct ConstBufferDataB0
	{
		XMMATRIX viewproj;    // ビュープロジェクション行列
		XMMATRIX world; // ワールド行列
		XMFLOAT3 cameraPos;//カメラ座標
	};

	struct ConstBufferDataB4
	{
		XMFLOAT3 ambient; // アンビエント係数
		XMFLOAT3 diffuse; // ディフューズ係数
		XMFLOAT3 specular; // スペキュラー係数
		float alpha;   // アルファ
	};

	//ボーンの最大数
	static const int MAX_BONES = 64;

	//定数バッファ用データ構造体(スキニング)
	struct ConstBufferDataSkin
	{
		XMMATRIX bones[MAX_BONES];
	};

	struct Animation
	{
		FbxAnimStack* Animstack;
		FbxTakeInfo* Takeinfo;
	};

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

	// マテリアル
	Material material;

public: //メンバ変数
	void Initialize();

	//更新
	void Update();

	//モデルセット
	void SetModel(FbxModel* model) { this->model = model; }

	void Draw(ID3D12GraphicsCommandList* cmdList);
	//アニメーション開始
	void PlayAnimation(int AnimationNumber);
	//アニメーション初期化
	void iniAnimation();
	//アニメーションブレンド
	void AnimetionBlend(int beforAniNum, int afterAniNum);

	static void CreateGraphicsPipeline();

	//ライトセット
	static void SetLight(Light* light) {
		Object3dFBX::light = light;
	}

	// 座標の取得
	const XMFLOAT3& GetPos() { return position; }
	// 座標の設定
	void SetPosition(XMFLOAT3 position) { this->position = position; }
	// X,Y,Z軸回りの取得
	const XMFLOAT3& GetRotation() { return rotation; }
	// X,Y,Z軸回りの設定
	void SetRotation(XMFLOAT3 rotation) { this->rotation = rotation; }
	// スケールの取得
	const XMFLOAT3& GetScale() { return scale; }
	// スケールの設定
	void SetScale(XMFLOAT3 scale) { this->scale = scale; }

	const FbxTime& GetendTime() { return endTime; }
protected:
	ComPtr<ID3D12Resource> constBuffTransform;
	static Light* light;
	//float s = 0.1;
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

	//アニメーションブレンド変更前の開始時間
	FbxTime beforstartTime;
	//アニメーションブレンド変更前の終了時間
	FbxTime beforendTime;

	//アニメーションブレンド変更後の開始時間
	FbxTime afterstartTime;
	//アニメーションブレンド変更後の終了時間
	FbxTime afterendTime;

	//現在時間(アニメーション)
	FbxTime currentTime;
	//アニメーション再生中
	bool isPlay = false;

	bool blend = false;

	int BeforAniNum=0;
	int AfterAniNum=0;
	void setblendanime(int AfterAniNum);
	//アニメーションの保存
	std::vector<Animation> AnimationData;
public:

};

