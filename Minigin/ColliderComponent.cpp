#include "MiniginPCH.h"
#include "ColliderComponent.h"
#include "GameObject.h"
#include "Transform.h"

std::vector<std::shared_ptr<elfgine::ColliderComponent>> elfgine::ColliderComponent::m_AllColliders{};

elfgine::ColliderComponent::ColliderComponent(int x, int y,int width, int height)
	: BaseComponent()
	, m_Rect(Rect2D{x, y ,width, height})
{
	//Add this component to the static collection so you can access all colliders
	m_AllColliders.push_back(shared_from_this());
}

void elfgine::ColliderComponent::Update(float)
{
	std::shared_ptr<Transform> t = m_pGameObject.lock()->GetTransform();
	m_Rect.x = (int)t->GetPosition().x;
	m_Rect.y = (int)t->GetPosition().y;
}

bool elfgine::ColliderComponent::CheckCollision()
{
	for(std::shared_ptr<ColliderComponent> c : m_AllColliders)
	{
		//Make sure it does not check collision with itself
		if (c == shared_from_this())
			return false;

		//Check collision with others
		Rect2D otherRect = c->m_Rect;
		if(m_Rect.x < otherRect.x + otherRect.width &&
			m_Rect.x + m_Rect.width > otherRect.x &&
			m_Rect.y < otherRect.y + otherRect.height &&
			m_Rect.y + m_Rect.height > otherRect.y)
		{
			return true;
		}
	}
	return false;
}

