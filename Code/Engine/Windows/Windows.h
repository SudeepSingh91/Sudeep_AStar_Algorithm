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

			static inline void SetEnded(const bool i_ifEnded);

			inline HINSTANCE AppInstance() const;
			inline HWND WindowHandle() const;
			inline bool IfEnded() const;

		private:
			WindowData(const WindowData& i_windowData);
			WindowData& operator=(const WindowData& i_windowData);

			static bool m_hasEnded;

			const HINSTANCE m_appInstance;
			HWND m_windowHandle;
		};
	}
}

#include "Windows-inl.h"

#endif