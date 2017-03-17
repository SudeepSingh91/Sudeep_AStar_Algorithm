#ifndef GAMEOBJECT_H
#define GAMEOBJECT_H

#include <Windows.h>

#include "../../Physics/ObjectProperties/ObjectProperties.h"

namespace Engine
{
	namespace Sprite
	{
		class Sprite;
	}

	namespace GameObject
	{	
		class GameObject
		{
		public:
			GameObject(const HINSTANCE i_appid, const Math::Vector2& i_pos, const Physics::ObjectProperties& i_objProperty, int i_imageId, int i_maskId);
			GameObject(const GameObject& i_obj);
			GameObject& operator=(const GameObject& i_obj);

			GameObject(GameObject&& i_obj);
			GameObject& operator=(GameObject&& i_obj);

			~GameObject();

			inline float Drag() const;
			inline float Mass() const;
			inline Math::Vector2 Pos() const;
			inline Math::Vector2 Vel() const;

			inline void Drag(const float i_drag);
			inline void Mass(const float i_mass);
			inline void Pos(const Math::Vector2& i_pos);
			inline void Vel(const Math::Vector2& i_vel);

			inline void Draw(const HDC i_backbufferDC, const HDC i_spriteDC);

		private:
			Physics::ObjectProperties m_PhysicsProperties;
			Math::Vector2 m_pos;
			Sprite::Sprite* m_sprite;
		};
	}
}

#include "GameObject-inl.h"

#endif