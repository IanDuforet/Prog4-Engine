#include "MiniginPCH.h"
#include "Grid.h"
#include "TileObject.h"
#include <cmath>
#include "Scene.h"

elfgine::Grid::Grid(int WindowWidth, int WindowHeight, const std::string& textureName)
	: GameObject()
	, m_TileSize(60)
{
	m_GridWidth = WindowWidth / m_TileSize;
	m_GridHeight = WindowHeight / m_TileSize;
	m_GridHeight -= 1;
	
	glm::vec2 startPos{};
	for(int i{0}; i < (m_GridHeight*m_GridWidth); i++)
	{
		int indexX = i % m_GridWidth;
		int indexY = i / m_GridWidth;
		startPos.x = float(m_TileSize * indexX);
		startPos.y = float(m_TileSize * indexY);
		startPos.x += m_TileSize/2.f;
		startPos.y += m_TileSize/2.f;
		std::shared_ptr<TileObject> tile = std::make_shared<TileObject>(textureName, startPos);
		tile->SetTileState(false);
		tile->AddGameObjectToComponents(tile);
		m_pTiles.push_back(tile);
		//pScene.AddColliderToCollection(tile->GetComponent<ColliderComponent>());
	}

	
}

void elfgine::Grid::Update(float deltaTime)
{
	for(std::shared_ptr<TileObject> t : m_pTiles)
	{
		t->Update(deltaTime);
	}
}

int elfgine::Grid::GetTileSize() const
{
	return m_TileSize;
}

const std::vector<std::shared_ptr<elfgine::TileObject>>& elfgine::Grid::GetTiles() const
{
	return m_pTiles;
}

int elfgine::Grid::GetDistance(glm::vec2 pos1, glm::vec2 pos2) const
{
	float a = pow(pos2.x, 2) - pow(pos1.x, 2);
	float b = pow(pos2.y, 2) - pow(pos1.y, 2);
	return int(sqrt(a + b));
}

void elfgine::Grid::SetDugTiles(const std::vector<int>& tiles)
{
	for (int i : tiles)
	{
		m_pTiles[i]->SetTileState(true);
		m_pTiles[i]->RemoveComponent(m_pTiles[i]->GetComponent<ColliderComponent>());
	}

}
