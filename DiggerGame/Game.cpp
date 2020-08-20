#include "Game.h"
#include "ELFgine.h"
#include "GameIncludes.h"


//TO DO
//NO NEED TO INCLUDE THIS IN GAME SEPERATE THIS

using namespace elfgine;

void Game::Run()
{
	//Init
	elfgine::ELFgine engine;
	engine.Initialize(m_WindowWidth, m_WindowHeight);

	//Load Data
	LoadTextures();

	//Load scenes
	LoadScenes();

	//Run game
	engine.Run();
}

void Game::LoadTextures()
{
	// tell the resource manager where he can find the game data
	ResourceManager::GetInstance().Init("../Data/");
	
	auto& manager = ResourceManager::GetInstance();

	//Character sprite
	manager.AddTexture("Digger.png", "Digger");

	//Logo
	manager.AddTexture("logo.png", "Logo");

	//Background
	manager.AddTexture("background.jpg", "Background");

	//Gem
	manager.AddTexture("Gem.png", "Gem");


	/////////FONTS
	ResourceManager::GetInstance().AddFont("Lingua.otf", 36, "Lingua");
}

void Game::LoadScenes()
{
	LoadScene1();
	LoadScene2();
	LoadScene3();
}

void Game::LoadScene1()
{
	glm::vec2 middleOfWindow = { float(m_WindowWidth / 2), float(m_WindowHeight / 2) };
	//Add Observers
	std::shared_ptr<GameObserver> gameObserver = std::make_shared<GameObserver>();

	auto& scene = SceneManager::GetInstance().CreateScene("Demo");

	//Make background
	auto go = std::make_shared<GameObject>();
	auto pBackRender = std::make_shared<RenderComponent>(go->GetTransform());
	pBackRender->SetTexture("Background");
	go->AddComponent(pBackRender);
	scene.Add(go);
	go->SetPosition(middleOfWindow);

	//Make logo
	go = std::make_shared<GameObject>();
	auto pLogoRender = std::make_shared<RenderComponent>(go->GetTransform());
	pLogoRender->SetTexture("Logo");
	go->AddComponent(pLogoRender);
	go->SetPosition(middleOfWindow);

	scene.Add(go);

	//Make testplayer
	std::shared_ptr<Player> player = std::make_shared<Player>("Digger", true);
	player->AddGameObjectToComponents(player);
	player->SetPosition(100, 200);
	scene.Add(player);
	player->SetSpeed(100);

	//Make pickup
	std::shared_ptr<Pickup> gem = std::make_shared<Pickup>("Gem", glm::vec2{ 300,500 }, 10);
	gem->AddGameObjectToComponents(gem);
	scene.Add(gem);

	gem = std::make_shared<Pickup>("Gem", glm::vec2{ 200,100 }, 10);
	gem->AddGameObjectToComponents(gem);
	scene.Add(gem);


	//Make score object
	SDL_Color colorScore{ 255,255,0 };

	auto to = std::make_shared<TextObject>("0000", "Lingua", colorScore);
	to->SetPosition(float(m_WindowWidth) - 60, float(m_WindowHeight) - 20);
	scene.Add(to);

	GameManager::GetInstance().SetScoreText(to);
}

void Game::LoadScene2()
{

}
void Game::LoadScene3()
{

}
