#include "MiniginPCH.h"
#include "RigidBodyComponent.h"
#include "GameObject.h"
#include "Transform.h"


void elfgine::RigidBodyComponent::MoveLeft(float value)
{
	std::shared_ptr<Transform> transform = m_pGameObject.lock()->GetTransform();
	transform->SetX(transform->GetPosition().x + value);
}

void elfgine::RigidBodyComponent::MoveRight(float value)
{
	std::shared_ptr<Transform> transform = m_pGameObject.lock()->GetTransform();
	transform->SetX(transform->GetPosition().x + value);
}

void elfgine::RigidBodyComponent::MoveUp(float value)
{
	std::shared_ptr<Transform> transform = m_pGameObject.lock()->GetTransform();
	transform->SetY(transform->GetPosition().y + value);
}

void elfgine::RigidBodyComponent::MoveDown(float value)
{
	std::shared_ptr<Transform> transform = m_pGameObject.lock()->GetTransform();
	transform->SetY(transform->GetPosition().y + value);
}

void elfgine::RigidBodyComponent::Update(float)
{
	/*std::shared_ptr<Transform> transform = m_pGameObject.lock()->GetTransform();
	float newX = (float)transform->GetPosition().x + ((float)m_Velocity.x * deltaTime);
	float newY = (float)transform->GetPosition().y + ((float)m_Velocity.y * deltaTime);
	
	transform->SetPosition(newX, newY);
	
	m_Velocity.x = 0;
	m_Velocity.y = 0;*/
}


