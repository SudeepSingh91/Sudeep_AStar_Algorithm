#include "PlayerController.h"
#include "GameObject/GameObject/GameObject.h"

#include "Math/Vector2/Vector2.h"

namespace Engine
{
	namespace GameObject
	{
		PlayerController::PlayerController(GameObject* const i_gameObj) : m_gameObj(i_gameObj), m_pos(nullptr), m_vel(nullptr)
		{
			m_pos = new Math::Vector2;
			m_vel = new Math::Vector2;
		}
		
		PlayerController::~PlayerController()
		{
			delete m_pos;
			delete m_vel;
		}

		void PlayerController::Update(const float i_dt, const Math::Vector2& i_force)
		{
			*m_vel = m_gameObj->Vel() + (((i_force - (m_gameObj->Vel() * m_gameObj->Drag())) / m_gameObj->Mass()) * i_dt);
			m_gameObj->Vel((*m_vel + m_gameObj->Vel()) / 2.0f);
			*m_pos = m_gameObj->Pos() + m_gameObj->Vel();
			m_gameObj->Pos(*m_pos);
		}
	}
}