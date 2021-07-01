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

	auto& sceneManager = GetSceneManager();
	sceneManager.SetSceneFactory(m_SceneFactory);

	sceneManager.SwitchToScene(SceneType::Logo);
}

void Flappy::HandleInput()
{
	auto& window = GetRenderWindow();
	auto& sceneManager = GetSceneManager();

	sf::Event event;
	while(window.pollEvent(event))
	{
		// Request for closing the window
		if(event.type == sf::Event::Closed)
			window.close();

		sceneManager.ProcessInput(event);
	}
}

void Flappy::Update(float dt)
{
	auto& sceneManager = GetSceneManager();
	sceneManager.Update(dt);
}

void Flappy::Draw()
{
	sf::RenderWindow& window = GetRenderWindow();

	auto& sceneManager = GetSceneManager();
	sceneManager.Draw(window);
}
