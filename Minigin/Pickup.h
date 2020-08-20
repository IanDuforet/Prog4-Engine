#pragma once
#include "GameObject.h"
namespace elfgine
{
	class Pickup : public GameObject
	{
	public:
		Pickup(const std::string& textureName, int value);
		Pickup(const std::string& textureName, glm::vec2 position, int value);
		int GetValue();
		virtual ~Pickup() = default;

	private:
		int m_Value;

	};
}

