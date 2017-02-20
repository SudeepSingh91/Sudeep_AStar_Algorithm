#ifndef SPRITE_H
#define SPRITE_H

#include <Windows.h>

#include "../Math/Vector2/Vector2.h"

namespace Engine
{
	namespace Sprite
	{
		class Sprite
		{
		public:
			Sprite(const HINSTANCE i_hinstance, const int i_imageid, const int i_maskid, const Math::Vector2& i_pos, const Math::Vector2& i_vec);

			~Sprite();

			inline int width() const;
			inline int height() const;
			inline Math::Vector2 pos() const;
			inline Math::Vector2 vel() const;

			void Update(float i_dt);
			void Draw(const HDC i_backbufferDC, const HDC i_spriteDC) const;

		private:
			Sprite(const Sprite& i_sprite);
			Sprite& operator=(const Sprite& i_sprite);

			BITMAP m_imagebm;
			BITMAP m_maskbm;

			Math::Vector2 m_pos;
			Math::Vector2 m_vel;
			
			const HINSTANCE m_appId;
			HBITMAP m_himage;
			HBITMAP m_hmask;
		};
	}
}

#include "Sprite-inl.h"

#endif