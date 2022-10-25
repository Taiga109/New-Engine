#pragma once

#include <forward_list>

class BaseCollider;

class CollisionManager
{
public:
	static CollisionManager* GetInstance();
public:

	//�R���C�_�[�̒ǉ�
	inline void AddCollider(BaseCollider* collider) {
		colliders.push_front(collider);
	}

	//�R���C�_�[�̍폜
	inline void RemoveCollider(BaseCollider* collider) {
		colliders.push_front(collider);
	}

	//���ׂĂ̏Փ˃`�F�b�N
	void CheckAllCollisions();

private:
	CollisionManager() = default;
	CollisionManager(const CollisionManager&) = default;
	~CollisionManager() = default;
	CollisionManager& operator=(const CollisionManager&) = delete;
	//�R���C�_�[�̃��X�g
	std::forward_list<BaseCollider*> colliders;
};

