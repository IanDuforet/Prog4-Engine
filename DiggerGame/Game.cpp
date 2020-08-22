#include "MiniginPCH.h"
#include "Game.h"
#include "ELFgine.h"
#include "GameIncludes.h"
#include <glm/detail/type_vec2.hpp>

//TO DO
//NO NEED TO INCLUDE THIS IN GAME SEPARATE THIS

void Game::Run()
{
	
	//Init
	elfgine::ELFgine engine;
	engine.Initialize(m_WindowWidth, m_WindowHeight);

	//Load Data
	LoadTextures();
	//Add Observers
	auto& observers = elfgine::ObserverManager::GetInstance();
	observers.AddObserver(std::make_shared<GameObserver>(), "Game");
	observers.AddObserver(std::make_shared<ScoreObserver>() , "Score");
	
	//Load scenes
	LoadScenes();

	//Run game
	engine.Run();
}

void Game::LoadTextures()
{
	// tell the resource manager where he can find the game data
	elfgine::ResourceManager::GetInstance().Init("../Data/");
	
	auto& manager = elfgine::ResourceManager::GetInstance();

	//Character sprite
	manager.AddTexture("Digger.png", "Digger");

	//Dugtile sprite
	manager.AddTexture("DugTile.png", "DugTile");
	
	//Gem
	manager.AddTexture("Gem.png", "Gem");

	//Background
	manager.AddTexture("Background1.png", "Background1");
	

	/////////FONTS
	elfgine::ResourceManager::GetInstance().AddFont("Lingua.otf", 36, "Lingua");
}

void Game::LoadScenes()
{
	LoadScene1();
	LoadScene2();
	LoadScene3();
}

void Game::LoadScene1()
{
	//RENDERING ORDER MATTERS (NOT DEPTH INDEX IMPLEMENTED)

	glm::vec2 middleOfWindow = { float(m_WindowWidth / 2), float(m_WindowHeight / 2) };
	

	auto& scene = elfgine::SceneManager::GetInstance().CreateScene("Demo");

	
	//Make background
	std::shared_ptr<elfgine::SpriteObject> background = std::make_shared<elfgine::SpriteObject>("Background1", middleOfWindow);
	background->AddGameObjectToComponents(background);
	scene.Add(background);

	
	//Make Grid
	std::shared_ptr<elfgine::Grid> grid = std::make_shared<elfgine::Grid>(m_WindowWidth, m_WindowHeight, "DugTile");
	scene.Add(grid);
	

	//Make pickup
	std::shared_ptr<elfgine::Pickup> gem = std::make_shared<elfgine::Pickup>("Gem", glm::vec2{ 300,500 }, 10);
	gem->AddGameObjectToComponents(gem);
	scene.Add(gem);
	
	//Make pickup
	gem = std::make_shared<elfgine::Pickup>("Gem", glm::vec2{ 200,100 }, 10);
	gem->AddGameObjectToComponents(gem);
	scene.Add(gem);

	//Make testplayer
	std::shared_ptr<elfgine::Player> player = std::make_shared<elfgine::Player>("Digger", true);
	player->AddGameObjectToComponents(player);
	player->SetPosition(30	, 30);
	scene.Add(player);
	player->SetSpeed(100);
	//Make score object
	SDL_Color colorScore{ 255,255,0 };

	auto scoreText = std::make_shared<elfgine::TextObject>("0000", "Lingua", colorScore);
	scoreText->SetPosition(float(m_WindowWidth) - 60, float(m_WindowHeight) - 20);
	scene.Add(scoreText);

	//Add Game Manager
	std::shared_ptr<GameManager> pGameManager = std::make_shared<GameManager>();
	pGameManager->SetScoreText(scoreText);
	pGameManager->SetGrid(grid);
	pGameManager->SetPlayer(player);
	scene.Add(pGameManager);

	std::shared_ptr<ScoreObserver> pScore = std::dynamic_pointer_cast<ScoreObserver>(elfgine::ObserverManager::GetInstance().GetObserver("Score"));
	pScore->SetGameManager(pGameManager);
}

void Game::LoadScene2()
{

}
void Game::LoadScene3()
{

}
