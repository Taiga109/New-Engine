#include "player.h"
#include "Input.h"
#include "DebugCamera.h"
#include "AABBCollision.h"
#include "SphereCollider.h"
#include "ParticleManager.h"


using namespace DirectX;

player* player::Create(FbxModel* model)
{
	//3dオブジェクトのインスタンスを生成
	player* instance = new player();
	if (instance == nullptr)
	{
		return nullptr;
	}

	//初期化
	if (!instance->Initialize())
	{
		delete instance;
		assert(0);
	}
	//モデルのセット
	if (model)
	{
		instance->SetModel(model);
	}
	return instance;
}

bool player::Initialize()
{
	if (!Object3dFBX::Initialize())
	{
		return false;
	}
	XMVECTOR offset = { 0,0,0,0 };
	XMFLOAT3 scale = {10,10,10};
	setCollider(new AABBCollision(offset,scale));

	return true;
}

void player::Update()
{
	Input* input = Input::GetInstance();

	if (input->PushKey(DIK_A))
	{
		rotation.y -= 2.0f;
	}

	if (input->PushKey(DIK_D))
	{
		rotation.y += 2.0f;
	}

	//移動ベクトルをY軸回りの角度で回転
	XMVECTOR move = { 0,0,0.1f,0 };
	XMMATRIX matRot =
		XMMatrixRotationY(XMConvertToRadians(rotation.y));
	move = XMVector3TransformNormal(move, matRot);
	/*if (input->PushKey(DIK_S))
	{
		position.x -= move.m128_f32[0];
		position.y -= move.m128_f32[1];
		position.z -= move.m128_f32[2];


	}
	else if (input->PushKey(DIK_W))
	{
		position.x += move.m128_f32[0];
		position.y += move.m128_f32[1];
		position.z += move.m128_f32[2];

	}*/
	
	Object3dFBX::Update();
}

void player::OnCollisionFBX(const CollisionInfo_FBX& info)
{

	for (int i = 0; i < 1; i++)
	{
		const float rnd_vel = 0.5f;
		XMFLOAT3 vel{};
		vel.x = (float)rand() / RAND_MAX * rnd_vel - rnd_vel / 2.0f;
		vel.y = (float)rand() / RAND_MAX * rnd_vel - rnd_vel / 2.0f;
		vel.z = (float)rand() / RAND_MAX * rnd_vel - rnd_vel / 2.0f;
		XMFLOAT3 pos = { info.inter.m128_f32[0]-10, info.inter.m128_f32[1], info.inter.m128_f32[2]-10 };
		ParticleManager::GetInstance()->Add(20,
			pos, vel, XMFLOAT3(), 0.0f, 5.0f);
	}
}


