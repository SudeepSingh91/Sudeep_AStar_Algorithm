#ifndef GAMEPLAY_H
#define GAMEPLAY_H

#include <Windows.h>

namespace Engine
{
	namespace GameObject
	{
		class GameObject;
	}

	namespace Sprite
	{
		class BackBuffer;
	}
}

namespace Game
{
	namespace Gameplay
	{		
		class Gameplay
		{
		public:
			static Gameplay* GetGame();
			~Gameplay();

			void InitializeSprite(HINSTANCE i_appid);
			inline void InitializeBackBuffer(const HWND i_hwnd, const int i_width, const int i_height);
			inline void DrawSprites();
			//void UpdateGameObjects(const float dt);

		private:
			Gameplay();
			Gameplay(const Gameplay& i_gameplay);
			Gameplay operator=(const Gameplay& i_gameplay);

			static Gameplay* m_gameplay;

			Engine::GameObject::GameObject* m_player;
			Engine::GameObject::GameObject* m_enemy;
			Engine::Sprite::BackBuffer* m_backbuffer;
			HDC m_spritedc;
		};
	}
}

#include "Gameplay-inl.h"

#endif