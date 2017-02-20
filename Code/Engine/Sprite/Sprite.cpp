#include "Sprite.h"

#include "../DebugFunctions/DebugFunctions.h"

namespace Engine
{
	namespace Sprite
	{
		Sprite::Sprite(const HINSTANCE i_hinstance, const int i_imageid, const int i_maskid, const Math::Vector2& i_pos, const Math::Vector2& i_vel) : m_appId(i_hinstance), m_pos(i_pos), m_vel(i_vel)
		{
			m_himage = LoadBitmap(m_appId, MAKEINTRESOURCE(i_imageid));
			m_hmask = LoadBitmap(m_appId, MAKEINTRESOURCE(i_maskid));

			assert(m_himage != nullptr);
			assert(m_hmask != nullptr);

			GetObject(m_himage, sizeof(BITMAP), &m_imagebm);
			GetObject(m_hmask, sizeof(BITMAP), &m_maskbm);

			assert(m_imagebm.bmWidth == m_maskbm.bmWidth);
			assert(m_imagebm.bmHeight == m_maskbm.bmHeight);

			DEBUG_PRINT("Constructed Sprite with imageid %d", i_imageid);
		}

		Sprite::~Sprite()
		{
			DeleteObject(m_himage);
			DeleteObject(m_hmask);
		}

		void Sprite::Update(float i_dt)
		{
			m_pos += m_vel * i_dt;

			DEBUG_PRINT("Updated position of sprite to (%f, %f)", m_pos.x(), m_pos.y());
		}

		void Sprite::Draw(const HDC i_backbufferDC, const HDC i_spriteDC) const
		{
			assert(i_backbufferDC != nullptr);
			assert(i_spriteDC != nullptr);
			
			const int sprWidth = width();
			const int sprHeight = height();

			const int halvingValue = 2;
			const int posx = static_cast<float>(m_pos.x() - (sprWidth / halvingValue));
			const int posy = static_cast<float>(m_pos.y() - (sprHeight / halvingValue));

			const HGDIOBJ oldObj = SelectObject(i_spriteDC, m_hmask);
			BitBlt(i_backbufferDC, posx, posy, sprWidth, sprHeight, i_spriteDC, 0, 0, SRCAND);

			SelectObject(i_spriteDC, m_himage);
			BitBlt(i_backbufferDC, posx, posy, sprWidth, sprHeight, i_spriteDC, 0, 0, SRCPAINT);

			SelectObject(i_spriteDC, oldObj);

			DEBUG_PRINT("Drew sprite at position (%f, %f)", m_pos.x(), m_pos.y());
		}
	}
}