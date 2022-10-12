#include "player.h"

void player::Initialize(Object3dFBX* fbx, FbxModel* model)
{
	fbx->Initialize();
	fbx->SetModel(model);
	//pos = fbx->GetPos();
	fbx->iniAnimation();

}

void player::move(Input* input, Object3dFBX* fbx)
{
	
	//if (input->PushKey(DIK_A))	//¶
	//{
	//	pos.x -= moveSpead;
	//}
	//else if (input->PushKey(DIK_D))	//‰E
	//{
	//	pos.x += moveSpead;
	//}
	//if (input->PushKey(DIK_S))	//Œã‚ë
	//{
	//	pos.z -= moveSpead;
	//}
	//else if (input->PushKey(DIK_W))	//‘O
	//{
	//	pos.z += moveSpead;
	//}
	//fbx->SetPosition({ pos.x,pos.y,pos.z });
}

void player::update(Object3dFBX* fbx, Input* input)
{
	move(input, fbx);

	fbx->Update();
}

void player::Draw(Object3dFBX* fbx, ID3D12GraphicsCommandList* cmdlist)
{

	fbx->Draw(cmdlist);
}
