#pragma once
#include "Observer.h"
namespace elfgine
{
	class GameObserver :
		public Observer
	{
	public:
		void onNotify(std::shared_ptr<GameObject> pGameObject, Event event);
	private:
		void DestroyObject(std::shared_ptr<GameObject> pGameObject);

		
	};
}

