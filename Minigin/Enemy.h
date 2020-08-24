#pragma once
#include "GameObject.h"
namespace elfgine
{
	class Enemy final : public GameObject
	{
	public:
		Enemy(const std::string& textureName, glm::vec2 position, int value);
		virtual ~Enemy() = default;
		Enemy(const Enemy& other) = delete;
		Enemy(Enemy&& other) = delete;
		Enemy& operator=(const Enemy& other) = delete;
		Enemy& operator=(Enemy&& other) = delete;

		//Functions
		int GetValue() const;
	private:
		//Variables
		int m_Value;
	};	
}

