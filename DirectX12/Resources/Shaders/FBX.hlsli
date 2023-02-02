//�{�[���̍ő吔
static const int MAX_BONES = 64;

cbuffer cbuff0 : register(b0)
{
	matrix viewproj;
	matrix world;
	float3 cameraPos;
	float bad1;
	float4 color;
};

cbuffer cbuff4 :register(b4)
{
	float3 m_ambient  : packoffset(c0); // �A���r�G���g�W��
	float3 m_diffuse  : packoffset(c1); // �f�B�t���[�Y�W��
	float3 m_specular : packoffset(c2); // �X�y�L�����[�W��
	float m_alpha : packoffset(c2.w);   // �A���t�@
};

cbuffer cbuff5 :register(b8)
{
	float3 lightv;
	float3 lightcolor;
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
	float3 worldpos: POSITION;
	float3 normal :NORMAL; // �@���x�N�g��
	float2 uv  :TEXCOORD; // uv�l

};
