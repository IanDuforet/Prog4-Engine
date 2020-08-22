#include "MiniginPCH.h"
#include "Pickup.h"
#include "Components.h"

elfgine::Pickup::Pickup(const std::string& textureName, int value)
	: GameObject()
	, m_Value(value)
{
	std::shared_ptr<RenderComponent> renderComponent = std::make_shared<RenderComponent>(GetTransform());
	renderComponent->SetTexture(textureName);
	AddComponent(renderComponent);

	std::shared_ptr<ColliderComponent> colliderComponent = std::make_shared<ColliderComponent>(renderComponent->GetTextureWidth(),
		renderComponent->GetTextureHeight(), false, Tag::Pickup);

	colliderComponent->AddColliderToCollection(colliderComponent);
	
	AddComponent(colliderComponent);
}

elfgine::Pickup::Pickup(const std::string& textureName, glm::vec2 position, int value)
	: GameObject()
	, m_Value(value)
{
	std::shared_ptr<RenderComponent> renderComponent = std::make_shared<RenderComponent>(GetTransform());
	renderComponent->SetTexture(textureName);
	AddComponent(renderComponent);


	m_pTransformComponent->SetPosition(position.x, position.y);

	std::shared_ptr<ColliderComponent> colliderComponent = std::make_shared<ColliderComponent>(renderComponent->GetTextureWidth(),
		renderComponent->GetTextureHeight(), false, Tag::Pickup);

	colliderComponent->AddColliderToCollection(colliderComponent);

	AddComponent(colliderComponent);
}

int elfgine::Pickup::GetValue()
{
	return m_Value;
}
