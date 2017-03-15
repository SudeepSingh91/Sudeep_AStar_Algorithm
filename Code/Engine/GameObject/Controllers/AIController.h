#ifndef AICONTROLLER_H
#define AICONTROLLER_H

#include "IGameObjectController.h"

namespace Engine
{
	namespace GameObject
	{
		class GameObject;

		class AIController : public IGameObjectController 
		{
		public:
			AIController(const GameObject* const i_gameObj);
			~AIController();

			void Update(const float i_dt, const Math::Vector2& i_force) final;

		private:
			const GameObject* m_gameObj;
		};
	}
}

#endif