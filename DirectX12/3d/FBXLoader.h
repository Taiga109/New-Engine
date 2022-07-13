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
	
	//���f���i�[���[�g�p�X
	static const string baseDirectory;
	//�e�N�X�`�����Ȃ��ꍇ�̕W���e�N�X�`���t�@�C����
	static const string defaultTextureFileName;
public:
	// �V���O���g���C���X�^���X�̎擾
	static FBXLoader* GetInstance();
public:
	// ������
	void Initialize(ID3D12Device* device);
	// ��n��
	void Finalize();
	//�t�@�C������FBX���f���ǂݍ���
	FbxModel* LoadModelFromFile(const string& modelName);
	//FBX�̍s���XMMatrix�ɕϊ�
	static void ConvertMatrixFromFbx(DirectX::XMMATRIX* dst, const FbxAMatrix& src);

private:
	void ParseNodeRecursive(FbxModel* model, FbxNode* fbxNode, Node* parent = nullptr);
	//���b�V���ǂݎ��
	void ParseMesh(FbxModel* model, FbxNode* fbxnode);
	//���_���W�ǂݎ��
	void ParseMeshVertices(FbxModel* model, FbxMesh* fbxmesh);
	//�ʏ��ǂݎ��
	void ParseMeshFaces(FbxModel* model, FbxMesh* fbxmesh);
	//�}�e���A���ǂݎ��
	void ParseMaterial(FbxModel* model, FbxNode* fbxnode);
	//�e�N�X�`���ǂݎ��
	void LoadTexture(FbxModel* model, const std::string& fullpath);
	//�X�L�j���O���̓ǂݎ��
	void ParseSkin(FbxModel* model, FbxMesh* fbxMesh);
	
private:
	// D3D12�f�o�C�X
	ID3D12Device* device = nullptr;
	// FBX�}�l�[�W��
	FbxManager* fbxManager = nullptr;
	// FBX�C���|�[�^
	FbxImporter* fbxImporter = nullptr;
	//�f�B���N�g�����܂񂾃t�@�C���p�X����t�@�C�����𒊏o����
	std::string ExtractFileName(const std::string& path);

public:


};

