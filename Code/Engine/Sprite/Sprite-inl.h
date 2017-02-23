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
	}
}