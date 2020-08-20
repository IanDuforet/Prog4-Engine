#include "MiniginPCH.h"
#include "ScoreObserver.h"
#include "Pickup.h"
#include "GameObject.h"
#include "GameManager.h"
void elfgine::ScoreObserver::onNotify(std::shared_ptr<GameObject> pGameObject, Event event)
{
	switch (event)
	{
	case Event::AddScore:
		int value{ 0 };
		std::shared_ptr<Pickup> pPickup = std::dynamic_pointer_cast <Pickup>(pGameObject);
		value = pPickup->GetValue();
		//Move this to member
		GameManager::GetInstance().AddScore(value);
		break;
	}
}
