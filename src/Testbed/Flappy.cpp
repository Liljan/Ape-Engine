#include "Flappy.hpp"

Flappy::Flappy()
{
	InitializeSystems();
}

void Flappy::InitializeSystems()
{

	// Mock data for reading app data.
	// The data will be read from file later.

	GameWindowConfig config;
	config.fullscreen = false;
	config.width = 1080;
	config.height = 720;
	config.resizable = false;
	config.title = "Flappy Struts";
	config.fpsTarget = 60;

	InitializeRenderWindow(config);
}

void Flappy::HandleInput()
{
	sf::RenderWindow& window = GetRenderWindow();

	sf::Event event;
	while(window.pollEvent(event))
	{
		// Request for closing the window
		if(event.type == sf::Event::Closed)
			window.close();
	}
}

void Flappy::Update(float dt)
{

}

void Flappy::Draw()
{
	sf::RenderWindow& window = GetRenderWindow();

	window.clear(sf::Color::Yellow);

	window.display();
}
