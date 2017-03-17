#include "Vector2.h"

namespace Engine
{
	namespace Math
	{
		Vector2::Vector2()
		{

		}

		Vector2::Vector2(const float i_x, const float i_y) : m_x(i_x), m_y(i_y)
		{
			
		}

		Vector2::Vector2(const Vector2& i_vec) : m_x(i_vec.m_x), m_y(i_vec.m_y)
		{
			
		}

		Vector2& Vector2::operator=(const Vector2& i_vec)
		{
			m_x = i_vec.x();
			m_y = i_vec.y();

			return *this;
		}

		Vector2::~Vector2()
		{

		}

		float Vector2::DotProduct(const Vector2& i_vec1, const Vector2& i_vec2)
		{
			return ((i_vec1.x() * i_vec2.x()) + (i_vec1.y() * i_vec2.y()));
		}
	}
}