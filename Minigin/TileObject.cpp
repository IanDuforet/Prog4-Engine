#include "MiniginPCH.h"
#include "TileObject.h"
#include "Components.h"

elfgine::TileObject::TileObject(const std::string& textureName, glm::vec2 position)
{
	SetPosition(position);
	std::shared_ptr<RenderComponent> renderComponent = std::make_shared<RenderComponent>(GetTransform());
	renderComponent->SetTexture(textureName);
	AddComponent(renderComponent);
	m_pRenderComponent = renderComponent;

	std::shared_ptr<ColliderComponent> colliderComponent = std::make_shared<ColliderComponent>(renderComponent->GetTextureWidth() - 20,
		renderComponent->GetTextureHeight() - 20, false, Tag::Tile);

	colliderComponent->AddColliderToCollection(colliderComponent);

	AddComponent(colliderComponent);
	
}

void elfgine::TileObject::SetTileState(bool state)
{
	m_pRenderComponent.lock()->SetEnable(state);
	m_State = state;
}
