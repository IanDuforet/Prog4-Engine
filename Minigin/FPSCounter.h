#pragma once
#include "TextObject.h"

namespace elfgine
{
	class TextObject;
	class FPSCounter
	{
	public:
		FPSCounter(std::shared_ptr<TextObject> pTextObject);
		~FPSCounter() = default;
		void Update(float deltaTime);

	private:
		std::shared_ptr<TextObject> m_pTextObject;
		int m_Frames;
		float m_SecondCounter;
	};
	
}

