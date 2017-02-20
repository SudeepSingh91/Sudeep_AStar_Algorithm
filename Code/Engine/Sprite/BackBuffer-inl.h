namespace Engine
{
	namespace Sprite
	{
		inline HDC BackBuffer::getDC() const
		{
			return m_hdc;
		}

		inline int BackBuffer::width() const
		{
			return m_width;
		}

		inline int BackBuffer::height() const
		{
			return m_height;
		}
	}
}