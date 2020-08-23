#include "MiniginPCH.h"
#include "ColliderComponent.h"
#include "GameObject.h"
#include "Transform.h"
#include <algorithm>
#include "GameObserver.h"
#include "ObserverManager.h"
std::vector<std::weak_ptr<elfgine::ColliderComponent>> elfgine::ColliderComponent::m_AllColliders{};

elfgine::ColliderComponent::ColliderComponent(int width, int height, bool checkCollision, Tag tag)
	: BaseComponent()
	, m_Rect(Rect2D{ 0,0,width, height})
	, m_CheckCollision(checkCollision)
	, m_Tag{tag}
	, m_SpriteWidth(width)
	, m_SpriteHeight(height)
{
	auto& pManager = ObserverManager::GetInstance();
	AddObserver(pManager.GetObserver("Game"));
	AddObserver(pManager.GetObserver("Score"));
}

elfgine::ColliderComponent::~ColliderComponent()
{
	/*auto it = std::remove(m_AllColliders.begin(), m_AllColliders.end(), m_ThisCollider.lock());
	m_AllColliders.erase(it, m_AllColliders.end());*/
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
			pObserver.lock()->onNotify(m_FoundObject.lock(), Observer::Event::PlayerWithPickup);
			break;
		case Tag::Tile:
			if(m_Tag == Tag::Projectile)
				pObserver.lock()->onNotify(m_pGameObject.lock(), Observer::Event::ProjectileWithTile);
			if(m_Tag == Tag::Player)
				pObserver.lock()->onNotify(m_FoundObject.lock(), Observer::Event::PlayerWithTile);
			break;
		default:
			break;
		}
		
	}
}

bool elfgine::ColliderComponent::CheckCollision()
{
	for(std::weak_ptr<ColliderComponent> c : m_AllColliders)
	{
		if(c.lock())
		{
			//Make sure it does not check collision with itself
			if (c.lock() != m_ThisCollider.lock())
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

void elfgine::ColliderComponent::AddColliderToCollection(std::shared_ptr<ColliderComponent> pThisCollider)
{
	m_AllColliders.push_back(pThisCollider);
	m_ThisCollider = pThisCollider;
}

void elfgine::ColliderComponent::AddObserver(std::shared_ptr<Observer> pObserver)
{
	m_pObservers.push_back(pObserver);
}

