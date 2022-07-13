#pragma once
#include "Sprite.h"
#include <d3d12.h>
#include "Input.h"
class PostEffect :
    public Sprite
{
public: 
   
    PostEffect();
    //������
    void Initialize();
    //�p�C�v���C������
    void CreateGraphicsPipelineState();
    //�`��
    void Draw(ID3D12GraphicsCommandList* cmdList, Input* input);
    //�V�[���`��O����
    void PreDrawScene(ID3D12GraphicsCommandList* cmdList);
    //�V�[���`��㏈��
    void PostDrawScene(ID3D12GraphicsCommandList* cmdList);
private:
    //�O���t�B�b�N�X�p�C�v���C��
    ComPtr<ID3D12PipelineState> piplineState;
    //���[�g�V�O�l�`��
    ComPtr<ID3D12RootSignature> rootSignature;
    //�e�N�X�`���o�b�t�@
    ComPtr <ID3D12Resource> texBuff[2];
    //SRV�p�f�X�N���v�^�q�[�v
    ComPtr <ID3D12DescriptorHeap> descHeapSRV;
    //�[�x�o�b�t�@
    ComPtr<ID3D12Resource> depthBuff;
    //RTV�p�f�X�N���v�^�q�[�v
    ComPtr<ID3D12DescriptorHeap> descHeapRTV;
    //DSV�p�f�X�N���v�^�q�[�v
    ComPtr<ID3D12DescriptorHeap>descHeapDSV;
    //��ʃN���A�J���[
    static const float clearColor[4];
private:
    
   
};

