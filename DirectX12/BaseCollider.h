#pragma once
#include "CollisionInfo.h"
#include "CollisionTypes.h"
#include "Object3d.h"
#include "3d/Object3dFBX.h"
class BaseCollider
{
public:
	BaseCollider() = default;
	//���z�f�X�g���N�^
	virtual ~BaseCollider() = default;

	inline void SetObject(Object3d* object) {
		this->object3d = object;
	}

	inline void SetObjectFbx(Object3dFBX* objectfbx) {
		this->object3dfbx = objectfbx;
	}

	inline Object3d* GetObject3d() {
		return object3d;
	}
	inline Object3dFBX* GetObject3dFbx() {
		return object3dfbx;
	}
	//�X�V
	virtual void Update() = 0;
	//�`��^�C�v�擾
	inline CollisionShapeType GetShapeType() { return shapeType; }
	//�Փˎ��R�[���o�b�N�֐�
	inline void OnCollision(const CollisionInfo& info) {
		object3d->OnCollision(info);
	}
protected:
	Object3d* object3d = nullptr;
	Object3dFBX* object3dfbx = nullptr;
	//�`��^�C�v
	CollisionShapeType shapeType = SHAPE_UNKNOWN;
};

