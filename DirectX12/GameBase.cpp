#include "GameBase.h"

#include "fbxsdk.h"
#include "FBXLoader.h"


void GameBase::Initialize()
{

	// �Q�[���E�B���h�E�̍쐬
	win = new WinApp();
	win->CreateGameWindow();
#ifdef _DEBUG
	//�f�o�b�N���C���[���I����
	ID3D12Debug1* debugController;
	if (SUCCEEDED(D3D12GetDebugInterface(IID_PPV_ARGS(&debugController))))
	{
		debugController->EnableDebugLayer();
		debugController->SetEnableGPUBasedValidation(TRUE);
	}
#endif // DEBUG

	//DirectX����������
	dxCommon = new DirectXCommon();
	dxCommon->Initialize(win);

	//fbx������
	FBXLoader::GetInstance()->Initialize(dxCommon->GetDevice());
	
#pragma region �ėp�@�\������

	//���͂̏�����
	input =  Input::GetInstance();
	input->Initialize(win->GetInstance(), win->GetHwnd());


	// �X�v���C�g�ÓI������
	if (!Sprite::StaticInitialize(dxCommon->GetDevice(), WinApp::window_width, WinApp::window_height))
	{
		assert(0);
	}
	//�|�X�g�G�t�F�N�g�p�e�N�X�`���̓ǂݍ���
	//Sprite::LoadTexture(100, L"Resources/white1x1.png");
	//�|�X�g�G�t�F�N�g�̏�����
	postEffect = new PostEffect();
	postEffect->Initialize();
	// 3D�I�u�W�F�N�g�ÓI������
	Object3d::StaticInitialize(dxCommon->GetDevice());
	//���C�g�ÓI������
	Light::StaticInitialize(dxCommon->GetDevice());
	ParticleManager::GetInstance()->Initialize(dxCommon->GetDevice());
	//�I�[�f�B�I������
	audio = new Audio();
	if (!audio->Initialize())
	{
		assert(0);
	}
#pragma endregion �ėp�@�\������

	// �Q�[���V�[���̏�����
	gameScene = new GameScene();
	gameScene->Initialize(dxCommon, audio);

}

void GameBase::Update()
{
	// ���b�Z�[�W����
	if (win->ProcessMessage())
	{
		endflag = true;
		return;
	}
#pragma region DirectX���t���[������

	// ���͊֘A�̖��t���[������
	input->Update();
	// �Q�[���V�[���̖��t���[������
	gameScene->Update();

#pragma endregion DirectX���t���[������
}

void GameBase::Draw()
{
#pragma region �O���t�B�b�N�X�R�}���h

	//�����_�[�e�N�X�`���ւ̕`��
	//postEffect->PreDrawScene(dxCommon->GetCommandList());

	//postEffect->PostDrawScene(dxCommon->GetCommandList());
	// �`��J�n
	dxCommon->PreDraw();
	//�|�X�g�G�t�F�N�g�̕`��
	//postEffect->Draw(dxCommon->GetCommandList(),input);
	// �Q�[���V�[���̕`��

	gameScene->Draw();
	// �`��I��
	dxCommon->PostDraw();

#pragma endregion �O���t�B�b�N�X�R�}���h
}

void GameBase::Finalize()
{
// �e����
	safe_delete(gameScene);
	//safe_delete(input);
	safe_delete(dxCommon);
	safe_delete(audio);
	safe_delete(postEffect);
	FBXLoader::GetInstance()->Finalize();
	// �Q�[���E�B���h�E�̔j��
	win->TerminateGameWindow();
	safe_delete(win);

}
