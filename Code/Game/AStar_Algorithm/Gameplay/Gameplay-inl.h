#include "Sprite/BackBuffer.h"
#include "DebugFunctions/DebugFunctions.h"
#include "GameObject/GameObject.h"

namespace Game
{
	namespace Gameplay
	{
		inline void Gameplay::InitializeBackBuffer(const HWND i_hwnd, const int i_width, const int i_height)
		{
			assert(i_hwnd != nullptr);
			
			m_backbuffer = new Engine::Sprite::BackBuffer(i_hwnd, i_width, i_height);

			DEBUG_PRINT("Created backbuffer with width %d and height %d", i_width, i_height);
		}

		inline void Gameplay::DrawSprites()
		{
			m_player->Draw(m_backbuffer->getDC(), m_spritedc);
			m_enemy->Draw(m_backbuffer->getDC(), m_spritedc);
			m_backbuffer->Present();

			DEBUG_PRINT("Drew Player and Enemy sprites");
		}
	}
}