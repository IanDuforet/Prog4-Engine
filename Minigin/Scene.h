#pragma once
#include "SceneManager.h"

namespace elfgine
{
	class ColliderComponent;
	class Player;
	class SceneObject;
	class Scene final
	{
		friend Scene& SceneManager::CreateScene(const std::string& name);
	public:
		void Add(const std::shared_ptr<SceneObject>& object);
		void SetPlayer(std::shared_ptr<Player> pPlayer);
		void AddColliderToCollection(std::shared_ptr<ColliderComponent> pCollider);
		
		std::shared_ptr<Player> GetPlayer() const;
		const std::vector<std::weak_ptr<ColliderComponent>>& GetColliders() const;
		
		void Update(float deltaTime);
		void FixedUpdate();
		void CheckToDelete();
		void AddColliders();

		
		template <typename T>
		std::shared_ptr<T> GetObject()
		{
			for (std::shared_ptr<SceneObject> o : m_Objects)
			{
				std::shared_ptr<T> pObject{ std::dynamic_pointer_cast<T>(o) };
				if (pObject != nullptr)
					return pObject;
			}
			return nullptr;
		}
		
		~Scene();
		Scene(const Scene& other) = delete;
		Scene(Scene&& other) = delete;
		Scene& operator=(const Scene& other) = delete;
		Scene& operator=(Scene&& other) = delete;

	private: 
		explicit Scene(const std::string& name);

		//Variables
		static unsigned int m_IdCounter;
		std::string m_Name;
		std::vector <std::shared_ptr<SceneObject>> m_Objects{};
		std::vector <std::weak_ptr<ColliderComponent>> m_Colliders{};
		std::weak_ptr<Player> m_Player;
	};

}
