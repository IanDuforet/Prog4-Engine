#pragma once
#include "BaseComponent.h"
#include "Rectangle.h"
#include "GameObject.h"

namespace elfgine
{
	
	class Observer;
	class ColliderComponent final : public BaseComponent
	{
	public:
		enum class Tag
		{
			Pickup,
			Tile,
			Enemy,
			Player,
			Projectile
		};
		
		ColliderComponent(int width, int height, bool checkCollision, Tag tag);
		virtual ~ColliderComponent() = default;
		ColliderComponent(const ColliderComponent& other) = delete;
		ColliderComponent(ColliderComponent&& other) = delete;
		ColliderComponent& operator=(const ColliderComponent& other) = delete;
		ColliderComponent& operator=(ColliderComponent&& other) = delete;
		
		//Functions
		void Update(float deltaTime) override;
		void AddObserver(std::shared_ptr<Observer> pObserver);
		
	protected:
		//Variables
		Rect2D m_Rect;
		bool m_CheckCollision{false};
	private:
		//Helper functions
		bool CheckCollision();

		//Variables
		int m_SpriteWidth;
		int m_SpriteHeight;
		Tag m_Tag;
		std::weak_ptr<GameObject> m_FoundObject{};
		std::vector<std::weak_ptr<Observer>> m_pObservers;
		
	};
}

