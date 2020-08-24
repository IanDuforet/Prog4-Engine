#pragma once
#include "GameObject.h"
namespace elfgine
{
	class RenderComponent;
	class TileObject final : public GameObject
	{
	public:
		TileObject(const std::string& textureName, glm::vec2 position);
		virtual ~TileObject() = default;
		TileObject(const TileObject& other) = delete;
		TileObject(TileObject&& other) = delete;
		TileObject& operator=(const TileObject& other) = delete;
		TileObject& operator=(TileObject&& other) = delete;

		//Functions
		void SetTileState(bool state);
		bool GetTileState() const;
	private:
		//Variables
		bool m_State;
		std::weak_ptr<RenderComponent> m_pRenderComponent;
	};
}

