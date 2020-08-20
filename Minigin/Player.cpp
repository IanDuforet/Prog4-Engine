#include "MiniginPCH.h"
#include "Player.h"
#include "Components.h"
#include  "CommandInputHandler.h"

elfgine::Player::Player(const std::string& textureName, bool isActivePlayer)
	: GameObject()
{
	std::shared_ptr<RenderComponent> renderComponent = std::make_shared<RenderComponent>(GetTransform());
	renderComponent->SetTexture(textureName);
	AddComponent(renderComponent);

	std::shared_ptr<RigidBodyComponent> rbComponent = std::make_shared<RigidBodyComponent>();
	AddComponent(rbComponent);

	std::shared_ptr<ControlComponent> controlComponent = std::make_shared<ControlComponent>(rbComponent);
	if (isActivePlayer)
		CommandInputHandler::GetInstance().AssignActor(controlComponent);

	AddComponent(controlComponent);
	m_pControlComponent = controlComponent;
	
	std::shared_ptr<ColliderComponent> colliderComponent = std::make_shared<ColliderComponent>(renderComponent->GetTextureWidth(), 
		renderComponent->GetTextureHeight(), true);
	colliderComponent->AddColliderToCollection(colliderComponent);
	
	AddComponent(colliderComponent);
}

void elfgine::Player::SetSpeed(int speed)
{
	m_pControlComponent->SetSpeed(speed);
}


