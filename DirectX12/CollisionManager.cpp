#include "CollisionManager.h"
#include "BaseCollider.h"
#include "Collision.h"

CollisionManager* CollisionManager::GetInstance()
{
	static CollisionManager instance;
	return &instance;
}

void CollisionManager::CheckAllCollisions()
{
	std::forward_list<BaseCollider*>::iterator itA;
	std::forward_list<BaseCollider*>::iterator itB;

	//すべての組み合わせについて総当たりチェック
	itA = colliders.begin();
	for (; itA != colliders.end(); ++itA)
	{
		itB = itA;
		++itB;
		for ( ;itB != colliders.end(); ++itB)
		{
			BaseCollider* colA = *itA;
			BaseCollider* colB = *itB;
			if (colA->GetShapeType()==COLLISIONSHAPE_SPHERE&&
				colB->GetShapeType()== COLLISIONSHAPE_SPHERE)
			{
				Sphere* SphereA = dynamic_cast<Sphere*>(colA);
				Sphere* SphereB = dynamic_cast<Sphere*>(colB);
				DirectX::XMVECTOR inter;
				if (Collision::CheckSphere2Sphere(*SphereA,*SphereB,&inter))
				{
					colA->OnCollisionFBX(CollisionInfo_FBX(colB->GetObject3dFbx(), colB, inter));
					colB->OnCollisionFBX(CollisionInfo_FBX(colA->GetObject3dFbx(), colA, inter));
				}
			}

			if (colA->GetShapeType() == COLLISIONSHAPE_SPHERE &&
				colB->GetShapeType() == COLLISIONSHAPE_AABB)
			{
				Sphere* SphereA = dynamic_cast<Sphere*>(colA);
				AABB* AABB_B = dynamic_cast<AABB*>(colB);
				DirectX::XMVECTOR inter;
				if (Collision::CheckSphere2AABB(*SphereA, *AABB_B, &inter))
				{
					colA->OnCollisionFBX(CollisionInfo_FBX(colB->GetObject3dFbx(), colB, inter));
					colB->OnCollisionFBX(CollisionInfo_FBX(colA->GetObject3dFbx(), colA, inter));
				}
			}
		}
	}
}

