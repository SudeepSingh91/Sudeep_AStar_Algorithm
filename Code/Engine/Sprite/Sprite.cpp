#include "Sprite.h"

#include <utility>

#include "../Math/Vector2/Vector2.h"
#include "../DebugFunctions/DebugFunctions.h"

namespace Engine
{
	namespace Sprite
	{
		Sprite::Sprite(const HINSTANCE i_hinstance, const int i_imageid, const int i_maskid)
		{
			m_himage = LoadBitmap(i_hinstance, MAKEINTRESOURCE(i_imageid));
			m_hmask = LoadBitmap(i_hinstance, MAKEINTRESOURCE(i_maskid));

			assert(m_himage != nullptr);
			assert(m_hmask != nullptr);

			GetObject(m_himage, sizeof(BITMAP), &m_imagebm);
			GetObject(m_hmask, sizeof(BITMAP), &m_maskbm);

			assert(m_imagebm.bmWidth == m_maskbm.bmWidth);
			assert(m_imagebm.bmHeight == m_maskbm.bmHeight);

			DEBUG_PRINT("Constructed Sprite with imageid %d", i_imageid);
		}

		Sprite::Sprite(const Sprite& i_sprite)
		{
			m_himage = (HBITMAP)CopyImage(i_sprite.m_himage, IMAGE_BITMAP, i_sprite.width(), i_sprite.height(), LR_DEFAULTSIZE);
			m_hmask = (HBITMAP)CopyImage(i_sprite.m_hmask, IMAGE_BITMAP, i_sprite.width(), i_sprite.height(), LR_DEFAULTSIZE);

			assert(m_himage != nullptr);
			assert(m_hmask != nullptr);

			GetObject(m_himage, sizeof(BITMAP), &m_imagebm);
			GetObject(m_hmask, sizeof(BITMAP), &m_maskbm);

			assert(m_imagebm.bmWidth == m_maskbm.bmWidth);
			assert(m_imagebm.bmHeight == m_maskbm.bmHeight);

			DEBUG_PRINT("Constructed Copy Constructor for Sprite");
		}

		Sprite& Sprite::operator=(const Sprite& i_sprite)
		{
			DeleteObject(m_himage);
			DeleteObject(m_hmask);
			
			m_himage = (HBITMAP)CopyImage(i_sprite.m_himage, IMAGE_BITMAP, i_sprite.width(), i_sprite.height(), LR_DEFAULTSIZE);
			m_hmask = (HBITMAP)CopyImage(i_sprite.m_hmask, IMAGE_BITMAP, i_sprite.width(), i_sprite.height(), LR_DEFAULTSIZE);

			assert(m_himage != nullptr);
			assert(m_hmask != nullptr);

			GetObject(m_himage, sizeof(BITMAP), &m_imagebm);
			GetObject(m_hmask, sizeof(BITMAP), &m_maskbm);

			assert(m_imagebm.bmWidth == m_maskbm.bmWidth);
			assert(m_imagebm.bmHeight == m_maskbm.bmHeight);

			DEBUG_PRINT("Called Assignment operator for Sprite");

			return *this;
		}

		Sprite::~Sprite()
		{
			DeleteObject(m_himage);
			DeleteObject(m_hmask);
		}

		void Sprite::Update(float i_dt)
		{
			DEBUG_PRINT("Updated position of sprite");
		}

		void Sprite::Draw(const HDC i_backbufferDC, const HDC i_spriteDC, const Math::Vector2* const i_pos) const
		{
			assert(i_backbufferDC != nullptr);
			assert(i_spriteDC != nullptr);
			
			const int sprWidth = width();
			const int sprHeight = height();

			const int halvingValue = 2;
			const int posx = static_cast<int>(i_pos->x() - (sprWidth / halvingValue));
			const int posy = static_cast<int>(i_pos->y() - (sprHeight / halvingValue));

			const HGDIOBJ oldObj = SelectObject(i_spriteDC, m_hmask);
			BitBlt(i_backbufferDC, posx, posy, sprWidth, sprHeight, i_spriteDC, 0, 0, SRCAND);

			SelectObject(i_spriteDC, m_himage);
			BitBlt(i_backbufferDC, posx, posy, sprWidth, sprHeight, i_spriteDC, 0, 0, SRCPAINT);

			SelectObject(i_spriteDC, oldObj);

			DEBUG_PRINT("Drew sprite at position (%f, %f)", i_pos->x(), i_pos->y());
		}
	}
}