#pragma once
#include "GameObject.h"

namespace elfgine
{
	class Player;
	class TileObject;
	class Grid : public GameObject
	{
	public:
		Grid(int WindowWidth, int WindowHeight, const std::string& textureName);
		void Update(float deltaTime) override;
		~Grid() = default;
		int GetTileSize();
		std::shared_ptr<TileObject> GetNearestTile(std::shared_ptr<GameObject> pObject);
		int GetDistance(glm::vec2 pos1, glm::vec2 pos2);
	private:
		std::vector<std::shared_ptr<TileObject>> m_pTiles;
		int m_GridWidth, m_GridHeight;
		int m_Tilesize{60};
	};
	
}
