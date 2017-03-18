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
	}
}