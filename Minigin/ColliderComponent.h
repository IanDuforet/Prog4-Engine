#pragma once
#include "BaseComponent.h"
#include "Rectangle.h"
namespace elfgine
{
	class ColliderComponent : public BaseComponent, std::enable_shared_from_this<ColliderComponent>
	{
	public:
		ColliderComponent(int x, int y,int width, int height);
		~ColliderComponent() = default;
		void Update(float deltaTime);
		bool CheckCollision();
		
	protected:
		Rect2D m_Rect;
	private:
		static std::vector<std::shared_ptr<ColliderComponent>> m_AllColliders;
	};
}

