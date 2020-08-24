#include "MiniginPCH.h"
#include "Enemy.h"

elfgine::Enemy::Enemy(const std::string& textureName, glm::vec2 position, int value)
	: GameObject()
	, m_Value(value)
{
	//Render
	std::shared_ptr<RenderComponent> renderComponent = std::make_shared<RenderComponent>(GetTransform());
	renderComponent->SetTexture(textureName);
	AddComponent(renderComponent);

	//Rigidbody
	std::shared_ptr<RigidBodyComponent> rbComponent = std::make_shared<RigidBodyComponent>(m_pTransformComponent->GetTransform());
	AddComponent(rbComponent);
	
	//Collider
	std::shared_ptr<ColliderComponent> colliderComponent = std::make_shared<ColliderComponent>(renderComponent->GetTextureWidth(),
		renderComponent->GetTextureHeight(), false, ColliderComponent::Tag::Enemy);
	AddComponent(colliderComponent);

	SetPosition(position);
}

int elfgine::Enemy::GetValue() const
{
	return m_Value;
}

