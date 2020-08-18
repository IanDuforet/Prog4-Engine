#include "MiniginPCH.h"
#include "FPSCounter.h"
#include "TextObject.h"

elfgine::FPSCounter::FPSCounter(std::shared_ptr<TextObject> pTextObject)
	: m_pTextObject(pTextObject) , m_Frames(0), m_SecondCounter(0)
{
	
}

void elfgine::FPSCounter::Update(float deltaTime)
{

	m_Frames++;
	m_SecondCounter += deltaTime;
	if (m_SecondCounter >= 1.f)
	{
		m_pTextObject->SetText(std::to_string(m_Frames) + " FPS");
		m_SecondCounter = 0;
		m_Frames = 0;
	}
}
