#include "PlayerController.h"

namespace Engine
{
	namespace Physics
	{
		PlayerController::~PlayerController()
		{

		}

		void PlayerController::SetGameObject(const GameObject* i_gameObj)
		{
			m_gameObj = const_cast<GameObject*>(i_gameObj);
		}

		void PlayerController::Update(const float dt)
		{

		}
	}
}