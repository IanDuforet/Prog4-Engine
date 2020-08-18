#include "MiniginPCH.h"
#include "Transform.h"

using namespace elfgine;

//Constructors
//
Transform::Transform()
	: m_Position(glm::vec2{0,0})
	, m_Scale(glm::vec2{1,1})
{
	
}

Transform::Transform(glm::vec2 position)
	: m_Position(position)
	, m_Scale(glm::vec2{ 1,1 })
{

}

Transform::Transform(glm::vec2 position, glm::vec2 scale)
	: m_Position(position)
	, m_Scale(scale)
{

}
const glm::vec2& Transform::GetPosition() const
{
	return m_Position;
}


void Transform::SetPosition(const float x, const float y)
{
	m_Position.x = x;
	m_Position.y = y;
}

void Transform::SetX(float x)
{
	m_Position.x = x;
}

void Transform::SetY(float y)
{
	m_Position.y = y;
}

