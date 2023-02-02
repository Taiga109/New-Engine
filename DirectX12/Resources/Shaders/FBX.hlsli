//ボーンの最大数
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
	float3 m_ambient  : packoffset(c0); // アンビエント係数
	float3 m_diffuse  : packoffset(c1); // ディフューズ係数
	float3 m_specular : packoffset(c2); // スペキュラー係数
	float m_alpha : packoffset(c2.w);   // アルファ
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
	float4 pos : POSITION; // システム用頂点座標
	float3 normal :NORMAL; // 法線ベクトル
	float2 uv  :TEXCOORD; // uv値
	uint4 boneIndices : BONEINDICES;//ボーンの番号
	float4 boneWeights : BONEWEIGHTS;//ボーンのスキンウェイト
};

// 頂点シェーダーからピクセルシェーダーへのやり取りに使用する構造体
struct VSOutput
{
	float4 svpos : SV_POSITION; // システム用頂点座標
	float3 worldpos: POSITION;
	float3 normal :NORMAL; // 法線ベクトル
	float2 uv  :TEXCOORD; // uv値

};
