#include "MiniginPCH.h"
#include "GameManager.h"
#include "TextObject.h"

void elfgine::GameManager::SetScoreText(std::shared_ptr<TextObject> pTextObject)
{
	m_pScoreText = pTextObject;
}

void elfgine::GameManager::AddScore(int value)
{
	m_Score += value;
	UpdateScore();
}

void elfgine::GameManager::UpdateScore()
{
	m_pScoreText.lock()->SetText(std::to_string(m_Score));
}
