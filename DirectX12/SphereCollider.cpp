#include "SphereCollider.h"

using namespace DirectX;

void SphereCollider::Update()
{
	
	//ワールド行列から座標を抽出
	const XMMATRIX& matWorld= GetObject3dFbx()->GetMatWorld();

	Sphere::center = matWorld.r[3] + offset;
	Sphere::radius = radius;
}
