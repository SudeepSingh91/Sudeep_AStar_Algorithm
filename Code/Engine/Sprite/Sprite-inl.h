namespace Engine
{
	namespace Sprite
	{
		inline int Sprite::width() const
		{
			return m_imagebm.bmWidth;
		}

		inline int Sprite::height() const
		{
			return m_imagebm.bmHeight;
		}

		inline Math::Vector2 Sprite::pos() const
		{
			return m_pos;
		}

		inline Math::Vector2 Sprite::vel() const
		{
			return m_vel;
		}
	}
}