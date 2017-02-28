#include "Gameplay.h"
#include"../../resource1.h"

#include "DebugFunctions/DebugFunctions.h"
#include "GameObject/GameObject.h"
#include "Physics/ObjectProperties/ObjectProperties.h"

namespace Game
{
	namespace Gameplay
	{
		Gameplay* Gameplay::m_gameplay = 0;

		Gameplay::Gameplay() : m_player(nullptr), m_enemy(nullptr)
		{
			
		}

		Gameplay::~Gameplay()
		{

		}

		Gameplay* Gameplay::GetGame()
		{
			if (m_gameplay == 0)
			{
				m_gameplay = new Gameplay;

				DEBUG_PRINT("Created Gameplay");
			}

			DEBUG_PRINT("Called Get Game");

			return m_gameplay;
		}

		void Gameplay::InitializeSprite(HINSTANCE i_appid)
		{
			assert(i_appid != nullptr);
			
			m_player = static_cast<Engine::GameObject::GameObject*>(_aligned_malloc(2 * sizeof(Engine::GameObject::GameObject), 64));

			assert(m_player != nullptr);

			m_enemy = m_player + 1;
			
			Engine::Physics::ObjectProperties playerprop(Engine::Math::Vector2(500.0f, 400.0f), Engine::Math::Vector2(0.0f, 0.0f), 10.0f, 0.4f);
			Engine::Physics::ObjectProperties enemyprop(Engine::Math::Vector2(700.0f, 400.0f), Engine::Math::Vector2(0.0f, 0.0f), 8.0f, 0.6f);

			*m_player = Engine::GameObject::GameObject(i_appid, playerprop, IDB_ALIEN, IDB_ALIENMASK);
			*m_enemy = Engine::GameObject::GameObject(i_appid, enemyprop, IDB_JET, IDB_JETMASK);

			m_spritedc = CreateCompatibleDC(0);

			DEBUG_PRINT("Initialized Sprites");
		}
	}
}