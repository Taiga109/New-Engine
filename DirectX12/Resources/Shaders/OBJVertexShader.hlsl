#include "OBJShaderHeader.hlsli"

VSOutput main(float4 pos : POSITION, float3 normal : NORMAL, float2 uv : TEXCOORD)
{
	float4 wnormal = normalize(mul(world, float4(normal, 0)));
	float4 wpos = mul(world, pos);
	//ピクセルシェーダーに渡す値
	VSOutput output; // ピクセルシェーダーに渡す値
	//行列による座標変換
	output.svpos = mul(mul(viewproj, world), pos);
	output.worldpos = wpos;
	//ワールド法線を次のステージに渡す
	output.normal = wnormal.xyz;
	//入力値をそのまま次のステージに渡す
	output.uv = uv;
	return output;
}