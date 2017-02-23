#include "Windows\Windows.h"

#include <Windows.h>

int WINAPI WinMain(const HINSTANCE i_hInstance, const HINSTANCE i_hprevInstance, const PSTR i_cmdLine, const int i_showCmd)
{
	Engine::Windows::WindowData myWindow(i_hInstance);

	ShowWindow(myWindow.windowHandle() , i_showCmd);
	UpdateWindow(myWindow.windowHandle());
	
	const MSG msg = myWindow.MessageLoop();

	return (int)msg.wParam;
}