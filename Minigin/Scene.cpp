#include "MiniginPCH.h"
#include "Scene.h"
#include "GameObject.h"
#include <algorithm>
#include "Grid.h"
#include "TileObject.h"

using namespace elfgine;

unsigned int Scene::m_IdCounter = 0;

Scene::Scene(const std::string& name)
	: m_Name(name) {}


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

void Scene::AddColliders()
{
	for (std::shared_ptr<SceneObject> c : m_Objects)
	{
		std::weak_ptr<GameObject> object = std::dynamic_pointer_cast<GameObject>(c);
		m_Colliders.push_back(object.lock()->GetComponent<ColliderComponent>());
	}

	std::weak_ptr<Grid> pGrid = GetObject<Grid>();
	for(std::weak_ptr<TileObject> t : pGrid.lock()->GetTiles())
	{
		m_Colliders.push_back(t.lock()->GetComponent<ColliderComponent>());
	}
	
}

Scene::~Scene() = default;

void Scene::Add(const std::shared_ptr<SceneObject>& object)
{
	m_Objects.push_back(object);
}

void Scene::SetPlayer(std::shared_ptr<Player> pPlayer)
{
	m_Player = pPlayer;
}

void Scene::AddColliderToCollection(std::shared_ptr<ColliderComponent> pCollider)
{
	m_Colliders.push_back(pCollider);
}

std::shared_ptr<Player> Scene::GetPlayer() const
{
	return m_Player.lock();
}

const std::vector<std::weak_ptr<ColliderComponent>>& Scene::GetColliders() const
{
	return m_Colliders;
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


