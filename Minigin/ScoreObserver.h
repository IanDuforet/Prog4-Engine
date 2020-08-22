#pragma once
#include "Observer.h"
	class GameManager;
	class ScoreObserver :
		public elfgine::Observer
	{
	public:
		void SetGameManager(std::shared_ptr<GameManager> pGameManager);
		void onNotify(std::shared_ptr<elfgine::GameObject> pGameObject, Event event);
		std::weak_ptr<GameManager> m_pGameManager;
	};

