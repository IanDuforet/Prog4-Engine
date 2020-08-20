#include "MiniginPCH.h"
#include "Game.h"

#if _DEBUG
// ReSharper disable once CppUnusedIncludeDirective
#include <vld.h>
#endif


int main(int, char* [])
{
	std::shared_ptr<Game> game = std::make_shared<Game>();
	game->Run();
	return 0;
}
