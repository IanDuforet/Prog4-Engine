#pragma once
#include "SceneObject.h"
#include "vector"
#include "Components.h"

namespace elfgine
{
	class Transform;
	class TransformComponent;
	class BaseComponent;
	class GameObject : public SceneObject, std::enable_shared_from_this<GameObject>
	{
	public:
		GameObject();
		virtual ~GameObject() = default;
		GameObject(const GameObject& other) = delete;
		GameObject(GameObject&& other) = delete;
		GameObject& operator=(const GameObject& other) = delete;
		GameObject& operator=(GameObject&& other) = delete;

		//Functions
		void Update(float deltaTime) override;
		void FixedUpdate() override;
		void SetPosition(float x, float y) const;
		void SetPosition(glm::vec2 pos) const;
		void AddComponent(std::shared_ptr<BaseComponent> pComponent);
		void AddComponent(std::shared_ptr<BaseComponent> pComponent, std::weak_ptr<GameObject> pGameObject);
		void AddGameObjectToComponents(std::shared_ptr<GameObject> pGameObject);
		void RemoveComponent(std::shared_ptr<BaseComponent> pComponent);
		std::shared_ptr<Transform> GetTransform() const;
		
		template <typename T>
		std::shared_ptr<T> GetComponent() const
		{
			for (std::shared_ptr<BaseComponent> c : m_pComponents)
			{
				std::shared_ptr<T> pComponent{ std::dynamic_pointer_cast<T>(c) };
				if (pComponent != nullptr)
					return pComponent;
			}
			return nullptr;
		}
		
	protected:
		//Mandatory component:
		std::shared_ptr<TransformComponent> m_pTransformComponent{nullptr};
		
		//Extra components
		std::vector<std::shared_ptr<BaseComponent>> m_pComponents{};
	};
}
