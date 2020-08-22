#include "MiniginPCH.h"
#include "Player.h"
#include "Components.h"
#include  "CommandInputHandler.h"

elfgine::Player::Player(const std::string& textureName, bool isActivePlayer)
	: GameObject()
{
	//Render
	std::shared_ptr<RenderComponent> renderComponent = std::make_shared<RenderComponent>(GetTransform());
	renderComponent->SetTexture(textureName);
	AddComponent(renderComponent);

	//Rigidbody
	std::shared_ptr<RigidBodyComponent> rbComponent = std::make_shared<RigidBodyComponent>(m_pTransformComponent->GetTransform());
	AddComponent(rbComponent);

	//Control
	std::shared_ptr<ControlComponent> controlComponent = std::make_shared<ControlComponent>(rbComponent);
	if (isActivePlayer)
		CommandInputHandler::GetInstance().AssignActor(controlComponent);
	AddComponent(controlComponent);
	m_pControlComponent = controlComponent;

	//Collider
	std::shared_ptr<ColliderComponent> colliderComponent = std::make_shared<ColliderComponent>(renderComponent->GetTextureWidth() - 20, 
		renderComponent->GetTextureHeight() - 20, true, Tag::Player);
	colliderComponent->AddColliderToCollection(colliderComponent);
	AddComponent(colliderComponent);
}

void elfgine::Player::SetSpeed(int speed)
{
	m_pControlComponent->SetSpeed(speed);
}

void elfgine::Player::SetCanMove()
{
	GetComponent<ControlComponent>()->SetIsOnGrid();
}

bool elfgine::Player::GetIsOnGrid()
{
	return GetComponent<ControlComponent>()->GetIsOnGrid();
}


