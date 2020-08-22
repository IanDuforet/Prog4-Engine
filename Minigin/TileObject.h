#pragma once
#include "GameObject.h"
namespace elfgine
{
	class RenderComponent;
	class TileObject : public GameObject
	{
	public:
		TileObject(const std::string& textureName, glm::vec2 position);
		virtual ~TileObject() = default;

		void SetTileState(bool state);
		bool GetTileState() { return m_State; };
	private:
		std::weak_ptr<RenderComponent> m_pRenderComponent;
		bool m_State{false};
	};
}

