#include "MiniginPCH.h"
#include "Texture2D.h"
#include <SDL.h>

elfgine::Texture2D::~Texture2D()
{
	SDL_DestroyTexture(m_Texture);
}

int elfgine::Texture2D::GetWidth() const
{
	int width{};
	SDL_QueryTexture(m_Texture, NULL, NULL, &width, NULL);
	return width;
}

int elfgine::Texture2D::GetHeight() const
{
	int height{};
	SDL_QueryTexture(m_Texture, NULL, NULL, NULL ,&height);
	return height;
}

SDL_Texture* elfgine::Texture2D::GetSDLTexture() const
{
	return m_Texture;
}

elfgine::Texture2D::Texture2D(SDL_Texture* texture)
{
	m_Texture = texture;
}
