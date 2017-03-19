#include "Gameplay.h"
#include "resource1.h"

#include <vector>

#include "DebugFunctions/DebugFunctions.h"
#include "GameObject/GameObject/GameObject.h"
#include "PlayerController.h"
#include "Physics/ObjectProperties/ObjectProperties.h"
#include "UserInput/UserInput.h"
#include "Quadtree/Quadtree.h"

namespace Game
{
	namespace Gameplay
	{
		Gameplay* Gameplay::m_gameplay = nullptr;

		Gameplay::Gameplay() : m_player(nullptr), m_enemy(nullptr), m_playerController(nullptr), m_backbuffer(nullptr), m_quadtree(nullptr), m_spritedc(nullptr)
		{
			
		}

		Gameplay::~Gameplay()
		{
			if (m_player != nullptr)
			{
				delete m_player;
			}
			if (m_enemy != nullptr)
			{
				delete m_enemy;
			}
			if (m_playerController != nullptr)
			{
				delete m_playerController;
			}
			if (m_backbuffer != nullptr)
			{
				delete m_backbuffer;
			}
		}

		Gameplay* Gameplay::GetGame()
		{
			if (m_gameplay == nullptr)
			{
				m_gameplay = new Gameplay;

				DEBUG_PRINT("Created Gameplay");
			}

			DEBUG_PRINT("Called Get Game");

			return m_gameplay;
		}

		void Gameplay::DestroyGame()
		{
			if (m_gameplay != nullptr)
			{
				delete m_gameplay;

				DEBUG_PRINT("Destroyed Gameplay");
			}
			else
			{
				DEBUG_PRINT("Gameplay does not exist fro destruction");
			}
		}

		void Gameplay::InitializeQuadtree(const int i_width, const int i_height)
		{
			float width = static_cast<float>(i_width);
			float height = static_cast<float>(i_height);
			Engine::Math::Vector2 pos(width / 2.0f, height / 2.0f);
			m_quadtree = new Engine::AStar::Quadtree(pos, width, height);
		}

		void Gameplay::InitializeSprite(HINSTANCE i_appid)
		{
			assert(i_appid != nullptr);
			
			using namespace Engine;
			
			Math::Vector2 playerpos(50.0f, 50.0f);
			Math::Vector2 enemypos(900.0f, 600.0f);

			Physics::ObjectProperties playerprop(Math::Vector2(0.0f, 0.0f), 80.0f, 0.8f);
			Physics::ObjectProperties enemyprop(Math::Vector2(0.0f, 0.0f), 60.0f, 0.6f);

			m_player = new GameObject::GameObject(i_appid, playerpos, playerprop, IDB_ALIEN, IDB_ALIENMASK);
			m_enemy = new GameObject::GameObject(i_appid, enemypos, enemyprop, IDB_JET, IDB_JETMASK);

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
			else if (UserInput::IsKeyPressed('Q'))
			{
				GenerateQuadtree();
			}

			m_playerController->Update(i_dt, playerForce);
		}

		void Gameplay::GenerateQuadtree()
		{
			std::vector<Engine::GameObject::GameObject*> gameObjList;
			gameObjList.push_back(m_player);
			m_quadtree->CreateQuads(&gameObjList);
		}
	}
}