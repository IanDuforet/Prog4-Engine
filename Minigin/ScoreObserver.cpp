#include "MiniginPCH.h"
#include "ScoreObserver.h"
#include "Pickup.h"
#include "GameObject.h"
#include "GameManager.h"
#include "Enemy.h"

void ScoreObserver::SetGameManager(std::shared_ptr<GameManager> pGameManager)
{
	m_pGameManager = pGameManager;
}

void ScoreObserver::onNotify(std::shared_ptr<elfgine::GameObject> pGameObject, std::shared_ptr<elfgine::GameObject> pFoundObject, Event event)
{
	int value{ 0 };
	switch (event)
	{
	case Event::PlayerWithPickup:
		{
			std::shared_ptr<elfgine::Pickup> pPickup = std::dynamic_pointer_cast <elfgine::Pickup>(pFoundObject);
			value = pPickup->GetValue();
			//Move this to member
			m_pGameManager.lock()->AddScore(value);
			if(value == 25)
				m_pGameManager.lock()->CollectedEmerald();
			break;	
		}
	case Event::ProjectileWithEnemy:
		{
			std::shared_ptr<elfgine::Enemy> pEnemy = std::dynamic_pointer_cast <elfgine::Enemy>(pFoundObject);
			value = pEnemy->GetValue();
			m_pGameManager.lock()->AddScore(value);
			m_pGameManager.lock()->KilledEnemy();
			break;	
		}
	}
}
