#include "MiniginPCH.h"
#include "ControlComponent.h"
#include "GameObject.h"
#include "RigidBodyComponent.h"

elfgine::ControlComponent::ControlComponent(std::shared_ptr<RigidBodyComponent> pRigidBody)
	: BaseComponent()
	, m_Speed(10)
	, m_pRigidBody(pRigidBody)
{

}

void elfgine::ControlComponent::MoveLeft()
{
	m_pRigidBody.lock()->MoveLeft(float(-m_Speed));
}

void elfgine::ControlComponent::MoveRight()
{
	m_pRigidBody.lock()->MoveRight(float(m_Speed));
}

void elfgine::ControlComponent::MoveUp()
{
	m_pRigidBody.lock()->MoveUp(float(-m_Speed));
}

void elfgine::ControlComponent::MoveDown()
{
	m_pRigidBody.lock()->MoveDown(float(m_Speed));
}



