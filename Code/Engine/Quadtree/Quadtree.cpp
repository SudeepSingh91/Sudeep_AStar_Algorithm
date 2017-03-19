#include "Quadtree.h"

#include <cmath>

#include "../DebugFunctions/DebugFunctions.h"
#include "../GameObject/GameObject/GameObject.h"

namespace Engine
{
	namespace AStar
	{
		Quadtree::Quadtree(const Math::Vector2& i_pos, const float i_width, const float i_height)
			: m_pos(i_pos), m_width(i_width), m_height(i_height), m_northEast(nullptr), m_northWest(nullptr), m_southEast(nullptr), m_southWest(nullptr)
		{

		}

		Quadtree::~Quadtree()
		{

		}

		Quadtree* GetNextQuads(std::vector<GameObject::GameObject*>* i_gameObjList, const Math::Vector2& i_pos, const float i_width, const float i_height)
		{
			Quadtree* node = new Quadtree(i_pos, i_width, i_height);
			if (!node->CreateQuads(i_gameObjList))
			{
				return nullptr;
			}

			return node;
		}

		bool Quadtree::IsObjectInside(const GameObject::GameObject* const i_gameObj)
		{
			assert(i_gameObj != nullptr);

			float cenDistX = abs(m_pos.x() - i_gameObj->Pos().x());
			float sumExtX = (m_width / 2.0f) + (i_gameObj->Width() / 2.0f);
			float cenDistY = abs(m_pos.y() - i_gameObj->Pos().y());
			float sumExtY = (m_height / 2.0f) + (i_gameObj->Height() / 2.0f);

			if ((cenDistX <= sumExtX) && (cenDistY <= sumExtY))
			{
				return true;
			}
			else
			{
				return false;
			}
		}

		bool Quadtree::CreateQuads(std::vector<GameObject::GameObject*>* i_gameObjList)
		{
			assert(i_gameObjList->size != 0);

			for (size_t i = 0; i < i_gameObjList->size; i++)
			{
				if (IsObjectInside(i_gameObjList->at[i]))
				{
					if (IsObjectCornerInside(i_gameObjList->at[i]))
					{
						DEBUG_PRINT("\Quad at (%f, &f) is partially filled", m_pos.x(), m_pos.y());

						const Math::Vector2 leftTop = Math::Vector2(m_pos.x() - (m_width / 2.0f), m_pos.y() - (m_height / 2.0f));
						const Math::Vector2 leftBottom = Math::Vector2(m_pos.x() - (m_width / 2.0f), m_pos.y() + (m_height / 2.0f));
						const Math::Vector2 rightTop = Math::Vector2(m_pos.x() + (m_width / 2.0f), m_pos.y() - (m_height / 2.0f));
						const Math::Vector2 rightBottom = Math::Vector2(m_pos.x() + (m_width / 2.0f), m_pos.y() + (m_height / 2.0f));
						const float halfWidth = m_width / 2.0f;
						const float halfHeight = m_height / 2.0f;

						m_northEast = GetNextQuads(i_gameObjList, rightTop, halfWidth, halfHeight);
						m_northWest = GetNextQuads(i_gameObjList, leftTop, halfWidth, halfHeight);
						m_southEast = GetNextQuads(i_gameObjList, rightBottom, halfWidth, halfHeight);
						m_southWest = GetNextQuads(i_gameObjList, rightTop, halfWidth, halfHeight);

						return true;
					}
					else
					{
						DEBUG_PRINT("\Quad at (%f, &f) is completely filled", m_pos.x(), m_pos.y());

						return false;
					}
				}
			}

			DEBUG_PRINT("Quad at (%f, &f) is completely empty", m_pos.x(), m_pos.y());

			return true;
		}

		bool Quadtree::IsPointInside(const Math::Vector2& i_point)
		{
			const float left = m_pos.x() - (m_width / 2.0f);
			const float right = m_pos.x() + (m_width / 2.0f);
			const float top = m_pos.y() - (m_height / 2.0f);
			const float bottom = m_pos.y() + (m_height / 2.0f);

			if ((i_point.x() > left) && (i_point.x() < right) && (i_point.y() > top) && (i_point.y() < bottom))
			{
				DEBUG_PRINT("Point (%f, %f) is inside Quad", i_point.x(), i_point.y());
				
				return true;
			}
			else
			{
				DEBUG_PRINT("Point (%f, %f) is not inside Quad", i_point.x(), i_point.y());
				
				return false;
			}
		}

		bool Quadtree::IsObjectCornerInside(const GameObject::GameObject* const i_gameObj)
		{
			assert(i_gameObj != nullptr);
			
			const Math::Vector2 leftTop = Math::Vector2(i_gameObj->Pos().x() - (i_gameObj->Width() / 2.0f), i_gameObj->Pos().y() - (i_gameObj->Height() / 2.0f));
			const Math::Vector2 leftBottom = Math::Vector2(i_gameObj->Pos().x() - (i_gameObj->Width() / 2.0f), i_gameObj->Pos().y() + (i_gameObj->Height() / 2.0f));
			const Math::Vector2 rightTop = Math::Vector2(i_gameObj->Pos().x() + (i_gameObj->Width() / 2.0f), i_gameObj->Pos().y() - (i_gameObj->Height() / 2.0f));
			const Math::Vector2 rightBottom = Math::Vector2(i_gameObj->Pos().x() + (i_gameObj->Width() / 2.0f), i_gameObj->Pos().y() + (i_gameObj->Height() / 2.0f));

			if (IsPointInside(leftTop) || IsPointInside(leftBottom) || IsPointInside(rightTop) || IsPointInside(rightBottom))
			{
				DEBUG_PRINT("Gameobject at (%f, %f) is inside Quad", i_gameObj->Pos().x(), i_gameObj->Pos().y());
				
				return true;
			}
			else
			{
				DEBUG_PRINT("Gameobject at (%f, %f) is partially inside or not inside Quad", i_gameObj->Pos().x(), i_gameObj->Pos().y());
				
				return false;
			}
		}
	}
}