#include "MiniginPCH.h"
#include "GameManager.h"
#include "Grid.h"
#include "Player.h"
#include "TileObject.h"

void GameManager::SetScoreText(std::shared_ptr<elfgine::TextObject> pTextObject)
{
	m_pScoreText = pTextObject;
}

void GameManager::SetGrid(std::shared_ptr<elfgine::Grid> pGrid)
{
	m_pGrid = pGrid;
}

void GameManager::SetPlayer(std::shared_ptr<elfgine::Player> pPlayer)
{
	m_Player = pPlayer;
}


void GameManager::AddScore(int value)
{
	m_Score += value;
	UpdateScore();
}

void GameManager::Update(float)
{
	CheckGridMovement();
}

void GameManager::CheckGridMovement()
{
	glm::vec2 playerPos = m_Player.lock()->GetTransform()->GetPosition();
	int tileSize = m_pGrid.lock()->GetTileSize();

	int moduloResultX = int(playerPos.x - 30) % tileSize;
	int moduloResultY = int(playerPos.y - 30) % tileSize;
	int margin = 3;
	int smallMargin = margin;
	int bigMargin = tileSize - margin;
	if(moduloResultX < smallMargin || moduloResultX > bigMargin)
		if (moduloResultY < smallMargin || moduloResultY > bigMargin)
		{
			//m_Player.lock()->SetPosition(m_pGrid.lock()->GetNearestTile(m_Player.lock())->GetTransform()->GetPosition());
			m_Player.lock()->SetCanMove();
		}

}

void GameManager::UpdateScore()
{
	m_pScoreText.lock()->SetText(std::to_string(m_Score));
}
