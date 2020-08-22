#pragma once
#include "Observer.h"

class GameObserver :
	public elfgine::Observer
{
public:
	void onNotify(std::shared_ptr<elfgine::GameObject> pGameObject, Event event);
private:
	void DestroyObject(std::shared_ptr<elfgine::GameObject> pGameObject);

	
};

