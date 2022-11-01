#include "player.h"
#include "Input.h"
#include "DebugCamera.h"
#include "AABBCollision.h"
#include "SphereCollider.h"
#include "ParticleManager.h"


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
	XMFLOAT3 scale = { 10,10,10 };
	setCollider(new SphereCollider(offset, 5));

	return true;

}

void player::Update()
{
	Input* input = Input::GetInstance();
	pos = player::GetPos();
	if (input->PushKey(DIK_D) || input->PushKey(DIK_A)
		|| input->PushKey(DIK_S) || input->PushKey(DIK_W))
	{
		if (input->PushKey(DIK_A))
		{
			pos.x -= 0.5;

		}
		else if (input->PushKey(DIK_D))
		{
			pos.x += 0.5;

		}


		if (input->PushKey(DIK_S))
		{
			pos.z -= 0.5;

		}
		else if (input->PushKey(DIK_W))
		{
			pos.z += 0.5;

		}

	}
	if (input->TriggerMouse(Left) || input->TriggerMouse(Right))
	{
		Attack();
	}
	//移動ベクトルをY軸回りの角度で回転
	/*XMVECTOR move = { 0,0,0.1f,0 };
	XMMATRIX matRot =
		XMMatrixRotationY(XMConvertToRadians(rotation.y));
	move = XMVector3TransformNormal(move, matRot);*/
	player::SetPosition(pos);
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
		XMFLOAT3 pos = { info.inter.m128_f32[0], info.inter.m128_f32[1], info.inter.m128_f32[2]};
		ParticleManager::GetInstance()->Add(20,
			pos, vel, XMFLOAT3(), 0.0f, 5.0f);
	}
}

void player::Attack()
{
	XMVECTOR offset = { 0,0,0,0 };
	setCollider(new SphereCollider(offset, 15));
}


