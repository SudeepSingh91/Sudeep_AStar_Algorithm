#include "AIController.h"

namespace Engine
{
	namespace Physics
	{
		AIController::~AIController()
		{

		}

		void AIController::SetGameObject(const GameObject* i_gameObj)
		{
			m_gameObj = const_cast<GameObject*>(i_gameObj);
		}

		void AIController::Update(const float dt)
		{

		}
	}
}