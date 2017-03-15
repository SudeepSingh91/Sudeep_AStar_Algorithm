#ifndef IGAMEOBJECTCONTROLLER_H
#define IGAMEOBJECTCONTROLLER_H

namespace Engine
{
	namespace Math
	{
		class Vector2;
	}
	
	namespace GameObject
	{	
		class IGameObjectController
		{
		public:
			virtual ~IGameObjectController() {};

			virtual void Update(const float i_dt, const Math::Vector2& i_force) = 0;
		};
	}
}

#endif