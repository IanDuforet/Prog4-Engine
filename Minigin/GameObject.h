#pragma once
#include "SceneObject.h"
#include "vector"

namespace elfgine
{
	class Transform;
	class TransformComponent;
	class BaseComponent;
	//Remove these classes
	class Texture2D;
	class GameObject : public elfgine::SceneObject
	{
	public:
		void Update(float deltaTime) override;
		void FixedUpdate() override;
	
		//Change these into components
		void SetPosition(float x, float y); //Transform component
		std::shared_ptr<Transform> GetTransform() const;
		void AddComponent(std::shared_ptr<BaseComponent> pComponent);
		void AddComponent(std::shared_ptr<BaseComponent> pComponent, std::shared_ptr<GameObject> pGameObject);

		template <typename T>
		std::weak_ptr<T> GetComponent()
		{
			for (std::weak_ptr<T> c : m_pComponents)
			{
				std::weak_ptr<T> pComponent{ dynamic_cast<std::weak_ptr<T>>(c) };
				if (pComponent != nullptr)
					return pComponent;
			}
			return nullptr;
		}
		
		GameObject();
		virtual ~GameObject() = default;
		GameObject(const GameObject& other) = delete;
		GameObject(GameObject&& other) = delete;
		GameObject& operator=(const GameObject& other) = delete;
		GameObject& operator=(GameObject&& other) = delete;

	protected:

		
		//Mandatory component:
		std::shared_ptr<TransformComponent> m_pTransformComponent{nullptr};
		
		//Extra components
		std::vector<std::shared_ptr<BaseComponent>> m_pComponents{};

		//Member variables
		
	};
}
