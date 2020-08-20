#include "MiniginPCH.h"
#include "GameObserver.h"
#include "GameObject.h"

void elfgine::GameObserver::onNotify(std::shared_ptr<GameObject> pGameObject, Event event)
{
	switch (event)
	{
	case Event::DestroyObject:
		DestroyObject(pGameObject);
		break;
	//Can add more events
	}
}

void elfgine::GameObserver::DestroyObject(std::shared_ptr<GameObject> pGameObject)
{
	pGameObject->SetDelete();
}
