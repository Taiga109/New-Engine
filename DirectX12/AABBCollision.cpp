#include "AABBCollision.h"
void AABBCollision::Update()
{
	// ���[���h�s�񂩂���W�𒊏o
	const XMMATRIX& matWorld = object3d->GetMatWorld();

	// ���̃����o�ϐ����X�V
	AABB::center = matWorld.r[3] + offset;
	AABB::length = length;
}
