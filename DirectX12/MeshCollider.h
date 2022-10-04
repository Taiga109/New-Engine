#pragma once

#include "BaseCollider.h"
#include "CollisionPrimitive.h"

#include <DirectXMath.h>
class MeshCollider:
	public BaseCollider
{
public:
	MeshCollider()
	{
		//���b�V���`����Z�b�g
		shapeType = COLLISIONSHAPE_MESH;
	}

	//�O�p�`�̔z����\�z����
	void ConstructTriangles(FbxModel* model,FbxNode* node);
	//�X�V
	void Update() override;

	//���Ƃ̓����蔻��
	bool CheckCollisionSphere(const Sphere& sphere,
		DirectX::XMVECTOR* inter = nullptr);
	//���C�Ƃ̓����蔻��	
	bool CheckCollisionRay(const Ray& ray, float* distance = nullptr,
		DirectX::XMVECTOR* inter = nullptr);
private:
	std::vector<Triangle> triangle;
	//���[���h�s��̋t�s��
	DirectX::XMMATRIX invMatWorld;

};

