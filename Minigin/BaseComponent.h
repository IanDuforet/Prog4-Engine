#pragma once
namespace elfgine
{
	class GameObject;
	class BaseComponent
	{
	public:
		 BaseComponent() = default;
		virtual ~BaseComponent() = default;
		virtual void Update(float deltaTime) = 0;
		virtual void AddGameObject(std::shared_ptr<GameObject> pGameobject);
	protected:
		std::weak_ptr<GameObject> m_pGameObject;
	};
}

