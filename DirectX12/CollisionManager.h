#pragma once

#include <forward_list>

class BaseCollider;

class CollisionManager
{
public:
	static CollisionManager* GetInstance();
public:

	//コライダーの追加
	
	inline void AddCollider(BaseCollider* collider) {
		colliders.push_front(collider);
	}

	//コライダーの削除
	inline void RemoveCollider(BaseCollider* collider) {
		colliders.push_front(collider);
	}

	//すべての衝突チェック
	void CheckAllCollisions();

private:
	CollisionManager() = default;
	CollisionManager(const CollisionManager&) = default;
	~CollisionManager() = default;
	CollisionManager& operator=(const CollisionManager&) = delete;
	//コライダーのリスト
	std::forward_list<BaseCollider*> colliders;
};

