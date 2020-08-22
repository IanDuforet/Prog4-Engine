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
		virtual void AddGameObject(std::weak_ptr<GameObject> pGameobject);
		virtual void SetEnable(bool state);
	protected:
		std::weak_ptr<GameObject> m_pGameObject;
		bool m_Enabled{true};
	};
}

