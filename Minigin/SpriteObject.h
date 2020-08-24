#pragma once
#include "GameObject.h"

namespace  elfgine
{
	class SpriteObject final : public GameObject
	{
	public:
		SpriteObject(const std::string& textureName, glm::vec2 position);
		virtual ~SpriteObject() = default;
		SpriteObject(const SpriteObject& other) = delete;
		SpriteObject(SpriteObject&& other) = delete;
		SpriteObject& operator=(const SpriteObject& other) = delete;
		SpriteObject& operator=(SpriteObject&& other) = delete;
	};
}

