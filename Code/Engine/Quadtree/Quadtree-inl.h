namespace Engine
{
	namespace AStar
	{
		inline Quadtree* Quadtree::NorthEast() const
		{
			return m_northEast;
		}

		inline Quadtree* Quadtree::NorthWest() const
		{
			return m_northWest;
		}

		inline Quadtree* Quadtree::SouthEast() const
		{
			return m_southEast;
		}

		inline Quadtree* Quadtree::SouthWest() const
		{
			return m_southWest;
		}
	}
}