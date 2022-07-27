#include "FBX.hlsli"
Texture2D<float4> tex : register(t0);  // 0�ԃX���b�g�ɐݒ肳�ꂽ�e�N�X�`��
SamplerState smp : register(s0);      // 0�ԃX���b�g�ɐݒ肳�ꂽ�T���v���[

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
		//float3 light = normalize(float3(1, -1, 1)); // �E�����@�����̃��C�g
		//float light_diffuse = saturate(dot(-light, input.normal));
		//float brightness = light_diffuse + 0.3f;
		//float4 shade_color;
		//shade_color = float4(brightness, brightness, brightness, 1.0f);
	}
	float4 texcolor = tex.Sample(smp, input.uv);
	float4 shade_color;
	//����x
	const float shininess = 4.0f;
	//���_���王�_�ւ̕����x�N�g��
	float3 eyedir = normalize(cameraPos - input.worldpos.xyz);
	//���C�g�Ɍ������x�N�g���Ɩ@���̓���
	float3 dotlightnormal = dot(lightv, input.normal);
	//���ˌ��x�N�g��
	float3 reflect = normalize(-lightv + 2 * dotlightnormal * input.normal);
	//�����ˌ�
	float3 ambient = m_ambient;
	//�g�U���ˌ�
	float3 diffuse = dotlightnormal * m_diffuse;
	//���ʔ��ˌ�
	float3 specular = pow(saturate(dot(reflect, eyedir)), shininess) * m_specular;
	float alpha = m_alpha;
	//����
	shade_color.rgb = float3((ambient + diffuse + specular).rgb * lightcolor.rgb);
	shade_color.a = 1;
>>>>>>> dfb81bd5af9e0216c0f7f1b76a1ae2677187af0c
	
		float4 texcolor = tex.Sample(smp, input.uv);
		float3 light = normalize(float3(1, -1, 1)); // �E�����@�����̃��C�g
		float light_diffuse = saturate(dot(-light, input.normal));
		float brightness = light_diffuse + 0.3f;
		float4 shade_color;
		shade_color = float4(brightness, brightness, brightness, 1.0f);
	
	//float4 texcolor = tex.Sample(smp, input.uv);
	//float4 shade_color;
	////����x
	//const float shininess = 4.0f;
	////���_���王�_�ւ̕����x�N�g��
	//float3 eyedir = normalize(cameraPos - input.worldpos.xyz);
	////���C�g�Ɍ������x�N�g���Ɩ@���̓���
	//float3 dotlightnormal = dot(lightv, input.normal);
	////���ˌ��x�N�g��
	//float3 reflect = normalize(-lightv + 2 * dotlightnormal * input.normal);
	////�����ˌ�
	//float3 ambient = m_ambient;
	////�g�U���ˌ�
	//float3 diffuse = dotlightnormal * m_diffuse;
	////���ʔ��ˌ�
	//float3 specular = pow(saturate(dot(reflect, eyedir)), shininess) * m_specular;
	//float alpha = m_alpha;
	////����
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