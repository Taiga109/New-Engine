#pragma once
#include "Sprite.h"
#include <d3d12.h>
#include "Input.h"
class PostEffect :
    public Sprite
{
public: 
   
    PostEffect();
    //初期化
    void Initialize();
    //パイプライン生成
    void CreateGraphicsPipelineState();
    //描画
    void Draw(ID3D12GraphicsCommandList* cmdList, Input* input);
    //シーン描画前処理
    void PreDrawScene(ID3D12GraphicsCommandList* cmdList);
    //シーン描画後処理
    void PostDrawScene(ID3D12GraphicsCommandList* cmdList);
private:
    //グラフィックスパイプライン
    ComPtr<ID3D12PipelineState> piplineState;
    //ルートシグネチャ
    ComPtr<ID3D12RootSignature> rootSignature;
    //テクスチャバッファ
    ComPtr <ID3D12Resource> texBuff[2];
    //SRV用デスクリプタヒープ
    ComPtr <ID3D12DescriptorHeap> descHeapSRV;
    //深度バッファ
    ComPtr<ID3D12Resource> depthBuff;
    //RTV用デスクリプタヒープ
    ComPtr<ID3D12DescriptorHeap> descHeapRTV;
    //DSV用デスクリプタヒープ
    ComPtr<ID3D12DescriptorHeap>descHeapDSV;
    //画面クリアカラー
    static const float clearColor[4];
private:
    
   
};

