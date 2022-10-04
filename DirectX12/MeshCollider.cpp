#include "MeshCollider.h"
#include "Collision.h"

using namespace DirectX;

void MeshCollider::ConstructTriangles(FbxModel* model, FbxNode* node)
{
	
	//三角形リストをクリア
	triangle.clear();
	//モデルの持つメッシュリストを取得
	//const std::vector<FbxNode*>meshes = node->GetMesh();
	//ノードのメッシュを取得
	FbxMesh* meshes = node->GetMesh();
	//現在のメッシュの開始三角形番号を入れておく変数
	int start = 0;
	//全メッシュについて順に処理する	
}
