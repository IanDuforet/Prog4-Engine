#include "MiniginPCH.h"
#include "SceneManager.h"
#include "Scene.h"
#include "CommandInputHandler.h"
#include "Player.h"

void elfgine::SceneManager::Update(float deltaTime)
{
	m_Scenes[m_SceneIndex]->Update(deltaTime);
}


void elfgine::SceneManager::FixedUpdate()
{
	for (auto& scene : m_Scenes)
	{
		scene->FixedUpdate();
	}
}

void elfgine::SceneManager::CheckToDelete()
{
	for (auto& scene : m_Scenes)
	{
		scene->CheckToDelete();
	}
}

void elfgine::SceneManager::NextScene()
{
	m_SceneIndex++;
	auto& handler = CommandInputHandler::GetInstance();
	handler.AssignActor(GetActiveScene()->GetPlayer()->GetComponent<ControlComponent>());
}

std::shared_ptr<elfgine::Scene> elfgine::SceneManager::GetActiveScene()
{
	return m_Scenes[m_SceneIndex];
}

elfgine::Scene& elfgine::SceneManager::CreateScene(const std::string& name)
{
	const auto scene = std::shared_ptr<Scene>(new Scene(name));
	m_Scenes.push_back(scene);
	return *scene;
}
