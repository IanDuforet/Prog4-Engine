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
#include "Scene.h"
#include "FPSCounter.h"
#include "Components.h"
#include "CommandInputHandler.h"
using namespace std;
using namespace std::chrono;

void elfgine::ELFgine::Initialize()
{
	if (SDL_Init(SDL_INIT_VIDEO) != 0) 
	{
		throw std::runtime_error(std::string("SDL_Init Error: ") + SDL_GetError());
	}

	m_Window = SDL_CreateWindow(
		"Programming 4 assignment",
		SDL_WINDOWPOS_UNDEFINED,
		SDL_WINDOWPOS_UNDEFINED,
		640,
		480,
		SDL_WINDOW_OPENGL
	);
	if (m_Window == nullptr) 
	{
		throw std::runtime_error(std::string("SDL_CreateWindow Error: ") + SDL_GetError());
	}

	Renderer::GetInstance().Init(m_Window);
}

/**
 * Code constructing the scene world starts here
 */
void elfgine::ELFgine::LoadGame()
{
	auto& scene = SceneManager::GetInstance().CreateScene("Demo");

	//Make background
	auto go = std::make_shared<GameObject>();
	auto pBackRender = std::make_shared<RenderComponent>(go->GetTransform());
	pBackRender->SetTexture("background.jpg", "Background");
	go->AddComponent(pBackRender);
	scene.Add(go);

	//Make logo
	go = std::make_shared<GameObject>();
	auto pLogoRender = std::make_shared<RenderComponent>(go->GetTransform());
	pLogoRender->SetTexture("logo.png", "Logo");
	go->AddComponent(pLogoRender);
	go->SetPosition(216, 180);
	
	scene.Add(go);

	//Make test character
	go = std::make_shared<GameObject>();
	auto characterSprite = std::make_shared<RenderComponent>(go->GetTransform());
	characterSprite->SetTexture("Naiian.png", "Naiian");
	go->AddComponent(characterSprite, go);

	auto rb = std::make_shared<RigidBodyComponent>();
	go->AddComponent(rb, go);

	auto control = std::make_shared<ControlComponent>(rb);
	//Assign this control to the player
	auto& commandInput = CommandInputHandler::GetInstance();
	commandInput.AssignActor(control);

	go->AddComponent(control, go);
	
	scene.Add(go);

	//Make Textobject
	ResourceManager::GetInstance().AddFont("Lingua.otf", 36, "Lingua");
	SDL_Color color{0,255,0};

	auto to = std::make_shared<TextObject>("TextTest", "Lingua", color);	
	scene.Add(to);

	m_pFPSCounter = std::make_shared<FPSCounter>(to);
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
	Initialize();

	// tell the resource manager where he can find the game data
	ResourceManager::GetInstance().Init("../Data/");

	LoadGame();

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
			while (lag >= m_msPerFrame)
			{
				sceneManager.FixedUpdate();
				lag -= m_msPerFrame;
			}
			sceneManager.Update(deltaTime);
			rendered.Update(deltaTime);
			m_pFPSCounter->Update(deltaTime);
			t += std::chrono::milliseconds(m_msPerFrame);
			std::this_thread::sleep_until(t);
		}
	}

	Cleanup();
}
