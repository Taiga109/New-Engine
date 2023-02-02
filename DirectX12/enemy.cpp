#include "Enemy.h"
#include "Input.h"
#include "DebugCamera.h"
#include "AABBCollision.h"
#include "SphereCollider.h"
#include "ParticleManager.h"
#include "player.h"


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

	E_spherecoll = new SphereCollider(offset, Radius);

	setCollider(E_spherecoll);
}

void Enemy::Update()
{
	
	pos = Enemy::GetPos();
	if (Life > 0)
	{
		switch (phase)
		{
		case Enemy::Enemy_Phase::move:

			direction = playerpos - pos;

			len = direction.Length();
			if (len >= 6)
			{
				direction.Normalize();
				//方向ベクトル*スピード*時間
				pos += (direction * 2 * 0.1);
			}
			else if (len <= 6)
			{
				phase = Enemy_Phase::attack;
				SetColor({ 1,0,0,1 });
			}
			break;
		case Enemy::Enemy_Phase::attack:
			EnemyAttack = true;
			Radius = 15;
			E_spherecoll = new SphereCollider(offset, Radius);
			count = 1;


			phase = Enemy_Phase::idol;
			break;

		case Enemy::Enemy_Phase::idol:
			SetColor({ 1,1,1,1 });
			EnemyAttack = false;
			staycount++;
			Radius = 5;
			E_spherecoll->SetRadius(Radius);
			if (staycount > 150)
			{
				staycount = 0;
				phase = Enemy_Phase::move;
			}
			break;
		default:
			break;
		}
		//CheckFlag = Player->GetAttackFlag();

		playerAttack = Player->GetAttackFlag();
		if (!playerAttack)
		{
			count = 0;
		}
		if (EnemyAttack)
		{
			
			for (int i = 0; i < 12; i++)
			{
				
				/*const float rnd_vel = 0.1f;
				XMFLOAT3 vel{};
				vel.x = (float)rand() / RAND_MAX * rnd_vel - rnd_vel / 2.0f;
				vel.y = (float)rand() / RAND_MAX * rnd_vel - rnd_vel / 2.0f;
				vel.z = (float)rand() / RAND_MAX * rnd_vel - rnd_vel / 2.0f;
				XMFLOAT3 p_pos = pos;
				p_pos.y += 10;
				ParticleManager::GetInstance()->Add(80,
					p_pos, vel, XMFLOAT3(), 0.0f, 5.0f, { 1,1,0,1 }, { 1,1,0,0 });*/
			}
		}
	}
	
	Enemy::SetPosition(pos);
	Object3dFBX::Update();

}

void Enemy::Draw(ID3D12GraphicsCommandList* cmdList)
{
	if (Life > 0)
	{
		Object3dFBX::Draw(cmdList);
	}

}

void Enemy::OnCollisionFBX(const CollisionInfo_FBX& info)
{
	int life = Player->GetLife();
	if (playerAttack && count == 0)
	{
		Life -= 1;
		count = 1;
	}

	if (EnemyAttack && life > 0)
	{
		for (int i = 0; i < 7; i++)
		{

			const float rnd_vel = 0.5f;
			XMFLOAT3 vel{};
			vel.x = (float)rand() / RAND_MAX * rnd_vel - rnd_vel / 2.0f;
			vel.y = (float)rand() / RAND_MAX * rnd_vel - rnd_vel / 2.0f;
			vel.z = (float)rand() / RAND_MAX * rnd_vel - rnd_vel / 2.0f;
			XMFLOAT3 pos = { info.inter.m128_f32[0], info.inter.m128_f32[1], info.inter.m128_f32[2] };
			ParticleManager::GetInstance()->Add(20,
				pos, vel, XMFLOAT3(), 0.0f, 5.0f, { 1,0,0,1 }, { 1,0,0,1 });
		}

		life -= 1;
		Player->setLife(life);
		EnemyAttack = false;

	}
}




