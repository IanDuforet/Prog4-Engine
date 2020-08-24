#pragma once
struct SDL_Window;
namespace elfgine
{
	class FPSCounter;
	class ELFgine
	{
	public:
		//Functions
		void Initialize(int windowWidth, int windowHeight);
		void Cleanup();
		void Run();
	private:
		//Variables
		static const int m_msPerFrame = 16;
		SDL_Window* m_Window{};
	};
}