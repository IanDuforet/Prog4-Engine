#pragma once
#include "GameObject.h"
#include "TextObject.h"
#include "Grid.h"
#include "Player.h"

class GameManager final : public elfgine::GameObject
{
public:
	enum class State
	{
		Level1,
		Level2,
		Level3,
	};

	GameManager(int toCollect, int toKill);
	virtual ~GameManager() = default;
	GameManager(const GameManager& other) = delete;
	GameManager(GameManager&& other) = delete;
	GameManager& operator=(const GameManager& other) = delete;
	GameManager& operator=(GameManager&& other) = delete;

	//Functions
	void SetScoreText(std::shared_ptr<elfgine::TextObject> pTextObject);
	void SetGrid(std::shared_ptr<elfgine::Grid> pGrid);
	void SetPlayer(std::shared_ptr<elfgine::Player> pPlayer);
	void AddScore(int value);
	void CollectedEmerald();
	void KilledEnemy();
	void Update(float deltaTime) override;
	
private:
	//Helper functions
	void CheckGridMovement();
	void UpdateScore();
	void LoadNextLevel(State levelState);

	//Variables
	int m_ToCollect;
	int m_ToKill;
	int m_Score{0};
	int m_CollectedEmeralds{0};
	int m_KilledEnemies{0};
	std::weak_ptr<elfgine::TextObject> m_pScoreText;
	std::weak_ptr<elfgine::Grid> m_pGrid;
	std::weak_ptr<elfgine::Player> m_Player;

	//Static
	static State m_LevelState;

};

