#pragma once
#include "GameObject.h"

namespace  elfgine
{
	class SpriteObject : public GameObject
	{
	public:
		SpriteObject(const std::string& textureName, glm::vec2 position);
		virtual ~SpriteObject() = default;
	};
}

