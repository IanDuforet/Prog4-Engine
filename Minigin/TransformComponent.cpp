#include "MiniginPCH.h"
#include "TransformComponent.h"
#include "Transform.h"
elfgine::TransformComponent::TransformComponent(std::shared_ptr<Transform> pTransform)
	: BaseComponent(), m_pTransform(pTransform)
{
	
}


std::shared_ptr<elfgine::Transform> elfgine::TransformComponent::GetTransform() const
{
	return m_pTransform;
}

void elfgine::TransformComponent::SetPosition(float x, float y)
{
	m_pTransform->SetPosition(x, y);
}

void elfgine::TransformComponent::SetPosition(glm::vec2 pos)
{
	m_pTransform->SetPosition(pos);
}

void elfgine::TransformComponent::Update(float)
{
	
}


