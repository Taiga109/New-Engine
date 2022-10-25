#include"GameBase.h"
//# Windowsアプリでのエントリーポイント(main関数)
int WINAPI WinMain(HINSTANCE, HINSTANCE, LPSTR, int)
{
	GameBase game;
	game.Initialize();
	
	while (true)  // ゲームループ
	{
		game.Update();
		if (game.GetEndFlag())
		{
			break;
		}
		game.Draw();
	
	}
	game.Finalize();
	return 0;
}
