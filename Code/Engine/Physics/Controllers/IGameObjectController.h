#ifndef IGAMEOBJECTCONTROLLER_H
#define IGAMEOBJECTCONTROLLER_H

namespace Engine
{
	namespace Physics
	{
		class GameObject;
		
		class IGameObjectController
		{
		public:
			virtual ~IGameObjectController() = 0;

			virtual void SetGameObject(const GameObject* i_gameObj) = 0;
			virtual void Update(const float dt) = 0;
		};
	}
}

#endif