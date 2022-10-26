#include "Enemy.h"
#include "Input.h"
#include "DebugCamera.h"
#include "AABBCollision.h"
#include "SphereCollider.h"
#include "ParticleManager.h"


Enemy* Enemy::Create(FbxModel* model)
{
	//3dオブジェクトのインスタンスを生成
	Enemy* instance = new Enemy();
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

bool Enemy::Initialize()
{
	if (!Object3dFBX::Initialize())
	{
		return false;
	}
	return true;

}

void Enemy::Update()
{
	
	pos = Enemy::GetPos();
	switch (phase)
	{
	case Enemy::Enemy_Phase::move:
		if (turn)
		{
			pos.x -= 0.5;
			if (pos.x <= -20) {
				turn = false;
			}
		}
		else
		{
			pos.x += 0.5;
			if (pos.x >= 20) {
				turn = true;
			}
		}
		break;
	case Enemy::Enemy_Phase::attack:
		break;
	case Enemy::Enemy_Phase::idol:

		break;
	default:
		break;
	}


	
	Enemy::SetPosition(pos);
	Object3dFBX::Update();
}

void Enemy::OnCollisionFBX(const CollisionInfo_FBX& info)
{

	for (int i = 0; i < 1; i++)
	{
		const float rnd_vel = 0.5f;
		XMFLOAT3 vel{};
		vel.x = (float)rand() / RAND_MAX * rnd_vel - rnd_vel / 2.0f;
		vel.y = (float)rand() / RAND_MAX * rnd_vel - rnd_vel / 2.0f;
		vel.z = (float)rand() / RAND_MAX * rnd_vel - rnd_vel / 2.0f;
		XMFLOAT3 pos = { info.inter.m128_f32[0] - 10, info.inter.m128_f32[1], info.inter.m128_f32[2] - 10 };
		ParticleManager::GetInstance()->Add(20,
			pos, vel, XMFLOAT3(), 0.0f, 5.0f);
	}
}


