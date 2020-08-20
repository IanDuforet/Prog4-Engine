#pragma once
struct SDL_Window;
namespace elfgine
{
	class FPSCounter;
	class ELFgine
	{
	public:
		void Initialize(int windowWidth, int windowHeight);

		void Cleanup();
		void Run();

	private:
		
		void CheckToDelete();
		static const int m_msPerFrame = 16; //16 for 60 fps, 33 for 30 fps
		SDL_Window* m_Window{};
		

	};
}