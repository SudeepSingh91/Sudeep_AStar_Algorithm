#ifndef AICONTROLLER_H
#define AICONTROLLER_H

#include "GameObject/Controllers/IGameObjectController.h"

#include <stdint.h>

namespace Engine
{
	namespace GameObject
	{
		class GameObject;

		class AIController : public IGameObjectController 
		{
		public:
			AIController(GameObject* const i_gameObj, const size_t i_numWayPoint, const size_t i_curIndex, Math::Vector2* i_wayPoints);
			~AIController();

			void Update(const float i_dt, const Math::Vector2& i_force) final;

		private:
			const size_t m_numWayPoint;
			size_t m_waypointIndex;
			GameObject* const m_gameObj;
			Math::Vector2* m_wayPoint;
			Math::Vector2* m_pos;
			Math::Vector2* m_vel;
		};
	}
}

#endif