#include "PlayerController.h"
#include "../GameObject/GameObject.h"

#include "../../Math/Vector2/Vector2.h"

namespace Engine
{
	namespace GameObject
	{
		PlayerController::PlayerController(const GameObject* const i_gameObj) : m_gameObj(const_cast<GameObject*>(i_gameObj))
		{

		}
		
		PlayerController::~PlayerController()
		{

		}

		void PlayerController::Update(const float i_dt, const Math::Vector2& i_force)
		{
			const Math::Vector2 acc = i_force / m_gameObj->Mass();
			const Math::Vector2 newVel = m_gameObj->Vel() + (acc * i_dt);
			m_gameObj->Vel(newVel * m_gameObj->Drag());

			const Math::Vector2 newPos = m_gameObj->Pos() + m_gameObj->Vel();
			m_gameObj->Pos(newPos);
		}
	}
}