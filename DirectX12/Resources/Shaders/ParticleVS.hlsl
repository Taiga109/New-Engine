#include "Particle.hlsli"

VSOutput main(float4 pos : POSITION, float scale:TEXCOORD)
{
	VSOutput output; // ピクセルシェーダーに渡す値
	/*output.svpos = mul(mat, pos);
	output.normal = normal;
	output.uv = uv;*/
	output.scale = scale;
	output.pos = pos;
	return output;
}