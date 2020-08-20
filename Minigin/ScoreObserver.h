#pragma once
#include "Observer.h"
namespace elfgine
{
	class ScoreObserver :
		public Observer
	{
	public:
		void onNotify(std::shared_ptr<GameObject> pGameObject, Event event);
	};
}

