#ifndef SPRITE_H
#define SPRITE_H

#include <Windows.h>

namespace Engine
{
	namespace Math
	{
		class Vector2;
	}

	namespace Sprite
	{
		class Sprite
		{
		public:
			Sprite(const HINSTANCE i_hinstance, const int i_imageid, const int i_maskid);
			Sprite(const Sprite& i_sprite);
			Sprite& operator=(const Sprite& i_sprite);

			~Sprite();

			inline int width() const;
			inline int height() const;

			void Update(float i_dt);
			void Draw(const HDC i_backbufferDC, const HDC i_spriteDC, const Math::Vector2* const i_pos) const;

		private:
			BITMAP m_imagebm;
			BITMAP m_maskbm;

			HBITMAP m_himage;
			HBITMAP m_hmask;
		};
	}
}

#include "Sprite-inl.h"

#endif