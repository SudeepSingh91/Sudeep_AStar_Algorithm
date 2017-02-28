#include "../Sprite/Sprite.h"

namespace Engine
{
	namespace GameObject
	{
		inline void GameObject::Draw(const HDC i_backbufferDC, const HDC i_spriteDC)
		{
			assert(i_backbufferDC != nullptr);
			assert(i_spriteDC != nullptr);
			
			m_sprite->Draw(i_backbufferDC, i_spriteDC, &m_PhysicsProperties.m_pos);
		}
	}
}