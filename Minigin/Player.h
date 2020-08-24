#pragma once
#include "GameObject.h"
#include <string>
namespace elfgine
{
	class ControlComponent;
	class Player final : public GameObject
	{
	public:
		Player(const std::string& textureName, bool isActivePlayer);
		virtual ~Player() = default;
		Player(const Player& other) = delete;
		Player(Player&& other) = delete;
		Player& operator=(const Player& other) = delete;
		Player& operator=(Player&& other) = delete;

		//Functions
		void SetShootCooldown(float cooldown);
		void SetSpeed(int speed);
		void SetCanMove();
		
		bool GetIsOnGrid();

	private:
		//Variables
		std::shared_ptr<ControlComponent> m_pControlComponent;
		
	};	
}

