#include "MiniginPCH.h"
#include "GameManager.h"
#include "Grid.h"
#include "Player.h"
#include "TileObject.h"
#include "SceneManager.h"
#include "Scene.h"
#include "ObserverManager.h"
#include "Observer.h"
#include "GameObserver.h"
#include "ScoreObserver.h"

GameManager::State GameManager::m_LevelState{GameManager::State::Level1};

GameManager::GameManager(int toCollect, int toKill)
	: GameObject()
	, m_ToCollect(toCollect) , m_ToKill(toKill)
{
	
}

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

void GameManager::CollectedEmerald()
{
	m_CollectedEmeralds++;
}

void GameManager::KilledEnemy()
{
	m_KilledEnemies++;
}

void GameManager::Update(float)
{
	CheckGridMovement();

	switch (m_LevelState)
	{
	case State::Level1:
		if(m_CollectedEmeralds == m_ToCollect || m_KilledEnemies == m_ToKill)
		{
			LoadNextLevel(State::Level2);
		}
		break;
	case State::Level2:
		if (m_CollectedEmeralds == m_ToCollect || m_KilledEnemies == m_ToKill)
		{
			LoadNextLevel(State::Level3);
		}
		break;
	case State::Level3:
		break;
	default: ;
	}
	
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
			m_Player.lock()->SetCanMove();
		}

}

void GameManager::UpdateScore()
{
	m_pScoreText.lock()->SetText(std::to_string(m_Score));
}

void GameManager::LoadNextLevel(State levelState)
{
	elfgine::SceneManager::GetInstance().NextScene();
	std::shared_ptr<GameManager> activeManager = elfgine::SceneManager::GetInstance().GetActiveScene()->GetObjectW<GameManager>();
	auto& observerM = elfgine::ObserverManager::GetInstance();
	std::shared_ptr<ScoreObserver> scoreObserver = std::dynamic_pointer_cast<ScoreObserver>(observerM.GetObserver("Score"));
	scoreObserver->SetGameManager(activeManager);
	m_LevelState = levelState;
}
