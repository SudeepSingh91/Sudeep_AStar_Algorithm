#include "Gameplay.h"
#include "resource1.h"

#include "DebugFunctions/DebugFunctions.h"
#include "GameObject/GameObject/GameObject.h"
#include "PlayerController.h"
#include "Physics/ObjectProperties/ObjectProperties.h"
#include "UserInput/UserInput.h"

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
			
			using namespace Engine;

			m_player = static_cast<GameObject::GameObject*>(_aligned_malloc(2 * sizeof(GameObject::GameObject), 64));

			assert(m_player != nullptr);

			m_enemy = m_player + 1;
			
			Math::Vector2 playerpos(500.0f, 400.0f);
			Math::Vector2 enemypos(700.0f, 400.0f);

			Physics::ObjectProperties playerprop(Math::Vector2(0.0f, 0.0f), 80.0f, 0.8f);
			Physics::ObjectProperties enemyprop(Math::Vector2(0.0f, 0.0f), 60.0f, 0.6f);

			*m_player = GameObject::GameObject(i_appid, playerpos, playerprop, IDB_ALIEN, IDB_ALIENMASK);
			*m_enemy = GameObject::GameObject(i_appid, enemypos, enemyprop, IDB_JET, IDB_JETMASK);

			m_playerController = new GameObject::PlayerController(m_player);

			m_spritedc = CreateCompatibleDC(0);

			DEBUG_PRINT("Initialized Sprites");
		}

		void Gameplay::UpdateGameObjects(const float i_dt)
		{
			using namespace Engine;
			
			Math::Vector2 playerForce(0.0f, 0.0f);

			if (UserInput::IsKeyPressed('W'))
			{
				playerForce = playerForce + Math::Vector2(0.0f, -10.0f);
			}
			else if (UserInput::IsKeyPressed('A'))
			{
				playerForce = playerForce + Math::Vector2(-10.0f, 0.0f);
			}
			else if (UserInput::IsKeyPressed('D'))
			{
				playerForce = playerForce + Math::Vector2(10.0f, 0.0f);
			}
			else if (UserInput::IsKeyPressed('S'))
			{
				playerForce = playerForce + Math::Vector2(0.0f, 10.0f);
			}

			m_playerController->Update(i_dt, playerForce);
		}
	}
}