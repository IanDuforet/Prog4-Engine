#include "MiniginPCH.h"
#include "RigidBodyComponent.h"
#include "GameObject.h"
#include "Transform.h"


elfgine::RigidBodyComponent::RigidBodyComponent(std::shared_ptr<Transform> pTransform)
	: m_Velocity{}
{
	m_Transform = pTransform;
}


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
	
	glm::vec2 pos = m_Transform.lock()->GetPosition();
	glm::vec2 newPos{pos};

	newPos.x = pos.x + (m_Velocity.x * deltaTime);
	newPos.y = pos.y + (m_Velocity.y * deltaTime);
	m_Transform.lock()->SetPosition(newPos);

	m_Velocity = { 0,0 };
}


