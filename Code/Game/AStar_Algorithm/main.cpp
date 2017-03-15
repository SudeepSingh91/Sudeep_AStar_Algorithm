#include "GamePlay/Gameplay.h"

#include <Windows.h>

#include "Timing/Timing.h"
#include "Windows/Windows.h"

int WINAPI WinMain(const HINSTANCE i_hInstance, const HINSTANCE i_hprevInstance, const PSTR i_cmdLine, const int i_showCmd)
{
	Engine::Windows::WindowData myWindow(i_hInstance);

	Game::Gameplay::Gameplay* gameplay =  Game::Gameplay::Gameplay::GetGame();
	gameplay->InitializeSprite(myWindow.appInstance());
	gameplay->InitializeBackBuffer(myWindow.windowHandle(), 1200, 800);

	ShowWindow(myWindow.windowHandle() , i_showCmd);
	UpdateWindow(myWindow.windowHandle());
	
	Engine::Timing::Timing* timer = Engine::Timing::Timing::GetTimer();
	timer->Initialize();
	float dt = timer->GetElapsedSecondCount_duringPreviousFrame();

	//const MSG msg = myWindow.MessageLoop();

	MSG msg;
	ZeroMemory(&msg, sizeof(MSG));

	while (GetMessage(&msg, 0, 0, 0))
	{
		TranslateMessage(&msg);
		DispatchMessage(&msg);

		gameplay->UpdateGameObjects(dt);
		gameplay->DrawSprites();
		dt = timer->GetElapsedSecondCount_duringPreviousFrame();
	}

	return (int)msg.wParam;
}