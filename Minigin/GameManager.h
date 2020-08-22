#pragma once
#include "GameObject.h"
#include "TextObject.h"
#include "Grid.h"
#include "Player.h"

class GameManager : public elfgine::GameObject
{
public:
	void SetScoreText(std::shared_ptr<elfgine::TextObject> pTextObject);
	void SetGrid(std::shared_ptr<elfgine::Grid> pGrid);
	void SetPlayer(std::shared_ptr<elfgine::Player> pPlayer);
	void AddScore(int value);
	void Update(float deltaTime) override;
private:

	//Helper functions
	void CheckGridMovement();
	void UpdateScore();
	
	int m_Score{0};
	std::weak_ptr<elfgine::TextObject> m_pScoreText;
	std::weak_ptr<elfgine::Grid> m_pGrid;
	std::weak_ptr<elfgine::Player> m_Player;

};


