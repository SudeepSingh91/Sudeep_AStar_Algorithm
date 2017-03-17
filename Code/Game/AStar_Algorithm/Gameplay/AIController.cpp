#include "AIController.h"
#include "GameObject/GameObject/GameObject.h"

#include "Math/Vector2/Vector2.h"

namespace Engine
{
	namespace GameObject
	{
		AIController::AIController(GameObject* const i_gameObj, const size_t i_numWayPoint, const size_t i_curIndex, Math::Vector2* i_wayPoints)
			: m_numWayPoint(i_numWayPoint), m_waypointIndex(i_curIndex), m_gameObj(i_gameObj), m_wayPoint(nullptr), m_pos(nullptr), m_vel(nullptr)
		{
			m_wayPoint = new Math::Vector2[m_numWayPoint];
			for (size_t i = 0; i < m_numWayPoint; i++)
			{
				m_wayPoint[i] = i_wayPoints[i];
			}

			m_pos = new Math::Vector2;
			m_vel = new Math::Vector2;
		}
		
		AIController::~AIController()
		{
			delete[] m_wayPoint;
			delete m_pos;
			delete m_vel;
		}

		void AIController::Update(const float i_dt, const Math::Vector2& i_force)
		{

		}
	}
}