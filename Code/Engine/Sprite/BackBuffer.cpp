#include "BackBuffer.h"

namespace Engine
{
	namespace Sprite
	{
		BackBuffer::BackBuffer(const HWND i_hwnd, const int i_width, const int i_height) : m_hwnd(i_hwnd), m_width(i_width), m_height(i_height)
		{
			HDC hWndDc = GetDC(m_hwnd);

			m_hdc = CreateCompatibleDC(hWndDc);
			m_hSurface = CreateCompatibleBitmap(hWndDc, m_width, m_height);

			ReleaseDC(m_hwnd, hWndDc);

			
		}

		BackBuffer::~BackBuffer()
		{

		}

		
	}
}