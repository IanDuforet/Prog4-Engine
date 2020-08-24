#pragma once
namespace elfgine
{
	class GameObject;
	class Observer
	{	
	public:
		enum class Event
		{
			PlayerWithPickup,
			PlayerWithTile,
			ProjectileWithTile,
			ProjectileWithEnemy
		};

		Observer() = default;
		virtual ~Observer() = default;
		Observer(const Observer& other) = delete;
		Observer(Observer&& other) = delete;
		Observer& operator=(const Observer& other) = delete;
		Observer& operator=(Observer&& other) = delete;

		//Function
		virtual void onNotify(std::shared_ptr<GameObject> pGameObject, std::shared_ptr<GameObject> pFoundObject, Event event) = 0;
	};
	
}

