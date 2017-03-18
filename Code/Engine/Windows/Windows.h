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
			WindowData(const HINSTANCE i_hinstance, const int i_topx, const int i_topy, const int i_width, const int i_height);

			inline HINSTANCE AppInstance() const;
			inline HWND WindowHandle() const;

		private:
			WindowData(const WindowData& i_windowData);
			WindowData& operator=(const WindowData& i_windowData);

			const HINSTANCE m_appInstance;
			HWND m_windowHandle;
		};
	}
}

#include "Windows-inl.h"

#endif