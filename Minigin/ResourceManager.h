#pragma once
#include "Singleton.h"
#include <vector>
#include <unordered_map>
#include "SDL_ttf.h"
#include <string>
namespace elfgine
{
	class Texture2D;
	class ResourceManager final : public Singleton<ResourceManager>
	{
	public:
		void Init(const std::string& data);
		void DestroyAll();
		
		//Adders
		void AddFont(const std::string& file, unsigned int size, const std::string& fontName);
		void AddTexture(const std::string& file, const std::string& textureName);
		
		//Getters
		_TTF_Font* GetFont(const std::string& fontName) const;
		std::shared_ptr<Texture2D> GetTexture(const std::string& textureName) const;
		
	private:
		std::shared_ptr<Texture2D> LoadTexture(const std::string& file) const;
		friend class Singleton<ResourceManager>;
		ResourceManager() = default;
		std::string m_DataPath;

		//Containers
		std::unordered_map<std::string, TTF_Font*> m_pFonts;
		std::unordered_map<std::string, std::shared_ptr<Texture2D>> m_pTextures;
	};
}
