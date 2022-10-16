#pragma once

#include<DirectXMath.h>

class Object3dFBX;
class BaseCollider;

struct CollisionInfo_FBX
{
public:
	CollisionInfo_FBX(Object3dFBX* objectfbx, BaseCollider* collider, const
		DirectX::XMVECTOR& inter) {
		this->objectfbx = objectfbx;
		this->collider = collider;
		this->inter = inter;
	}
	//衝突相手のオブジェクト
	Object3dFBX* objectfbx = nullptr;
	//衝突相手のコライダー
	BaseCollider* collider = nullptr;
	//衝突点
	DirectX::XMVECTOR inter;
};