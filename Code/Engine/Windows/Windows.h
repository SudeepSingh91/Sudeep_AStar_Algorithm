#ifndef WINDOWS_H
#define WINDOWS_H

#include <Windows.h>

namespace Engine
{
	namespace Windows
	{
		class WindowData
		{
		public:
			WindowData(const HINSTANCE i_hinstance);

			HINSTANCE appInstance();
			HWND windowHandle();

			MSG MessageLoop();

		private:
			WindowData(const WindowData& i_windowData);
			WindowData& operator=(const WindowData& i_windowData);

			const HINSTANCE m_appInstance;
			HWND m_windowHandle;
		};
	}
}

#endif