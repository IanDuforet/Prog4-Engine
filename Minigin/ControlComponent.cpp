#include "MiniginPCH.h"
#include "ControlComponent.h"
#include "GameObject.h"
#include "RigidBodyComponent.h"

elfgine::ControlComponent::ControlComponent(std::shared_ptr<RigidBodyComponent> pRigidBody)
	: BaseComponent()
	, m_Speed(0)
	, m_pRigidBody(pRigidBody)
{

}

void elfgine::ControlComponent::SetIsOnGrid()
{
	m_IsOnGrid = true;
}

bool elfgine::ControlComponent::GetIsOnGrid()
{
	return m_IsOnGrid;
}

void elfgine::ControlComponent::SetSpeed(int speed)
{
	m_Speed = speed;
}

void elfgine::ControlComponent::MoveLeft()
{
	if (m_IsOnGrid)
	{
		m_MoveDirection = moveDirection::Left;
		m_pRigidBody.lock()->MoveLeft(float(m_Speed));
		m_IsOnGrid = false;
	}
	else
	{
		switch (m_MoveDirection)
		{
		case moveDirection::Left:
			m_MoveDirection = moveDirection::Left;
			m_pRigidBody.lock()->MoveLeft(float(m_Speed));
			break;
		case moveDirection::Up:
			m_pRigidBody.lock()->MoveUp(float(m_Speed));
			break;
		case moveDirection::Down:
			m_pRigidBody.lock()->MoveDown(float(m_Speed));
			break;
		case moveDirection::Right:
			m_MoveDirection = moveDirection::Left;
			m_pRigidBody.lock()->MoveLeft(float(m_Speed));
			break;
		default: ;
		}
		
	}
}

void elfgine::ControlComponent::MoveRight()
{
	if (m_IsOnGrid)
	{
		m_MoveDirection = moveDirection::Right;
		m_pRigidBody.lock()->MoveRight(float(m_Speed));
		m_IsOnGrid = false;
	}
	else
	{
		switch (m_MoveDirection)
		{
		case moveDirection::Right:
			m_MoveDirection = moveDirection::Right;
			m_pRigidBody.lock()->MoveRight(float(m_Speed));
			break;
		case moveDirection::Up:
			m_pRigidBody.lock()->MoveUp(float(m_Speed));
			break;
		case moveDirection::Down:
			m_pRigidBody.lock()->MoveDown(float(m_Speed));
			break;
		case moveDirection::Left:
			m_MoveDirection = moveDirection::Right;
			m_pRigidBody.lock()->MoveRight(float(m_Speed));
			break;
		default: ;
		}

	}
}

void elfgine::ControlComponent::MoveUp()
{
	if (m_IsOnGrid)
	{
		m_MoveDirection = moveDirection::Up;
		m_pRigidBody.lock()->MoveUp(float(m_Speed));
		m_IsOnGrid = false;
	}
	else
	{
		switch (m_MoveDirection)
		{
		case moveDirection::Right:
			m_pRigidBody.lock()->MoveRight(float(m_Speed));
			break;
		case moveDirection::Up:
			m_MoveDirection = moveDirection::Up;
			m_pRigidBody.lock()->MoveUp(float(m_Speed));
			break;
		case moveDirection::Left:
			m_pRigidBody.lock()->MoveLeft(float(m_Speed));
			break;
		case moveDirection::Down:
			m_MoveDirection = moveDirection::Up;
			m_pRigidBody.lock()->MoveUp(float(m_Speed));
			break;
		default: ;
		}

	}
}

void elfgine::ControlComponent::MoveDown()
{
	if (m_IsOnGrid)
	{
		m_MoveDirection = moveDirection::Down;
		m_pRigidBody.lock()->MoveDown(float(m_Speed));
		m_IsOnGrid = false;
	}
	else
	{
		switch (m_MoveDirection)
		{
		case moveDirection::Right:
			m_pRigidBody.lock()->MoveRight(float(m_Speed));
			break;
		case moveDirection::Left:
			m_pRigidBody.lock()->MoveLeft(float(m_Speed));
			break;
		case moveDirection::Down:
			m_MoveDirection = moveDirection::Down;
			m_pRigidBody.lock()->MoveDown(float(m_Speed));
			break;
		case moveDirection::Up:
			m_MoveDirection = moveDirection::Down;
			m_pRigidBody.lock()->MoveDown(float(m_Speed));
			break;
		default: ;
		}

	}
}



