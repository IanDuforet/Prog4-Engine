#pragma once
#include "Singleton.h"

namespace elfgine
{
	class TextObject;
	class GameManager :
		public Singleton<GameManager>
	{
	public:
		void SetScoreText(std::shared_ptr<TextObject> pTextObject);
		void AddScore(int value);
	private:

		void UpdateScore();
		
		int m_Score{0};
		std::weak_ptr<TextObject> m_pScoreText;
	};
}

