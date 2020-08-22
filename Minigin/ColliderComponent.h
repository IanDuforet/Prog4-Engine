#pragma once
#include "BaseComponent.h"
#include "Rectangle.h"
#include "GameObject.h"

namespace elfgine
{
	enum class Tag
	{
		Pickup,
		Tile,
		Enemy,
		Player,
		Projectile
	};
	
	class Observer;
	class ColliderComponent : public BaseComponent
	{
	public:
		ColliderComponent(int width, int height, bool checkCollision, Tag tag);
		~ColliderComponent();
		void Update(float deltaTime) override;
		bool CheckCollision();
		void AddColliderToCollection(std::shared_ptr<ColliderComponent> pThisCollider);
		void AddObserver(std::shared_ptr<Observer> pObserver);
		
	protected:
		Rect2D m_Rect;
		std::weak_ptr<ColliderComponent> m_ThisCollider;
		bool m_CheckCollision{false};
	private:
		static std::vector<std::weak_ptr<ColliderComponent>> m_AllColliders;
		std::weak_ptr<GameObject> m_FoundObject;
		std::vector<std::weak_ptr<Observer>> m_pObservers;
		int m_SpriteWidth;
		int m_SpriteHeight;
		Tag m_Tag;
		
	};
}

