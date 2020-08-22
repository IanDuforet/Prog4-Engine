#pragma once
#include "GameObject.h"
#include <string>
namespace elfgine
{
	class ControlComponent;
	class Player : public GameObject
	{
	public:
		Player(const std::string& textureName, bool isActivePlayer);
		virtual ~Player() = default;

		void SetSpeed(int speed);
		void SetCanMove();
		bool GetIsOnGrid();
		
		std::shared_ptr<ControlComponent> m_pControlComponent;
	private:
		
	};	
}

