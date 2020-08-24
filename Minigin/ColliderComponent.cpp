#include "MiniginPCH.h"
#include "ColliderComponent.h"
#include "GameObject.h"
#include "Transform.h"
#include <algorithm>
#include "GameObserver.h"
#include "ObserverManager.h"
#include "SceneManager.h"
#include "Scene.h"

elfgine::ColliderComponent::ColliderComponent(int width, int height, bool checkCollision, Tag tag)
	: BaseComponent()
	, m_Rect(Rect2D{ 0,0,width, height})
	, m_SpriteWidth(width)
	, m_SpriteHeight(height)
	, m_Tag{tag}
	, m_CheckCollision(checkCollision)
{
	auto& pManager = ObserverManager::GetInstance();
	AddObserver(pManager.GetObserver("Game"));
	AddObserver(pManager.GetObserver("Score"));
}


void elfgine::ColliderComponent::Update(float)
{
	std::shared_ptr<Transform> t = m_pGameObject.lock()->GetTransform();
	m_Rect.x = int(t->GetPosition().x);
	m_Rect.y = int(t->GetPosition().y);

	if (!m_CheckCollision)
		return;
	if (!CheckCollision())
		return;
	if (!m_FoundObject.lock())
		return;
	if (m_FoundObject.lock()->CheckDelete())
		return;
	for(int i{0}; i < int(m_pObservers.size()); i++)
	{
		std::weak_ptr<Observer> pObserver = m_pObservers[i];

		std::weak_ptr<ColliderComponent> otherCollider = m_FoundObject.lock()->GetComponent<ColliderComponent>();

		if (!otherCollider.lock())
			return;
		
			Tag otherTag = otherCollider.lock()->m_Tag;
		switch (otherTag)
		{
		case Tag::Pickup:
			if(m_Tag == Tag::Player)
				pObserver.lock()->onNotify(m_pGameObject.lock(),m_FoundObject.lock(), Observer::Event::PlayerWithPickup);
			break;
		case Tag::Tile:
			if(m_Tag == Tag::Projectile)
				pObserver.lock()->onNotify(m_pGameObject.lock(), m_FoundObject.lock(), Observer::Event::ProjectileWithTile);
			if(m_Tag == Tag::Player)
				pObserver.lock()->onNotify(m_pGameObject.lock(), m_FoundObject.lock(), Observer::Event::PlayerWithTile);
			break;
		case Tag::Enemy:
			if(m_Tag == Tag::Projectile)
				pObserver.lock()->onNotify(m_pGameObject.lock(), m_FoundObject.lock(), Observer::Event::ProjectileWithEnemy);
		default:
			break;
		}
		
	}
}

bool elfgine::ColliderComponent::CheckCollision()
{
	std::vector<std::weak_ptr<ColliderComponent>> allColliders = SceneManager::GetInstance().GetActiveScene()->GetColliders();
	for(std::weak_ptr<ColliderComponent> c : allColliders)
	{
		if(c.lock())
		{
			//Make sure it does not check collision with itself
			if (c.lock()->m_Tag != m_Tag)
			{
				//Check collision with others
				Rect2D otherRect = c.lock()->m_Rect;
				if(m_Rect.x < otherRect.x + otherRect.width &&
					m_Rect.x + m_Rect.width > otherRect.x &&
					m_Rect.y < otherRect.y + otherRect.height &&
					m_Rect.y + m_Rect.height > otherRect.y)
				{
					m_FoundObject = c.lock()->m_pGameObject;
					
					return true;
				}
			}
		}
	}
	return false;
}


void elfgine::ColliderComponent::AddObserver(std::shared_ptr<Observer> pObserver)
{
	m_pObservers.push_back(pObserver);
}

