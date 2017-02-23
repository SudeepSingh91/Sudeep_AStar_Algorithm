#include "Windows.h"

#include "../DebugFunctions/DebugFunctions.h"

namespace Engine
{
	namespace Windows
	{
		LRESULT CALLBACK WndProc(const HWND i_hWnd, const UINT i_msg, const WPARAM i_wParam, const LPARAM i_lParam)
		{
			switch (i_msg)
			{
			case WM_KEYDOWN:
				if (i_wParam == VK_ESCAPE)
				{
					DEBUG_PRINT("Pressed Escape");
					::DestroyWindow(i_hWnd);
				}
				return 0;
			case WM_DESTROY:
				DEBUG_PRINT("Pressed close button on top right of window");
				PostQuitMessage(0);
				return 0;
			}

			return DefWindowProc(i_hWnd, i_msg, i_wParam, i_lParam);
		}
		
		WindowData::WindowData(const HINSTANCE i_hinstance) : m_appInstance(i_hinstance)
		{
			assert(i_hinstance != nullptr);

			LOGBRUSH lb;
			lb.lbStyle = BS_SOLID;
			lb.lbColor = RGB(51, 51, 255);
			const HBRUSH blueBrush = CreateBrushIndirect(&lb);

			assert(blueBrush != NULL);

			WNDCLASS wc;
			wc.style = CS_HREDRAW | CS_VREDRAW;
			wc.lpfnWndProc = WndProc;
			wc.cbWndExtra = 0;
			wc.cbClsExtra = 0;
			wc.hInstance = m_appInstance;
			wc.hIcon = LoadIcon(0, IDI_APPLICATION);
			wc.hCursor = LoadCursor(0, IDC_ARROW);
			wc.hbrBackground = blueBrush;
			wc.lpszMenuName = 0;
			wc.lpszClassName = "AStar_WindowClass";

			RegisterClass(&wc);

			m_windowHandle = ::CreateWindow("AStar_WindowClass", "AStar_Window", WS_OVERLAPPEDWINDOW, 100, 20, 1200, 800, 0, 0, m_appInstance, 0);

			assert(m_windowHandle != 0);

			DEBUG_PRINT("Created main window");
		}

		HINSTANCE WindowData::appInstance()
		{
			return m_appInstance;
		}

		HWND WindowData::windowHandle()
		{
			return m_windowHandle;
		}

		MSG WindowData::MessageLoop()
		{
			MSG msg;
			ZeroMemory(&msg, sizeof(MSG));

			while (GetMessage(&msg, 0, 0, 0))
			{
				TranslateMessage(&msg);
				DispatchMessage(&msg);
			}

			return msg;
		}
	}
}