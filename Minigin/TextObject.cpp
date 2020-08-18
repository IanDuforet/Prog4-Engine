#include "MiniginPCH.h"
#include "TextObject.h"
#include "ResourceManager.h"
#include "Renderer.h"
#include "Texture2D.h"
#include "RenderComponent.h"

elfgine::TextObject::TextObject(const std::string& text, const std::string& fontName, const SDL_Color& color)
	: GameObject()
	, m_Text(text)
	, m_NeedsUpdate(true)
	, m_pFont(nullptr)
	, m_TextColor(color)	
{
	m_pFont = ResourceManager::GetInstance().GetFont(fontName);
	std::shared_ptr<RenderComponent> pRc = std::make_shared<RenderComponent>(GetTransform());
	AddComponent(pRc);
	m_pRenderComponent = pRc;
}

elfgine::TextObject::~TextObject()
{
	
}

void elfgine::TextObject::Update(float deltaTime)
{
	if(m_NeedsUpdate)
	{
		const auto surf = TTF_RenderText_Blended(m_pFont, m_Text.c_str(), m_TextColor);
		if (!surf)
		{
			std::cout << "ERROR: Render text: '" << m_Text << "' failed: " << SDL_GetError() << std::endl;
			return;
		}

		auto texture = SDL_CreateTextureFromSurface(Renderer::GetInstance().GetSDLRenderer(), surf);
		if (!texture)
		{
			std::cout << "ERROR: Create text: '" << m_Text << "' from surface failed:" << SDL_GetError() << std::endl;
			return;
		}

		SDL_FreeSurface(surf);

		m_pRenderComponent.lock()->ChangeTexture(std::make_shared<Texture2D>(texture));

		m_NeedsUpdate = false;
	}

	GameObject::Update(deltaTime);
}

void elfgine::TextObject::FixedUpdate()
{
	
}

void elfgine::TextObject::SetText(const std::string& text)
{
	m_Text = text;
	m_NeedsUpdate = true;
	
}

void elfgine::TextObject::SetRenderComponent(std::shared_ptr<RenderComponent> pRenderComponent)
{
	m_pRenderComponent = pRenderComponent;
}


