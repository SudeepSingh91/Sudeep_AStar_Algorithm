#ifndef OBJECTPROPERTIES_H
#define OBJECTPROPERTIES_H

#include "../../Math/Vector2/Vector2.h"

namespace Engine
{
	namespace Physics
	{
		struct ObjectProperties
		{
			Math::Vector2 m_vel;
			float m_mass;
			float m_drag;

			ObjectProperties();
			ObjectProperties(const Math::Vector2& i_vel, const float i_mass, const float i_drag);
			ObjectProperties(const ObjectProperties& i_objProperty);
			ObjectProperties& operator=(const ObjectProperties& i_objProperty);
		};
	}
}

#endif