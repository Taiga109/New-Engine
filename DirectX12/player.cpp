#include "player.h"
#include "Input.h"
#include "DebugCamera.h"
#include "AABBCollision.h"
#include "SphereCollider.h"
#include "ParticleManager.h"
#include "PlayerAttack.h"


player* player::Create(FbxModel* model)
{
	//3d�I�u�W�F�N�g�̃C���X�^���X�𐶐�
	player* instance = new player();
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

bool player::Initialize()
{
	if (!Object3dFBX::Initialize())
	{
		return false;
	}


	XMFLOAT3 scale = { 10,10,10 };
	spherecoll = new SphereCollider(offset, Radius);

	setCollider(spherecoll);

	return true;

}

void player::Update()
{

	Input* input = Input::GetInstance();
	pos = player::GetPos();
	//E_AttackFlag = enemy->GetAttackFlag();
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

	Attack(input);

	if (AttackFlag == true)
	{
		attackcount++;
	}
	if (AttackFlag == true && attackcount >= 10)
	{
		Radius = 5;
		spherecoll->SetRadius(Radius);
		attackcount = 0;
		AttackFlag = false;

	}


	//�ړ��x�N�g����Y�����̊p�x�ŉ�]
	/*XMVECTOR move = { 0,0,0.1f,0 };
	XMMATRIX matRot =
		XMMatrixRotationY(XMConvertToRadians(rotation.y));
	move = XMVector3TransformNormal(move, matRot);*/
	player::SetPosition(pos);
	Object3dFBX::Update();
}

void player::Draw(ID3D12GraphicsCommandList* cmdList)
{

	if (playerlife > 0)
	{
		Object3dFBX::Draw(cmdList);
	}


}

void player::OnCollisionFBX(const CollisionInfo_FBX& info)
{
	if (AttackFlag)
	{
		for (int i = 0; i < 1; i++)
		{
			const float rnd_vel = 0.5f;
			XMFLOAT3 vel{};
			vel.x = (float)rand() / RAND_MAX * rnd_vel - rnd_vel / 2.0f;
			vel.y = (float)rand() / RAND_MAX * rnd_vel - rnd_vel / 2.0f;
			vel.z = (float)rand() / RAND_MAX * rnd_vel - rnd_vel / 2.0f;
			XMFLOAT3 pos = { info.inter.m128_f32[0], info.inter.m128_f32[1], info.inter.m128_f32[2] };
			ParticleManager::GetInstance()->Add(20,
				pos, vel, XMFLOAT3(), 0.0f, 5.0f, { 1,1,1,1 }, { 1,1,1,1 });
		}
	}
	
}

void player::Attack(Input* input)
{
	if (input->TriggerMouse(Left) || input->TriggerMouse(Right) || input->TriggerKey(DIK_SPACE) && AttackFlag == false)
	{

		Radius = 20;
		spherecoll->SetRadius(Radius);
		//playerAttack = attack;
		AttackFlag = true;
	}
}


