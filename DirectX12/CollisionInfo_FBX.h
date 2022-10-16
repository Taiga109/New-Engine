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
	//�Փˑ���̃I�u�W�F�N�g
	Object3dFBX* objectfbx = nullptr;
	//�Փˑ���̃R���C�_�[
	BaseCollider* collider = nullptr;
	//�Փ˓_
	DirectX::XMVECTOR inter;
};