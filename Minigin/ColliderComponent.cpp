#include "MiniginPCH.h"
#include "ColliderComponent.h"
#include "GameObject.h"
#include "Transform.h"
#include <algorithm>
#include "GameObserver.h"
#include "ScoreObserver.h"
std::vector<std::shared_ptr<elfgine::ColliderComponent>> elfgine::ColliderComponent::m_AllColliders{};

elfgine::ColliderComponent::ColliderComponent(int width, int height, bool checkCollision)
	: BaseComponent()
	, m_Rect(Rect2D{ 0,0,width, height})
	, m_CheckCollision(checkCollision)
{
	AddObserver(std::make_shared<GameObserver>());
	AddObserver(std::make_shared<ScoreObserver>());
}

elfgine::ColliderComponent::~ColliderComponent()
{
	auto it = std::remove(m_AllColliders.begin(), m_AllColliders.end(), m_ThisCollider.lock());
	m_AllColliders.erase(it, m_AllColliders.end());
}

void elfgine::ColliderComponent::Update(float)
{
	std::shared_ptr<Transform> t = m_pGameObject.lock()->GetTransform();
	m_Rect.x = int(t->GetPosition().x);
	m_Rect.y = int(t->GetPosition().y);

	if(m_CheckCollision)
	{
		if(CheckCollision())
		{
			if(m_FoundObject.lock())
			{
				if (!m_FoundObject.lock()->CheckDelete())
				{
					for(int i{0}; i < int(m_pObservers.size()); i++)
					{
						std::weak_ptr<Observer> pObserver = m_pObservers[i];
						pObserver.lock()->onNotify(m_FoundObject.lock(), Observer::Event::DestroyObject);
						pObserver.lock()->onNotify(m_FoundObject.lock(), Observer::Event::AddScore);
					}
				}
			}
		}
	}
}

bool elfgine::ColliderComponent::CheckCollision()
{
	for(std::shared_ptr<ColliderComponent> c : m_AllColliders)
	{
		//Make sure it does not check collision with itself
		if (c != m_ThisCollider.lock())
		{
			//Check collision with others
			Rect2D otherRect = c->m_Rect;
			if(m_Rect.x < otherRect.x + otherRect.width &&
				m_Rect.x + m_Rect.width > otherRect.x &&
				m_Rect.y < otherRect.y + otherRect.height &&
				m_Rect.y + m_Rect.height > otherRect.y)
			{
				m_FoundObject = c->m_pGameObject;
				return true;
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

