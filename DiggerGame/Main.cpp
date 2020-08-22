#include "MiniginPCH.h"
#include "Game.h"
#include "ELFgine.h"

#if _DEBUG
// ReSharper disable once CppUnusedIncludeDirective
#include <vld.h>
#endif

//Variables
int m_WindowHeight{ 600 };
int m_WindowWidth{ 960 };

int main(int, char* [])
{
	
	
	std::shared_ptr<Game> pGame = std::make_shared<Game>();

	//Run game
	pGame->Run();
	
	return 0;
}
