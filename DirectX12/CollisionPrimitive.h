#pragma once
#include "Vector3.h"
#include <DirectXMath.h>

struct Sphere
{
	DirectX::XMVECTOR center = { 0,0,0,1 };

	float radius = 1.0f;
};

struct Plane
{
	DirectX::XMVECTOR nomal = { 0,1,0,0 };

	float distance = 0.0f;
};

class Triangle
{
public:
	//���_���W�R��
	DirectX::XMVECTOR p0;
	DirectX::XMVECTOR p1;
	DirectX::XMVECTOR p2;
	//�@���x�N�g��
	DirectX::XMVECTOR normal;

	void ComputeNormal();
};

struct Ray
{
	DirectX::XMVECTOR start = { 0,0,0,1 };
	DirectX::XMVECTOR dir = { 1,0,0,0 };
};
//�����s���E�{�b�N�X
struct AABB {
	//���S���W
	Vector3 center = { 0,0,0 };
	//�W�_���W
	Vector3 length = { 1,1,1 };
};
