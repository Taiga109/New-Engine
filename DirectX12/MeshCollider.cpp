#include "MeshCollider.h"
#include "Collision.h"

using namespace DirectX;

void MeshCollider::ConstructTriangles(FbxModel* model, FbxNode* node)
{
	
	//�O�p�`���X�g���N���A
	triangle.clear();
	//���f���̎����b�V�����X�g���擾
	//const std::vector<FbxNode*>meshes = node->GetMesh();
	//�m�[�h�̃��b�V�����擾
	FbxMesh* meshes = node->GetMesh();
	//���݂̃��b�V���̊J�n�O�p�`�ԍ������Ă����ϐ�
	int start = 0;
	//�S���b�V���ɂ��ď��ɏ�������	
}
