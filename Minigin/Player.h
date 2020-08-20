#pragma once
#include "GameObject.h"
#include <string>
namespace elfgine
{
	class ControlComponent;
	class Player : public GameObject
	{
	public:
		//TO DO: move texture creation back out of render component so you can reuse textures for multiple game objects
		Player(const std::string& textureName, bool isActivePlayer);
		virtual ~Player() = default;

		void SetSpeed(int speed);
		
		std::shared_ptr<ControlComponent> m_pControlComponent;
	private:
		
	};	
}

