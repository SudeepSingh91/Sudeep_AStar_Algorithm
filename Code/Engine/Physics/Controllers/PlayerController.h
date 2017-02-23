#ifndef PLAYERCONTROLLER_H
#define PLAYERCONTROLLER_H

#include "IGameObjectController.h"

namespace Engine
{
	namespace Physics
	{
		class GameObject;
		
		class PlayerController : public IGameObjectController
		{
		public:
			~PlayerController();

			void SetGameObject(const GameObject* i_gameObj) final;
			void Update(const float dt) final;

		private:
			GameObject* m_gameObj;
		};
	}
}

#endif