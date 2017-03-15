#ifndef VECTOR2_H
#define VECTOR2_H

namespace Engine
{
	namespace Math
	{
		class Vector2
		{
		public:
			Vector2();
			Vector2(const float i_x, const float i_y);

			Vector2(const Vector2& i_vec);
			Vector2& operator=(const Vector2& i_vec);

			~Vector2();

			inline float x() const;
			inline float y() const;

			inline void x(const float i_x);
			inline void y(const float i_y);

			inline double Length() const;

			inline Vector2 operator+(const Vector2& i_vec) const;
			inline Vector2 operator-(const Vector2& i_vec) const;

			inline Vector2 operator/(const float i_scalar) const;
			inline Vector2 operator*(const float i_scalar) const;

			inline Vector2& operator+=(const Vector2& i_vec);
			inline Vector2& operator-=(const Vector2& i_vec);
			inline bool operator==(const Vector2& i_vec);

			static float DotProduct(const Vector2& i_vec1, const Vector2& i_vec2);

		private:
			float m_x;
			float m_y;
		};
	}
}

#include "Vector2-inl.h"

#endif