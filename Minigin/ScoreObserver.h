#pragma once
#include "Observer.h"
	class GameManager;
	class ScoreObserver final : public elfgine::Observer
	{
	public:
		void SetGameManager(std::shared_ptr<GameManager> pGameManager);
		void onNotify(std::shared_ptr<elfgine::GameObject> pGameObject, std::shared_ptr<elfgine::GameObject> pFoundObject, Event event);
	private:
		std::weak_ptr<GameManager> m_pGameManager;
	};

