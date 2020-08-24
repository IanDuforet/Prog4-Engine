#include "MiniginPCH.h"
#include "Projectile.h"
#include "CommandInputHandler.h"

elfgine::Projectile::Projectile(const std::string& textureName, ControlComponent::moveDirection playerDirection, int speed)
	: GameObject()
	, m_ProjectileSpeed(speed)
	, m_ProjectileDir(playerDirection)
{
	//Render
	std::shared_ptr<RenderComponent> renderComponent = std::make_shared<RenderComponent>(GetTransform());
	renderComponent->SetTexture(textureName);
	AddComponent(renderComponent);

	//Rigidbody
	std::shared_ptr<RigidBodyComponent> rbComponent = std::make_shared<RigidBodyComponent>(m_pTransformComponent->GetTransform());
	AddComponent(rbComponent);

	m_ThisRigidBody = rbComponent;
	
	//Collider
	std::shared_ptr<ColliderComponent> colliderComponent = std::make_shared<ColliderComponent>(renderComponent->GetTextureWidth(),
		renderComponent->GetTextureHeight(), true, ColliderComponent::Tag::Projectile);
	AddComponent(colliderComponent);
}

void elfgine::Projectile::Update(float deltaTime)
{
	switch (m_ProjectileDir)
	{
	case ControlComponent::moveDirection::Left:
		m_ThisRigidBody.lock()->MoveLeft((float)m_ProjectileSpeed);
		break;
	case ControlComponent::moveDirection::Right:
		m_ThisRigidBody.lock()->MoveRight((float)m_ProjectileSpeed);
		break;
	case ControlComponent::moveDirection::Up:
		m_ThisRigidBody.lock()->MoveUp((float)m_ProjectileSpeed);

		break;
	case ControlComponent::moveDirection::Down:
		m_ThisRigidBody.lock()->MoveDown((float)m_ProjectileSpeed);
		break;
	
	}

	GameObject::Update(deltaTime);
}
