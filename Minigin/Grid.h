#pragma once
#include "GameObject.h"

namespace elfgine
{
	class Scene;
	class Player;
	class TileObject;
	class Grid : public GameObject
	{
	public:
		Grid(int WindowWidth, int WindowHeight, const std::string& textureName);
		virtual ~Grid() = default;
		Grid(const Grid& other) = delete;
		Grid(Grid&& other) = delete;
		Grid& operator=(const Grid& other) = delete;
		Grid& operator=(Grid&& other) = delete;

		//Functions
		void Update(float deltaTime) override;
		
		int GetTileSize() const;
		int GetDistance(glm::vec2 pos1, glm::vec2 pos2) const;
		void SetDugTiles(const std::vector<int>& tiles);
		const std::vector<std::shared_ptr<TileObject>>& GetTiles() const;
	private:
		std::vector<std::shared_ptr<TileObject>> m_pTiles;
		int m_GridWidth, m_GridHeight;
		int m_TileSize;
	};
	
}
