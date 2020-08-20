#pragma once
namespace elfgine
{
	class GameObject;
	class Observer
	{	
	public:
		enum class Event
		{
			DestroyObject,
			AddScore
		};

		Observer() = default;
		virtual ~Observer() {};
		virtual void onNotify(std::shared_ptr<GameObject> pGameObject, Event event) = 0;
	};
	
}

