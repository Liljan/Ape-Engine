#include "Flappy.hpp"

#include <cassert>

Flappy::Flappy()
{
	InitializeSystems();
}

void Flappy::InitializeSystems()
{
	// Mock data for reading app data.
	// The data will be read from file later.

	auto config = ReadWindowConfigFromJSON("config.json");
	assert(config);

	InitializeRenderWindow(*config);

	auto dobrow = m_SceneFactory.CreateScene(SceneType::Logo);
	auto bilbow = m_SceneFactory.CreateScene(123);
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
