#include "../../Sprite/Sprite.h"

namespace Engine
{
	namespace GameObject
	{
		inline float GameObject::Drag() const
		{
			return m_PhysicsProperties.m_drag;
		}
		
		inline float GameObject::Mass() const
		{
			return m_PhysicsProperties.m_mass;
		}

		inline Math::Vector2 GameObject::Pos() const
		{
			return m_pos;
		}

		inline Math::Vector2 GameObject::Vel() const
		{
			return m_PhysicsProperties.m_vel;
		}

		inline void GameObject::Drag(const float i_drag)
		{
			m_PhysicsProperties.m_drag = i_drag;
		}

		inline void GameObject::Mass(const float i_mass)
		{
			m_PhysicsProperties.m_mass = i_mass;
		}

		inline void GameObject::Pos(const Math::Vector2& i_pos)
		{
			m_pos = i_pos;
		}

		inline void GameObject::Vel(const Math::Vector2& i_vel)
		{
			m_PhysicsProperties.m_vel = i_vel;
		}

		inline void GameObject::Draw(const HDC i_backbufferDC, const HDC i_spriteDC)
		{
			assert(i_backbufferDC != nullptr);
			assert(i_spriteDC != nullptr);
			
			m_sprite->Draw(i_backbufferDC, i_spriteDC, &m_pos);
		}
	}
}