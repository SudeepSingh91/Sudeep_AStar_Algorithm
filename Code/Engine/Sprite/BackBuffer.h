#ifndef BACKBUFFER_H
#define BACKBUFFER_H

#include <Windows.h>

namespace Engine
{
	namespace Sprite
	{
		class BackBuffer
		{
		public:
			BackBuffer(const HWND i_hwnd, const int i_width, const int i_height);
			~BackBuffer();

			inline HDC getDC() const;
			inline int width() const;
			inline int height() const;

			void Present() const;

		private:
			BackBuffer(const BackBuffer& i_buffer);
			BackBuffer operator=(const BackBuffer& i_buffer);

			const HWND m_hwnd;
			HDC m_hdc;
			HBITMAP m_hSurface;
			HBITMAP m_hOldObject;
			const int m_width;
			const int m_height;
		};
	}
}

#include "BackBuffer-inl.h"

#endif