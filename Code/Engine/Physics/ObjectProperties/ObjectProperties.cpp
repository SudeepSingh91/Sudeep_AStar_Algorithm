#include "ObjectProperties.h"

namespace Engine
{
	namespace Physics
	{
		ObjectProperties::ObjectProperties()
		{

		}
		
		ObjectProperties::ObjectProperties(const Math::Vector2& i_pos, const Math::Vector2& i_vel, const float i_mass, const float i_drag) :
			m_pos(i_pos), m_vel(i_vel), m_mass(i_mass), m_drag(i_drag)
		{
			assert(i_mass > 0.0f);
			assert(i_drag > 0.0f);

			DEBUG_PRINT("Constructed object properties with mass %f and drag %f", m_mass, m_drag);
		}

		ObjectProperties::ObjectProperties(const ObjectProperties& i_objProperty) 
			: m_pos(i_objProperty.m_pos), m_vel(i_objProperty.m_vel), m_mass(i_objProperty.m_mass), m_drag(i_objProperty.m_drag)
		{
			DEBUG_PRINT("Called Copy constructor for object properties with mass %f and drag %f", m_mass, m_drag);
		}
	}
}