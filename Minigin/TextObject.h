#pragma once
#include "GameObject.h"
#include <string>
#include <SDL_ttf.h>

namespace elfgine
{
	class RenderComponent;
	class TextObject final : public GameObject
	{
	public:
		TextObject(const std::string& text, const std::string& fontName, const SDL_Color& color);
		virtual ~TextObject() = default;
		TextObject(const TextObject& other) = delete;
		TextObject(TextObject&& other) = delete;
		TextObject& operator=(const TextObject& other) = delete;
		TextObject& operator=(TextObject&& other) = delete;

		//Functions
		void Update(float deltaTime) override;
		void FixedUpdate() override;
		void SetText(const std::string& text);
		void SetRenderComponent(std::shared_ptr<RenderComponent> pRenderComponent);
		
	private:
		//Variables
		bool m_NeedsUpdate;
		std::string m_Text;
		SDL_Color m_TextColor;
		TTF_Font* m_pFont;
		std::weak_ptr<RenderComponent> m_pRenderComponent;
	};
	
}

