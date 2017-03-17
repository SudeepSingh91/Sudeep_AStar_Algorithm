#ifndef PLAYERCONTROLLER_H
#define PLAYERCONTROLLER_H

#include "GameObject/Controllers/IGameObjectController.h"

namespace Engine
{
	namespace GameObject
	{
		class GameObject;
		
		class PlayerController : public IGameObjectController
		{
		public:
			PlayerController(GameObject* const i_gameObj);
			~PlayerController();

			void Update(const float i_dt, const Math::Vector2& i_force) final;

		private:
			GameObject* const m_gameObj;
			Math::Vector2* m_pos;
			Math::Vector2* m_vel;
		};
	}
}

#endif