//�{�[���̍ő吔
static const int MAX_BONES = 32;

cbuffer cbuff0 : register(b0)
{
	matrix viewproj;
	matrix world;
	float3 cameraPos;
};

cbuffer skinning:register(b3)
{
	matrix matSkinning[MAX_BONES];
}

struct VSInput
{
	float4 pos : POSITION; // �V�X�e���p���_���W
	float3 normal :NORMAL; // �@���x�N�g��
	float2 uv  :TEXCOORD; // uv�l
	uint4 boneIndices : BONEINDICES;//�{�[���̔ԍ�
	float4 boneWeights : BONEWEIGHTS;//�{�[���̃X�L���E�F�C�g
};

// ���_�V�F�[�_�[����s�N�Z���V�F�[�_�[�ւ̂����Ɏg�p����\����
struct VSOutput
{
	float4 svpos : SV_POSITION; // �V�X�e���p���_���W
	float3 normal :NORMAL; // �@���x�N�g��
	float2 uv  :TEXCOORD; // uv�l
};
