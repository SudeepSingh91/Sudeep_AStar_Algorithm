#ifndef AICONTROLLER_H
#define AICONTROLLER_H

#include "IGameObjectController.h"

namespace Engine
{
	namespace Physics
	{
		class GameObject;

		class AIController : public IGameObjectController 
		{
		public:
			~AIController();

			void SetGameObject(const GameObject* i_gameObj) final;
			void Update(const float dt) final;

		private:
			GameObject* m_gameObj;
		};
	}
}

#endif