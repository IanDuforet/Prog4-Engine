#include "MiniginPCH.h"
#include "ResourceManager.h"
#include <SDL.h>
#include <SDL_image.h>
#include <SDL_ttf.h>
#include "Renderer.h"
#include "Texture2D.h"

void elfgine::ResourceManager::Init(const std::string& dataPath)
{
	m_DataPath = dataPath;

	// load support for png and jpg, this takes a while!

	if ((IMG_Init(IMG_INIT_PNG) & IMG_INIT_PNG) != IMG_INIT_PNG) 
	{
		throw std::runtime_error(std::string("Failed to load support for png's: ") + SDL_GetError());
	}

	if ((IMG_Init(IMG_INIT_JPG) & IMG_INIT_JPG) != IMG_INIT_JPG) 
	{
		throw std::runtime_error(std::string("Failed to load support for jpg's: ") + SDL_GetError());
	}

	if (TTF_Init() != 0) 
	{
		throw std::runtime_error(std::string("Failed to load support for fonts: ") + SDL_GetError());
	}
}

std::shared_ptr<elfgine::Texture2D> elfgine::ResourceManager::LoadTexture(const std::string& file) const
{
	const auto fullPath = m_DataPath + file;
	auto texture = IMG_LoadTexture(Renderer::GetInstance().GetSDLRenderer(), fullPath.c_str());
	if (texture == nullptr) 
	{
		throw std::runtime_error(std::string("Failed to load texture: ") + SDL_GetError());
	}
	return std::make_shared<Texture2D>(texture);
}

void elfgine::ResourceManager::AddFont(const std::string& file, unsigned int size, const std::string& fontName)
{
	//m_Fonts.push_back(std::make_shared<Font>(m_DataPath + file, size));

	TTF_Font* pFont = TTF_OpenFont((m_DataPath + file).c_str(), size);
	if (pFont == nullptr)
	{
		throw std::runtime_error(std::string("Failed to load font: ") + SDL_GetError());
	}

	std::pair<std::string, TTF_Font*> Pair(fontName, pFont);
	m_pFonts.insert(Pair);
}

void elfgine::ResourceManager::AddTexture(const std::string& file, const std::string& textureName)
{
	std::shared_ptr<Texture2D> pTexture = LoadTexture(file);
	
	std::pair<std::string, std::shared_ptr<Texture2D>> Pair(textureName, pTexture);
	m_pTextures.insert(Pair);
}

TTF_Font* elfgine::ResourceManager::GetFont(const std::string& fontName)
{
	return m_pFonts.at(fontName);
}

std::shared_ptr<elfgine::Texture2D> elfgine::ResourceManager::GetTexture(const std::string& textureName)
{
	return m_pTextures.at(textureName);
}


void elfgine::ResourceManager::DestroyAll()
{
	for(std::pair<std::string, TTF_Font*> pair : m_pFonts)
	{
		TTF_CloseFont(pair.second);
	}
}




