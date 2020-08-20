#include "MiniginPCH.h"
#include "Scene.h"
#include "GameObject.h"
#include <algorithm>

using namespace elfgine;

unsigned int Scene::m_IdCounter = 0;

Scene::Scene(const std::string& name) : m_Name(name) {}


void Scene::CheckToDelete()
{
	for(int i{0}; i < int(m_Objects.size()); i++)
	{
		bool isDelete = m_Objects[i]->CheckDelete();
		if(isDelete)
		{
			auto it = std::remove(m_Objects.begin(), m_Objects.end(), m_Objects[i]);
			m_Objects.erase(it, m_Objects.end());
		}
	}
}

Scene::~Scene() = default;

void Scene::Add(const std::shared_ptr<SceneObject>& object)
{
	m_Objects.push_back(object);
}

void Scene::Update(float deltaTime)
{
	for(auto& object : m_Objects)
	{
		object->Update(deltaTime);
	}
}

void Scene::FixedUpdate()
{
	for (auto& object : m_Objects)
	{
		object->FixedUpdate();
	}
}


