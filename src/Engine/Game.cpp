#include "Engine/Game.hpp"

void Game::Run()
{
	sf::Clock timer;

	while(m_Window.isOpen())
	{
		const float dt = timer.getElapsedTime().asSeconds();
		timer.restart();

		HandleInput();
		Update(dt);
		Draw();
	}
}

void Game::InitializeRenderWindow(const GameWindowConfig& config)
{
	m_Window.create(sf::VideoMode(config.width, config.height), config.title, sf::Style::Titlebar | sf::Style::Close);
	m_Window.setFramerateLimit(config.fpsTarget);
}

sf::RenderWindow& Game::GetRenderWindow()
{
	return m_Window;
}
