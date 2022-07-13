#include "fbxsdk.h"
#include "FbxModel.h"
#include <d3d12.h>
#include <d3dx12.h>
#include <string>

class FBXLoader
{
private:
	using string = std::string;
public:
	
	//モデル格納ルートパス
	static const string baseDirectory;
	//テクスチャがない場合の標準テクスチャファイル名
	static const string defaultTextureFileName;
public:
	// シングルトンインスタンスの取得
	static FBXLoader* GetInstance();
public:
	// 初期化
	void Initialize(ID3D12Device* device);
	// 後始末
	void Finalize();
	//ファイルからFBXモデル読み込み
	FbxModel* LoadModelFromFile(const string& modelName);
	//FBXの行列をXMMatrixに変換
	static void ConvertMatrixFromFbx(DirectX::XMMATRIX* dst, const FbxAMatrix& src);

private:
	void ParseNodeRecursive(FbxModel* model, FbxNode* fbxNode, Node* parent = nullptr);
	//メッシュ読み取り
	void ParseMesh(FbxModel* model, FbxNode* fbxnode);
	//頂点座標読み取り
	void ParseMeshVertices(FbxModel* model, FbxMesh* fbxmesh);
	//面情報読み取り
	void ParseMeshFaces(FbxModel* model, FbxMesh* fbxmesh);
	//マテリアル読み取り
	void ParseMaterial(FbxModel* model, FbxNode* fbxnode);
	//テクスチャ読み取り
	void LoadTexture(FbxModel* model, const std::string& fullpath);
	//スキニング情報の読み取り
	void ParseSkin(FbxModel* model, FbxMesh* fbxMesh);
	
private:
	// D3D12デバイス
	ID3D12Device* device = nullptr;
	// FBXマネージャ
	FbxManager* fbxManager = nullptr;
	// FBXインポータ
	FbxImporter* fbxImporter = nullptr;
	//ディレクトリを含んだファイルパスからファイル名を抽出する
	std::string ExtractFileName(const std::string& path);

public:


};

