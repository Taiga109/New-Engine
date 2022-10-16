#include "AABBCollision.h"
void AABBCollision::Update()
{
	// ワールド行列から座標を抽出

	const XMMATRIX& matWorld = GetObject3dFbx()->GetMatWorld();
	const XMMATRIX& matWorld = object3d->GetMatWorld();


	// 球のメンバ変数を更新
	AABB::center = matWorld.r[3] + offset;
	AABB::length = length;
}
