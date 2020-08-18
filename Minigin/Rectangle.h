#pragma once
#include "MiniginPCH.h"
struct Rect2D
{
	int x;
	int y;
	int width;
	int height;
	inline glm::vec2 GetBottomLeft() const { return glm::vec2(0, height); };
	inline glm::vec2 GetTopLeft() const { return glm::vec2(0, 0); };
	inline glm::vec2 GetTopRight() const { return glm::vec2(width, 0); };
	inline glm::vec2 GetBottomrRight() const { return glm::vec2(width, height);};
};
