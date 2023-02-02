#include "PlayerAttack.h"

void PlayerAttack::Initialize(float Radius)
{
	setCollider(new SphereCollider({0,0,0,0}, Radius));

}

void PlayerAttack::OnCollisionFBX(const CollisionInfo_FBX& info)
{
	if (Attackflag)
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

