#pragma once
#include "CollisionInfo.h"
#include "CollisionTypes.h"
#include "Object3d.h"
#include "3d/Object3dFBX.h"
class BaseCollider
{
public:
	BaseCollider() = default;
	//仮想デストラクタ
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
	//更新
	virtual void Update() = 0;
	//形状タイプ取得
	inline CollisionShapeType GetShapeType() { return shapeType; }
	//衝突時コールバック関数
	inline void OnCollision(const CollisionInfo& info) {
		object3d->OnCollision(info);
	}
protected:
	Object3d* object3d = nullptr;
	Object3dFBX* object3dfbx = nullptr;
	//形状タイプ
	CollisionShapeType shapeType = SHAPE_UNKNOWN;
};

