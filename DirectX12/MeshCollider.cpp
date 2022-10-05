#include "MeshCollider.h"
#include "Collision.h"

using namespace DirectX;

void MeshCollider::ConstructTriangles(Model* model,Mesh* mesh)
{

	//三角形リストをクリア
	triangle.clear();
	const std::vector<unsigned short>& indices = mesh->GetIndices();
	//モデルの持つメッシュリストを取得
	const std::vector<Mesh*>& meshes = model->GetMeshes();

	//現在のメッシュの開始三角形番号を入れておく変数
	int start = 0;
	//全メッシュについて順に処理する	
	std::vector<Mesh*>::const_iterator it = meshes.cbegin();
	for (; it != meshes.cend(); ++it)
	{
		//メッシュ内の三角形の数を逆算
		size_t triangleNum = indices.size() / 3;
		//現在のメッシュの三角形の数だけ、三角形リストにスペースを追加する
		triangle.resize(triangle.size() + triangleNum);
		//全三角形について順に処理する
		for (int i = 0; i < triangleNum; i++)
		{

		}
		//次のメッシュは、今までの三角形番号の次から使う
		start += (int)triangleNum;
	}
}
