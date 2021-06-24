#include "Testbed/Flappy.hpp"

#include <rapidjson/document.h>

int main()
{
	rapidjson::Document doc;

	Flappy game;

	game.Run();

	return 0;
}