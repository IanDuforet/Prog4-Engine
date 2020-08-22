#include "MiniginPCH.h"
#include "ELFgine.h"
#include <chrono>
#include <thread>
#include "InputManager.h"
#include "SceneManager.h"
#include "Renderer.h"
#include "ResourceManager.h"
#include <SDL.h>
#include "TextObject.h"
#include "GameObject.h"
#include "Player.h"
#include "Scene.h"
#include "FPSCounter.h"
#include "Components.h"
#include "CommandInputHandler.h"
#include "Pickup.h"
#include "GameObserver.h"
#include "GameManager.h"
#include "Texture2D.h"
using namespace std;
using namespace std::chrono;

void elfgine::ELFgine::Initialize(int windowWidth, int windowHeight)
{
	if (SDL_Init(SDL_INIT_VIDEO) != 0) 
	{
		throw std::runtime_error(std::string("SDL_Init Error: ") + SDL_GetError());
	}

	m_Window = SDL_CreateWindow(
		"Programming 4 assignment",
		SDL_WINDOWPOS_UNDEFINED,
		SDL_WINDOWPOS_UNDEFINED,
		windowWidth,
		windowHeight,
		SDL_WINDOW_OPENGL
	);
	if (m_Window == nullptr) 
	{
		throw std::runtime_error(std::string("SDL_CreateWindow Error: ") + SDL_GetError());
	}

	Renderer::GetInstance().Init(m_Window, windowWidth, windowHeight);
}


void elfgine::ELFgine::Cleanup()
{
	Renderer::GetInstance().Destroy();
	ResourceManager::GetInstance().DestroyAll();
	SDL_DestroyWindow(m_Window);
	m_Window = nullptr;
	SDL_Quit();
}

void elfgine::ELFgine::Run()
{	
	{
		auto t = std::chrono::high_resolution_clock::now();
		auto& sceneManager = SceneManager::GetInstance();
		auto& input = InputManager::GetInstance();
		auto& rendered = Renderer::GetInstance();
		auto& commandInput = CommandInputHandler::GetInstance();
		
		bool doContinue = true;
		auto lastTime = std::chrono::high_resolution_clock::now();
		float lag = 0.0f;
		while (doContinue)
		{
			const auto currentTime = std::chrono::high_resolution_clock::now();
			float deltaTime = std::chrono::duration<float>(currentTime - lastTime).count();
			lastTime = currentTime;
			lag += deltaTime;
			commandInput.HandleCommands();
			commandInput.HandleContinuous();
			doContinue = !input.HasQuit();
			sceneManager.CheckToDelete();
			while (lag >= m_msPerFrame)
			{
				sceneManager.FixedUpdate();
				lag -= m_msPerFrame;
			}
			sceneManager.Update(deltaTime);
			rendered.Update(deltaTime);
			t += std::chrono::milliseconds(m_msPerFrame);
			std::this_thread::sleep_until(t);
		}
	}

	Cleanup();
}

