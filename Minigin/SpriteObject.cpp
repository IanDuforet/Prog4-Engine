#include "MiniginPCH.h"
#include "SpriteObject.h"
#include "Components.h"

elfgine::SpriteObject::SpriteObject(const std::string& textureName, glm::vec2 position)
{
	std::shared_ptr<RenderComponent> renderComponent = std::make_shared<RenderComponent>(GetTransform());
	renderComponent->SetTexture(textureName);
	AddComponent(renderComponent);

	SetPosition(position);
}
