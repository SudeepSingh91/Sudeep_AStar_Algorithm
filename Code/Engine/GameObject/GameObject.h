#ifndef GAMEOBJECT_H
#define GAMEOBJECT_H

#include "../Physics/ObjectProperties/ObjectProperties.h"

#include <Windows.h>

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
			GameObject(const Physics::ObjectProperties& i_objProperty, int i_imageId, int i_maskId);
			GameObject(const GameObject& i_obj);
			GameObject& operator=(const GameObject& i_obj);

			GameObject();

		private:
			HINSTANCE m_appId;
			Physics::ObjectProperties m_PhysicsProperties;
			Sprite::Sprite* m_sprite;
		};
	}
}

#endif