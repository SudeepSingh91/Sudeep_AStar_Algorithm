#include "BackBuffer.h"

#include "../DebugFunctions/DebugFunctions.h"

namespace Engine
{
	namespace Sprite
	{
		BackBuffer::BackBuffer(const HWND i_hwnd, const int i_width, const int i_height) : m_hwnd(i_hwnd), m_width(i_width), m_height(i_height)
		{
			assert(i_hwnd != nullptr);
			
			const HDC hWndDc = GetDC(m_hwnd);

			assert(hWndDc != nullptr);

			m_hdc = CreateCompatibleDC(hWndDc);

			assert(m_hdc != nullptr);

			m_hSurface = CreateCompatibleBitmap(hWndDc, m_width, m_height);

			assert(m_hSurface != nullptr);

			ReleaseDC(m_hwnd, hWndDc);

			m_hOldObject = (HBITMAP)SelectObject(m_hdc, m_hSurface);
			const HBRUSH whiteBrush = (HBRUSH)GetStockObject(WHITE_BRUSH);

			assert(whiteBrush != nullptr);

			const HBRUSH oldBrush = (HBRUSH)SelectObject(m_hdc, whiteBrush);
			Rectangle(m_hdc, 0, 0, m_width, m_height);
			SelectObject(m_hdc, oldBrush);

			DEBUG_PRINT("Constructed Back Buffer");
		}

		BackBuffer::~BackBuffer()
		{
			SelectObject(m_hdc, m_hOldObject);
			DeleteObject(m_hSurface);
			DeleteObject(m_hdc);
		}

		void BackBuffer::Present() const
		{
			HDC wndHdc = GetDC(m_hwnd);
			
			assert(wndHdc != nullptr);

			BitBlt(wndHdc, 0, 0, m_width, m_height, m_hdc, 0, 0, SRCCOPY);
			ReleaseDC(m_hwnd, wndHdc);

			DEBUG_PRINT("Presented Back Buffer to screen");
		}
	}
}