#pragma once

#include "CollisionPrimitive.h"
class Collision
{
	
public:
	static bool CheckSphere2Plane(const Sphere& sphere, const Plane& plane,
		DirectX::XMVECTOR* inter = nullptr);

	static void ClosetPtPoint2Triangle(const DirectX::XMVECTOR& point
		, const Triangle& triangle, DirectX::XMVECTOR* closest);

	static bool CheckSphere2Triangle(const Sphere& sphere, const Triangle& triangle,
		DirectX::XMVECTOR* inter = nullptr);

	static bool CheckRay2Plane(const Ray& ray, const Plane& plane, float* distance = nullptr,
		DirectX::XMVECTOR* inter = nullptr);

	static bool CheckRay2Triangle(const Ray& ray, const Triangle& triangle,
		float* distance = nullptr, DirectX::XMVECTOR* inter = nullptr);

	static bool CheckRay2Sphere(const Ray& ray, const Sphere& Sphere,
		float* distance = nullptr, DirectX::XMVECTOR* inter = nullptr);
	//‹…‚Æ‹…‚Ì“–‚½‚è”»’è
	static bool CheckSphere2Sphere(const Sphere& sphereA, const Sphere& sphereB,
		DirectX::XMVECTOR* inter = nullptr, DirectX::XMVECTOR* reject = nullptr);
	//‹…‚ÆAABB‚Ì“–‚½‚è”»’è
	static bool CheckSphere2AABB(const Sphere& sphere, const AABB& aabb, DirectX::XMVECTOR* inter = nullptr);

};

