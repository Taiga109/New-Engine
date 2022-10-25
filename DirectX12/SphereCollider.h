#pragma once

#include "BaseCollider.h"
#include "CollisionPrimitive.h"

#include <DirectXMath.h>
class SphereCollider:public BaseCollider,public Sphere
{
private:
	using XMVECTOR = DirectX::XMVECTOR;
public:
	SphereCollider(XMVECTOR offset = { 0,0,0,0 }, float radius = 1.0f) :
		offset(offset),
		radius(radius)
	{
		shapeType = COLLISIONSHAPE_SPHERE;
	}
	//更新
	void Update() override;
	inline float GetRadius() { return radius; }
	inline void SetRadius(float radius) { this->radius = radius; }
	inline const XMVECTOR& GetOffset() { return offset; }

	inline void SetOffset(const XMVECTOR& offset) { this->offset = offset; }
private:
	//オブジェクト中心からのオフセット
	XMVECTOR offset;
	//半径
	float radius;
};

