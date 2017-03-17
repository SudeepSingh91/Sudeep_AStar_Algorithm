#include "GameObject.h"

#include <utility>

#include "../../Sprite/Sprite.h"

namespace Engine
{
	namespace GameObject
	{
		GameObject::GameObject(const HINSTANCE i_appid, const Math::Vector2& i_pos, const Physics::ObjectProperties& i_objProperty, int i_imageId, int i_maskId) 
			: m_PhysicsProperties(i_objProperty), m_pos(i_pos), m_sprite(nullptr)
		{
			m_sprite = new Sprite::Sprite(i_appid, i_imageId, i_maskId);
		}

		GameObject::GameObject(const GameObject& i_obj) : m_PhysicsProperties(i_obj.m_PhysicsProperties), m_pos(i_obj.m_pos), m_sprite(nullptr)
		{
			m_sprite = new Sprite::Sprite(*i_obj.m_sprite);
			
			DEBUG_PRINT("Called Copy constructor for Gameobject");
		}

		GameObject& GameObject::operator=(const GameObject& i_obj)
		{
			if (this != &i_obj)
			{
				m_PhysicsProperties = i_obj.m_PhysicsProperties;
				delete m_sprite;
				m_sprite = new Sprite::Sprite(*i_obj.m_sprite);

				DEBUG_PRINT("Called Assignment operator for Gameobject");
			}
			else
			{
				DEBUG_PRINT("Performed Self Assignment using Assignment operator for Gameobject");
			}

			return *this;
		}

		GameObject::GameObject(GameObject&& i_obj) : m_PhysicsProperties(i_obj.m_PhysicsProperties), m_pos(i_obj.m_pos), m_sprite(i_obj.m_sprite)
		{
			i_obj.m_sprite = nullptr;

			DEBUG_PRINT("Called Move Copy constructor for Gameobject");
		}

		GameObject& GameObject::operator=(GameObject&& i_obj)
		{
			if (this != &i_obj)
			{
				std::swap(m_PhysicsProperties, i_obj.m_PhysicsProperties);
				std::swap(m_pos, i_obj.m_pos);
				std::swap(m_sprite, i_obj.m_sprite);
				i_obj.m_sprite = nullptr;

				DEBUG_PRINT("Called Move Assignment operator for Gameobject");
			}
			else
			{
				DEBUG_PRINT("Performed Self Assignment using Move Assignment operator for Gameobject");
			}
			
			return *this;
		}

		GameObject::~GameObject()
		{
			delete m_sprite;
		}
	}
}