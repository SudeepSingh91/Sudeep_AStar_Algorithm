namespace Engine
{
	namespace Windows
	{
		inline HINSTANCE WindowData::AppInstance() const
		{
			return m_appInstance;
		}

		inline HWND WindowData::WindowHandle() const
		{
			return m_windowHandle;
		}

		inline bool WindowData::IfEnded() const
		{
			return m_hasEnded;
		}

		inline void WindowData::SetEnded(const bool i_ifEnded)
		{
			m_hasEnded = i_ifEnded;
		}
	}
}