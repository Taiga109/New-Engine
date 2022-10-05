#include "MeshCollider.h"
#include "Collision.h"

using namespace DirectX;

void MeshCollider::ConstructTriangles(Model* model,Mesh* mesh)
{

	//�O�p�`���X�g���N���A
	triangle.clear();
	const std::vector<unsigned short>& indices = mesh->GetIndices();
	//���f���̎����b�V�����X�g���擾
	const std::vector<Mesh*>& meshes = model->GetMeshes();

	//���݂̃��b�V���̊J�n�O�p�`�ԍ������Ă����ϐ�
	int start = 0;
	//�S���b�V���ɂ��ď��ɏ�������	
	std::vector<Mesh*>::const_iterator it = meshes.cbegin();
	for (; it != meshes.cend(); ++it)
	{
		//���b�V�����̎O�p�`�̐����t�Z
		size_t triangleNum = indices.size() / 3;
		//���݂̃��b�V���̎O�p�`�̐������A�O�p�`���X�g�ɃX�y�[�X��ǉ�����
		triangle.resize(triangle.size() + triangleNum);
		//�S�O�p�`�ɂ��ď��ɏ�������
		for (int i = 0; i < triangleNum; i++)
		{

		}
		//���̃��b�V���́A���܂ł̎O�p�`�ԍ��̎�����g��
		start += (int)triangleNum;
	}
}
