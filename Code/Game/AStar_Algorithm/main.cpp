#include "GamePlay/Gameplay.h"

#if _DEBUG
#include <crtdbg.h>
#endif

#include <Windows.h>

#include "Timing/Timing.h"
#include "Windows/Windows.h"

int WINAPI WinMain(const HINSTANCE i_hInstance, const HINSTANCE i_hprevInstance, const PSTR i_cmdLine, const int i_showCmd)
{
#ifdef _DEBUG
	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);
	//_CrtSetBreakAlloc(80);
#endif
	
	const int topx = 150;
	const int topy = 20;
	const int windowWidth = 1200;
	const int windowHeight = 800;
	Engine::Windows::WindowData myWindow(i_hInstance, topx, topy, windowWidth, windowHeight);

	Game::Gameplay::Gameplay* gameplay =  Game::Gameplay::Gameplay::GetGame();
	gameplay->InitializeQuadtree(windowWidth, windowHeight);
	gameplay->InitializeSprite(myWindow.AppInstance());
	gameplay->InitializeBackBuffer(myWindow.WindowHandle(), windowWidth, windowHeight);

	ShowWindow(myWindow.WindowHandle() , i_showCmd);
	UpdateWindow(myWindow.WindowHandle());
	
	Engine::Timing::Timing* timer = Engine::Timing::Timing::GetTimer();
	timer->Initialize();

	MSG msg;
	ZeroMemory(&msg, sizeof(MSG));

	while (msg.message != WM_QUIT)
	{
		if (PeekMessage(&msg, 0, 0, 0, PM_REMOVE))
		{
			TranslateMessage(&msg);
			DispatchMessage(&msg);
		}
		else
		{
			timer->OnNewFrame();
			const float dt = timer->GetElapsedSecondCount_duringPreviousFrame();
			gameplay->UpdateGameObjects(dt);
			gameplay->DrawSprites();
		}
	}

	timer->StopTimer();
	gameplay->DestroyGame();
	return (int)msg.wParam;
}