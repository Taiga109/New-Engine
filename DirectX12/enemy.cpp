#include "Enemy.h"
#include "Input.h"
#include "DebugCamera.h"
#include "AABBCollision.h"
#include "SphereCollider.h"
#include "ParticleManager.h"


Enemy* Enemy::Create(FbxModel* model)
{
	//3d�I�u�W�F�N�g�̃C���X�^���X�𐶐�
	Enemy* instance = new Enemy();
	if (instance == nullptr)
	{
		return nullptr;
	}

	//������
	if (!instance->Initialize())
	{
		delete instance;
		assert(0);
	}
	//���f���̃Z�b�g
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
	/*	if (turn)
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
		}*/
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

}


