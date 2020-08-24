#include "MiniginPCH.h"
#include "GameObserver.h"
#include "GameObject.h"
#include "TileObject.h"
#include "RenderComponent.h"

void GameObserver::onNotify(std::shared_ptr<elfgine::GameObject> pGameObject, std::shared_ptr<elfgine::GameObject> pFoundObject, Event event)
{
	switch (event)
	{
	case Event::PlayerWithPickup:
		DestroyObject(pFoundObject);
		break;
	case Event::PlayerWithTile:
		{
			std::shared_ptr<elfgine::TileObject> pTile = std::dynamic_pointer_cast <elfgine::TileObject>(pFoundObject);
			std::shared_ptr<elfgine::ColliderComponent> collision = pFoundObject->GetComponent<elfgine::ColliderComponent>();
			pTile->SetTileState(true);
			pTile->RemoveComponent(collision);
			break;
		}
	case Event::ProjectileWithTile:
		DestroyObject(pGameObject);
		break;
	case Event::ProjectileWithEnemy:
		DestroyObject(pFoundObject);
		DestroyObject(pGameObject);
		break;
	//Can add more events
	}
}

void GameObserver::DestroyObject(std::shared_ptr<elfgine::GameObject> pGameObject)
{
	pGameObject->SetDelete();
}
