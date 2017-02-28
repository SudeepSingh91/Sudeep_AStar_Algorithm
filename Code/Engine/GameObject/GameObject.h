#ifndef GAMEOBJECT_H
#define GAMEOBJECT_H

#include <Windows.h>

#include "../Physics/ObjectProperties/ObjectProperties.h"

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
			GameObject(const HINSTANCE i_appid, const Physics::ObjectProperties& i_objProperty, int i_imageId, int i_maskId);
			GameObject(const GameObject& i_obj);
			GameObject& operator=(const GameObject& i_obj);

			GameObject(GameObject&& i_obj);
			GameObject& operator=(GameObject&& i_obj);

			~GameObject();

			inline void Draw(const HDC i_backbufferDC, const HDC i_spriteDC);

		private:
			Physics::ObjectProperties m_PhysicsProperties;
			Sprite::Sprite* m_sprite;
		};
	}
}

#include "GameObject-inl.h"

#endif