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
	class GameObject : public elfgine::SceneObject, std::enable_shared_from_this<GameObject>
	{
	public:
		
		void Update(float deltaTime) override;
		void FixedUpdate() override;
	
		//Change these into components
		void SetPosition(float x, float y); //Transform component
		void SetPosition(glm::vec2 pos);
		std::shared_ptr<Transform> GetTransform() const;
		void AddComponent(std::shared_ptr<BaseComponent> pComponent);
		void AddComponent(std::shared_ptr<BaseComponent> pComponent, std::weak_ptr<GameObject> pGameObject);
		void AddGameObjectToComponents(std::shared_ptr<GameObject> pGameObject);
		std::shared_ptr<Texture2D> GetTexture();
		
		template <typename T>
		std::shared_ptr<T> GetComponent()
		{
			for (std::shared_ptr<T> c : m_pComponents)
			{
				std::shared_ptr<T> pComponent{ dynamic_cast<std::shared_ptr<T>>(c) };
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
	};
}
