#ifndef QUADTREE_H
#define QUADTREE_H

#include <vector>

#include "../Math/Vector2/Vector2.h"

namespace Engine
{
	namespace GameObject
	{
		class GameObject;
	}
	namespace AStar
	{
		class Quadtree
		{
		public:
			Quadtree(const Math::Vector2& i_pos, const float i_width, const float i_height);

			~Quadtree();

			inline Quadtree* NorthEast() const;
			inline Quadtree* NorthWest() const;
			inline Quadtree* SouthEast() const;
			inline Quadtree* SouthWest() const;

			bool CreateQuads(std::vector<GameObject::GameObject*>* i_gameObjList);
		private:
			Quadtree(const Quadtree& i_quadtree);
			Quadtree& operator=(const Quadtree& i_quadtree);

			bool IsObjectInside(const GameObject::GameObject* const i_gameObj);
			bool IsPointInside(const Math::Vector2& i_point);
			bool IsObjectCornerInside(const GameObject::GameObject* const i_gameObj);
			Quadtree* GetNextQuads(std::vector<GameObject::GameObject*>* i_gameObjList, const Math::Vector2& i_pos, const float i_width, const float i_height);

			const Math::Vector2 m_pos;
			const float m_width;
			const float m_height;
			Quadtree* m_northEast;
			Quadtree* m_northWest;
			Quadtree* m_southEast;
			Quadtree* m_southWest;
		};
	}
}

#include "Quadtree-inl.h"

#endif