#include "MiniginPCH.h"
#include "GameObject.h"
#include "ResourceManager.h"
#include "Renderer.h"
#include "TransformComponent.h"
#include "RenderComponent.h"
#include "Transform.h"
#include <algorithm>
void elfgine::GameObject::Update(float deltaTime)
{
	std::shared_ptr<Transform> p_transform = m_pTransformComponent->GetTransform();
	const glm::vec2 pos = p_transform->GetPosition();

	for(std::shared_ptr<BaseComponent> c : m_pComponents)
	{
		c->Update(deltaTime);
	}
}

void elfgine::GameObject::FixedUpdate()
{
	
}

void elfgine::GameObject::SetPosition(float x, float y)
{
	m_pTransformComponent->SetPosition(x, y);
}

void elfgine::GameObject::SetPosition(glm::vec2 pos)
{
	m_pTransformComponent->SetPosition(pos);
}

std::shared_ptr<elfgine::Transform> elfgine::GameObject::GetTransform() const
{
	return m_pTransformComponent->GetTransform();
}

void elfgine::GameObject::AddComponent(std::shared_ptr<BaseComponent> pComponent, std::weak_ptr<GameObject> pGameObject)
{
	pComponent->AddGameObject(pGameObject);
	m_pComponents.push_back(pComponent);
}


void elfgine::GameObject::AddComponent(std::shared_ptr<BaseComponent> pComponent)
{
	m_pComponents.push_back(pComponent);
}

elfgine::GameObject::GameObject()
	: m_pTransformComponent(std::make_shared<TransformComponent>(std::make_shared<Transform>(glm::vec2{0,0})))
{
}

void elfgine::GameObject::AddGameObjectToComponents(std::shared_ptr<GameObject> pGameObject)
{
	for (std::shared_ptr<BaseComponent> c : m_pComponents)
	{
		c->AddGameObject(pGameObject);
	}
}

void elfgine::GameObject::RemoveComponent(std::shared_ptr<BaseComponent> pComponent)
{

		auto it = std::remove(m_pComponents.begin(), m_pComponents.end(), pComponent);
		m_pComponents.erase(it, m_pComponents.end());
}
