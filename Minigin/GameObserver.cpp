#include "MiniginPCH.h"
#include "GameObserver.h"
#include "GameObject.h"
#include "TileObject.h"
#include "RenderComponent.h"

void GameObserver::onNotify(std::shared_ptr<elfgine::GameObject> pGameObject, Event event)
{
	switch (event)
	{
	case Event::DestroyObject:
		DestroyObject(pGameObject);
		break;
	case Event::UpdateTile:
		std::shared_ptr<elfgine::TileObject> pTile = std::dynamic_pointer_cast <elfgine::TileObject>(pGameObject);
		std::shared_ptr<elfgine::ColliderComponent> collision = pGameObject->GetComponent<elfgine::ColliderComponent>();
		pTile->SetTileState(true);
		pTile->RemoveComponent(collision);
		break;
	//Can add more events
	}
}

void GameObserver::DestroyObject(std::shared_ptr<elfgine::GameObject> pGameObject)
{
	pGameObject->SetDelete();
}
