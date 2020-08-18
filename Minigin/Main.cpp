#include "MiniginPCH.h"

#if _DEBUG
// ReSharper disable once CppUnusedIncludeDirective
#include <vld.h>
#endif

#include "SDL.h"
#include "ELFgine.h"

int main(int, char*[]) {
	elfgine::ELFgine engine;
	engine.Run();
    return 0;
}