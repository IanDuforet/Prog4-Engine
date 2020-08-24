#pragma once
#include "GameObject.h"
namespace elfgine
{
	class Pickup final : public GameObject
	{
	public:
		Pickup(const std::string& textureName, int value);
		Pickup(const std::string& textureName, glm::vec2 position, int value);
		virtual ~Pickup() = default;
		Pickup(const Pickup& other) = delete;
		Pickup(Pickup&& other) = delete;
		Pickup& operator=(const Pickup& other) = delete;
		Pickup& operator=(Pickup&& other) = delete;

		//Functions
		int GetValue() const;
		
	private:
		//Variable
		int m_Value;

	};
}

