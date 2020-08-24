#pragma once
#include "Singleton.h"

struct SDL_Window;
struct SDL_Renderer;

namespace elfgine
{
	class Texture2D;
	/**
	 * Simple RAII wrapper for the SDL renderer
	 */
	class Renderer final : public Singleton<Renderer>
	{
	public:
		//Functions
		void Init(SDL_Window* window, int windowWidth, int windowHeight);
		void Destroy();
		void Update(float deltaTime) const;
		void RenderTexture(const Texture2D& texture, float x, float y) const;
		void RenderTexture(const Texture2D& texture, float x, float y, float width, float height) const;

		SDL_Renderer* GetSDLRenderer() const { return m_Renderer; }
	private:
		//Variables
		SDL_Renderer* m_Renderer{};
		int m_WindowWidth{};
		int m_WindowHeight{};
	};
}

