#include "MiniginPCH.h"
#include "Grid.h"
#include "TileObject.h"
#include <cmath>

elfgine::Grid::Grid(int WindowWidth, int WindowHeight, const std::string& textureName)
{
	m_GridWidth = WindowWidth / m_Tilesize;
	m_GridHeight = WindowHeight / m_Tilesize;
	m_GridHeight -= 1;
	
	glm::vec2 startPos{};
	for(int i{0}; i < (m_GridHeight*m_GridWidth); i++)
	{
		int indexX = i % m_GridWidth;
		int indexY = i / m_GridWidth;
		startPos.x = float(m_Tilesize * indexX);
		startPos.y = float(m_Tilesize * indexY);
		startPos.x += m_Tilesize/2.f;
		startPos.y += m_Tilesize/2.f;
		std::shared_ptr<TileObject> tile = std::make_shared<TileObject>(textureName, startPos);
		tile->SetTileState(false);
		tile->AddGameObjectToComponents(tile);
		m_pTiles.push_back(tile);
	}

	
}

void elfgine::Grid::Update(float deltaTime)
{
	for(std::shared_ptr<TileObject> t : m_pTiles)
	{
		t->Update(deltaTime);
	}
}

int elfgine::Grid::GetTileSize()
{
	return m_Tilesize;
}

std::shared_ptr<elfgine::TileObject> elfgine::Grid::GetNearestTile(std::shared_ptr<GameObject> pObject)
{
	std::shared_ptr<TileObject> closestTile = m_pTiles[0];
	int dist = GetDistance(pObject->GetTransform()->GetPosition(), m_pTiles[0]->GetTransform()->GetPosition()); //Calculate distance
	for (std::shared_ptr<TileObject> t : m_pTiles)
	{
		int tempDist = GetDistance(pObject->GetTransform()->GetPosition(), t->GetTransform()->GetPosition()); // Calculate distance between tile and player
		if (tempDist < dist) 
		{
			closestTile = t;
		}
	}
	return closestTile;
}

int elfgine::Grid::GetDistance(glm::vec2 pos1, glm::vec2 pos2)
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
