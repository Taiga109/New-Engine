#pragma once

#include "BaseCollider.h"
#include "CollisionPrimitive.h"
#include "Mesh.h"
#include <DirectXMath.h>
class MeshCollider:
	public BaseCollider
{
public:
	MeshCollider()
	{
		//メッシュ形状をセット
		shapeType = COLLISIONSHAPE_MESH;
	}

	//三角形の配列を構築する
	void ConstructTriangles(Model* model, Mesh* mesh);
	//更新
	void Update() override;

	//球との当たり判定
	bool CheckCollisionSphere(const Sphere& sphere,
		DirectX::XMVECTOR* inter = nullptr);
	//レイとの当たり判定	
	bool CheckCollisionRay(const Ray& ray, float* distance = nullptr,
		DirectX::XMVECTOR* inter = nullptr);
private:
	std::vector<Triangle> triangles;
	//ワールド行列の逆行列
	DirectX::XMMATRIX invMatWorld;



};

