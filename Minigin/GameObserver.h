#pragma once
#include "Observer.h"

class GameObserver final : public elfgine::Observer
{
public:
	void onNotify(std::shared_ptr<elfgine::GameObject> pGameObject, std::shared_ptr<elfgine::GameObject> pFoundObject, Event event);
private:
	void DestroyObject(std::shared_ptr<elfgine::GameObject> pGameObject);
};

