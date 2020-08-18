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
		void AddFont(const std::string& file, unsigned int size, const std::string& textureName);
		void AddTexture(const std::string& file, const std::string& fontName);
		_TTF_Font* GetFont(const std::string& fontName);
		std::shared_ptr<Texture2D> GetTexture(const std::string& textureName);
		void DestroyAll();
	private:
		std::shared_ptr<Texture2D> LoadTexture(const std::string& file) const;
		friend class Singleton<ResourceManager>;
		ResourceManager() = default;
		std::string m_DataPath;
		
		std::unordered_map<std::string, TTF_Font*> m_pFonts;
		std::unordered_map<std::string, std::shared_ptr<Texture2D>> m_pTextures;
	};
}
