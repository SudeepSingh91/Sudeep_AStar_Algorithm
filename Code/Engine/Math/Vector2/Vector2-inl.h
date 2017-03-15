#include <math.h>

#include "../../DebugFunctions/DebugFunctions.h"

namespace Engine
{
	namespace Math
	{
		inline float Vector2::x() const
		{
			return m_x;
		}

		inline float Vector2::y() const
		{
			return m_y;
		}

		inline void Vector2::x(const float i_x)
		{
			m_x = i_x;
		}

		inline void Vector2::y(const float i_y)
		{
			m_y = i_y;
		}

		inline double Vector2::Length() const
		{
			return sqrt((m_x * m_x) + (m_y * m_y));
		}

		inline Vector2 Vector2::operator+(const Vector2& i_vec) const
		{
			return Vector2((m_x + i_vec.x()), (m_y + i_vec.y()));
		}

		inline Vector2 Vector2::operator-(const Vector2& i_vec) const
		{
			return Vector2((m_x - i_vec.x()), (m_y - i_vec.y()));
		}

		inline Vector2 Vector2::operator/(const float i_scalar) const
		{
			assert(i_scalar != 0.0f);
			
			return Vector2((m_x / i_scalar), (m_y / i_scalar));
		}

		inline Vector2 Vector2::operator*(const float i_scalar) const
		{
			return Vector2((m_x * i_scalar), (m_y * i_scalar));
		}

		inline Vector2& Vector2::operator+=(const Vector2& i_vec)
		{
			m_x = m_x + i_vec.x();
			m_y = m_y + i_vec.y();

			return *this;
		}

		inline Vector2& Vector2::operator-=(const Vector2& i_vec)
		{
			m_x = m_x - i_vec.x();
			m_y = m_y - i_vec.y();

			return *this;
		}

		inline bool Vector2::operator==(const Vector2& i_vec)
		{
			return ((m_x == i_vec.x()) && (m_y == i_vec.y()));
		}
	}
}