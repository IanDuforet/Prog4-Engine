#include "MiniginPCH.h"
#include "RigidBodyComponent.h"
#include "GameObject.h"
#include "Transform.h"


void elfgine::RigidBodyComponent::MoveLeft(float value)
{
	m_Velocity.x = -value;
}

void elfgine::RigidBodyComponent::MoveRight(float value)
{
	m_Velocity.x = value;
}

void elfgine::RigidBodyComponent::MoveUp(float value)
{
	m_Velocity.y = value;
}

void elfgine::RigidBodyComponent::MoveDown(float value)
{
	m_Velocity.y = -value;
}

void elfgine::RigidBodyComponent::Update(float deltaTime)
{
	std::shared_ptr<Transform> transform = m_pGameObject.lock()->GetTransform();
	glm::vec2 pos = transform->GetPosition();
	glm::vec2 newPos = pos + (m_Velocity * deltaTime);
	transform->SetPosition(newPos);
	m_Velocity = { 0,0 };
}


