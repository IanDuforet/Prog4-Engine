#include "MiniginPCH.h"
#include "ScoreObserver.h"
#include "Pickup.h"
#include "GameObject.h"
#include "GameManager.h"

void ScoreObserver::SetGameManager(std::shared_ptr<GameManager> pGameManager)
{
	m_pGameManager = pGameManager;
}

void ScoreObserver::onNotify(std::shared_ptr<elfgine::GameObject> pGameObject, Event event)
{
	switch (event)
	{
	case Event::PlayerWithPickup:
		int value{ 0 };
		std::shared_ptr<elfgine::Pickup> pPickup = std::dynamic_pointer_cast <elfgine::Pickup>(pGameObject);
		value = pPickup->GetValue();
		//Move this to member
		m_pGameManager.lock()->AddScore(value);
		break;
	}
}
