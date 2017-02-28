#include "GamePlay/Gameplay.h"

#include <Windows.h>

#include "Windows/Windows.h"

int WINAPI WinMain(const HINSTANCE i_hInstance, const HINSTANCE i_hprevInstance, const PSTR i_cmdLine, const int i_showCmd)
{
	Engine::Windows::WindowData myWindow(i_hInstance);

	Game::Gameplay::Gameplay* gameplay =  Game::Gameplay::Gameplay::GetGame();
	gameplay->InitializeSprite(myWindow.appInstance());
	gameplay->InitializeBackBuffer(myWindow.windowHandle(), 1200, 800);

	ShowWindow(myWindow.windowHandle() , i_showCmd);
	UpdateWindow(myWindow.windowHandle());
	
	gameplay->DrawSprites();

	const MSG msg = myWindow.MessageLoop();

	return (int)msg.wParam;
}