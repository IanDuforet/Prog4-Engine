#pragma once
#include "BaseComponent.h"
#include "Rectangle.h"
#include "GameObject.h"

namespace elfgine
{
	class Observer;
	class ColliderComponent : public BaseComponent
	{
	public:
		ColliderComponent(int width, int height, bool checkCollision);
		~ColliderComponent();
		void Update(float deltaTime) override;
		bool CheckCollision();
		void AddColliderToCollection(std::shared_ptr<ColliderComponent> pThisCollider);
		void AddObserver(std::shared_ptr<Observer> pObserver);
		
	protected:
		Rect2D m_Rect;
	private:
		static std::vector<std::shared_ptr<ColliderComponent>> m_AllColliders;
		std::weak_ptr<ColliderComponent> m_ThisCollider;
		std::weak_ptr<GameObject> m_FoundObject;
		bool m_CheckCollision{false};
		std::vector<std::shared_ptr<Observer>> m_pObservers;
		
	};
}

