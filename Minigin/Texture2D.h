#pragma once
struct SDL_Texture;
namespace elfgine
{
	/**
	 * Simple RAII wrapper for an SDL_Texture
	 */
	class Texture2D
	{
	public:
		explicit Texture2D(SDL_Texture* texture);
		~Texture2D();
		Texture2D(const Texture2D &) = delete;
		Texture2D(Texture2D &&) = delete;
		Texture2D & operator= (const Texture2D &) = delete;
		Texture2D & operator= (const Texture2D &&) = delete;

		//Functions
		int GetWidth() const;
		int GetHeight() const;
		SDL_Texture* GetSDLTexture() const;
	private:
		//Variables
		SDL_Texture* m_Texture;
	};
}
