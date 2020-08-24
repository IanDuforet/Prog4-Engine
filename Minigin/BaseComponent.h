#pragma once
namespace elfgine
{
	class GameObject;
	class BaseComponent
	{
	public:
		BaseComponent() = default;
		virtual ~BaseComponent() = default;
		BaseComponent(const BaseComponent& other) = delete;
		BaseComponent(BaseComponent&& other) = delete;
		BaseComponent& operator=(const BaseComponent& other) = delete;
		BaseComponent& operator=(BaseComponent&& other) = delete;

		//Functions
		virtual void Update(float deltaTime) = 0;
		virtual void AddGameObject(std::weak_ptr<GameObject> pGameobject);
		virtual void SetEnable(bool state);
	protected:
		//Variables
		bool m_Enabled{true};
		std::weak_ptr<GameObject> m_pGameObject;
	};
}

