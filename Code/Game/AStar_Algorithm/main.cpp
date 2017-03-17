#include "GamePlay/Gameplay.h"

#include <Windows.h>

#include "Timing/Timing.h"
#include "Windows/Windows.h"

int WINAPI WinMain(const HINSTANCE i_hInstance, const HINSTANCE i_hprevInstance, const PSTR i_cmdLine, const int i_showCmd)
{
	Engine::Windows::WindowData myWindow(i_hInstance);

	Game::Gameplay::Gameplay* gameplay =  Game::Gameplay::Gameplay::GetGame();
	gameplay->InitializeSprite(myWindow.AppInstance());
	gameplay->InitializeBackBuffer(myWindow.WindowHandle(), 1200, 800);

	ShowWindow(myWindow.WindowHandle() , i_showCmd);
	UpdateWindow(myWindow.WindowHandle());
	
	Engine::Timing::Timing* timer = Engine::Timing::Timing::GetTimer();
	timer->Initialize();

	MSG msg;
	ZeroMemory(&msg, sizeof(MSG));

	while ((msg.wParam != WM_QUIT) && (!myWindow.IfEnded()))
	{
		if (PeekMessage(&msg, 0, 0, 0, PM_REMOVE))
		{
			TranslateMessage(&msg);
			DispatchMessage(&msg);
		}
		else
		{
			timer->OnNewFrame();
			float dt = timer->GetElapsedSecondCount_duringPreviousFrame();
			gameplay->UpdateGameObjects(dt);
			gameplay->DrawSprites();
		}
	}

	return (int)msg.wParam;
}