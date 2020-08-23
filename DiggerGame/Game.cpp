#include "MiniginPCH.h"
#include "Game.h"
#include "ELFgine.h"
#include "GameIncludes.h"
#include <glm/detail/type_vec2.hpp>
#include <fstream>

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
	manager.AddTexture("Images/Digger.png", "Digger");

	//Dugtile sprite
	manager.AddTexture("Images/DugTile.png", "DugTile");
	
	//Emerald
	manager.AddTexture("Images/Emerald.png", "Emerald");

	//Bag
	manager.AddTexture("Images/Bag.png", "Bag");
	
	//Backgrounds
	manager.AddTexture("Images/Background1.png", "Background1");

	//Projectile
	manager.AddTexture("Images/Projectile.png", "Projectile");
	
	/////////FONTS
	elfgine::ResourceManager::GetInstance().AddFont("Fonts/Lingua.otf", 36, "Lingua");
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
	auto& scene = elfgine::SceneManager::GetInstance().CreateScene("Demo");

	//RENDERING ORDER MATTERS (NOT DEPTH INDEX IMPLEMENTED)
	//Make background
	std::shared_ptr<elfgine::SpriteObject> background = std::make_shared<elfgine::SpriteObject>("Background1", middleOfWindow);
	background->AddGameObjectToComponents(background);
	scene.Add(background);
	//Make Grid
	std::shared_ptr<elfgine::Grid> grid = std::make_shared<elfgine::Grid>(m_WindowWidth, m_WindowHeight, "DugTile");
	scene.Add(grid);
	
	//Level parsing
	//TO DO: MOVE THIS TO A CLASS OR OTHER FUNCTION

	int pickUpType{0};
	glm::vec2 pos{0,0};
	std::vector<int> dugTiles{};
	
	std::ifstream file;
	std::string line;
	std::string startchar;

	
	file.open("../Data/Levels/Level1.txt", std::ios::in);
	if (file.is_open())
	{
		while (!file.eof())
		{
			std::getline(file, line);
			//Find first character
			startchar = line.substr(0, line.find(' '));
			//Pickup
			if (startchar == "p")
			{
				line = line.substr(2);
				//Find untill comma
				float posX = std::stof(line.substr(0, line.find(',')));
				//Remove untill next comma
				line = line.substr(line.find(',') + 1);
				//Add to vector
				float posY = std::stof(line.substr(0, line.find(',')));
				pos.x = posX;
				pos.y = posY;
				pos.x = (pos.x * 60) + 30;
				pos.y = (pos.y * 60) + 30;
				//Remove untill next comma
				line = line.substr(line.find(',') + 1);
				//Find untill komma
				pickUpType = std::stoi(line.substr(0, line.find(',')));

				//Make Pickup depending on type
				if(pickUpType == 1)
				{
					std::shared_ptr<elfgine::Pickup> pPickup = std::make_shared<elfgine::Pickup>("Emerald", pos, m_EmeraldValue);
					pPickup->AddGameObjectToComponents(pPickup);
					scene.Add(pPickup);
				}
				else if(pickUpType == 2)
				{
					std::shared_ptr<elfgine::Pickup> pPickup = std::make_shared<elfgine::Pickup>("Bag", pos, m_GoldValue);
					pPickup->AddGameObjectToComponents(pPickup);
					scene.Add(pPickup);
				}	
			}
			else if (startchar == "t")
			{
				line = line.substr(2);
				//Loop till the end
				while (line != "%,")
				{
					//Add tile index
					dugTiles.push_back(std::stoi(line.substr(0, line.find(','))));
					line = line.substr(line.find(',') + 1);
				}
				grid->SetDugTiles(dugTiles);
			}
		}
	}
	file.close();

	
	//Make Player
	std::shared_ptr<elfgine::Player> player = std::make_shared<elfgine::Player>("Digger", true);
	player->AddGameObjectToComponents(player);
	player->SetPosition(middleOfWindow.x	, 30);
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

	//Add Score Observer
	std::shared_ptr<ScoreObserver> pScore = std::dynamic_pointer_cast<ScoreObserver>(elfgine::ObserverManager::GetInstance().GetObserver("Score"));
	pScore->SetGameManager(pGameManager);
}

void Game::LoadScene2()
{

}
void Game::LoadScene3()
{

}