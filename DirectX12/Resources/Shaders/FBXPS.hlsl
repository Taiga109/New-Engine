#include "FBX.hlsli"
Texture2D<float4> tex : register(t0);  // 0番スロットに設定されたテクスチャ
SamplerState smp : register(s0);      // 0番スロットに設定されたサンプラー

struct PSOutput
{
	float4 target0 : SV_TARGET0;
	float4 target1 : SV_TARGET1;
};

PSOutput main(VSOutput input)
{
	PSOutput output;
<<<<<<< HEAD
=======
	{
		//float4 texcolor = tex.Sample(smp, input.uv);
		//float3 light = normalize(float3(1, -1, 1)); // 右下奥　向きのライト
		//float light_diffuse = saturate(dot(-light, input.normal));
		//float brightness = light_diffuse + 0.3f;
		//float4 shade_color;
		//shade_color = float4(brightness, brightness, brightness, 1.0f);
	}
	float4 texcolor = tex.Sample(smp, input.uv);
	float4 shade_color;
	//光沢度
	const float shininess = 4.0f;
	//頂点から視点への方向ベクトル
	float3 eyedir = normalize(cameraPos - input.worldpos.xyz);
	//ライトに向かうベクトルと法線の内積
	float3 dotlightnormal = dot(lightv, input.normal);
	//反射光ベクトル
	float3 reflect = normalize(-lightv + 2 * dotlightnormal * input.normal);
	//環境反射光
	float3 ambient = m_ambient;
	//拡散反射光
	float3 diffuse = dotlightnormal * m_diffuse;
	//鏡面反射光
	float3 specular = pow(saturate(dot(reflect, eyedir)), shininess) * m_specular;
	float alpha = m_alpha;
	//合成
	shade_color.rgb = float3((ambient + diffuse + specular).rgb * lightcolor.rgb);
	shade_color.a = 1;
>>>>>>> dfb81bd5af9e0216c0f7f1b76a1ae2677187af0c
	
		float4 texcolor = tex.Sample(smp, input.uv);
		float3 light = normalize(float3(1, -1, 1)); // 右下奥　向きのライト
		float light_diffuse = saturate(dot(-light, input.normal));
		float brightness = light_diffuse + 0.3f;
		float4 shade_color;
		shade_color = float4(brightness, brightness, brightness, 1.0f);
	
	//float4 texcolor = tex.Sample(smp, input.uv);
	//float4 shade_color;
	////光沢度
	//const float shininess = 4.0f;
	////頂点から視点への方向ベクトル
	//float3 eyedir = normalize(cameraPos - input.worldpos.xyz);
	////ライトに向かうベクトルと法線の内積
	//float3 dotlightnormal = dot(lightv, input.normal);
	////反射光ベクトル
	//float3 reflect = normalize(-lightv + 2 * dotlightnormal * input.normal);
	////環境反射光
	//float3 ambient = m_ambient;
	////拡散反射光
	//float3 diffuse = dotlightnormal * m_diffuse;
	////鏡面反射光
	//float3 specular = pow(saturate(dot(reflect, eyedir)), shininess) * m_specular;
	//float alpha = m_alpha;
	////合成
	//shade_color = float4((ambient + diffuse + specular).rgb * lightcolor.rgb, 1);
	//

<<<<<<< HEAD
	output.target0 =  texcolor;
	output.target1 = float4(1 - (shade_color * texcolor).rgb, 1);
=======
	output.target0 = shade_color * texcolor;
	//output.target1 = float4(1 - (shade_color * texcolor).rgb, 1);
>>>>>>> dfb81bd5af9e0216c0f7f1b76a1ae2677187af0c
	return output;
}