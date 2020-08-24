#pragma once
#include "Singleton.h"

namespace elfgine
{
	class Scene;
	class SceneManager final : public Singleton<SceneManager>
	{
	public:
		Scene& CreateScene(const std::string& name);

		void Update(float deltaTime);
		void FixedUpdate();
		void Render();
		void CheckToDelete();
		void NextScene();
		std::shared_ptr<Scene> GetActiveScene();
	private:
		friend class Singleton<SceneManager>;
		SceneManager() = default;
		std::vector<std::shared_ptr<Scene>> m_Scenes{};
		int m_SceneIndex{0};
	};
}
