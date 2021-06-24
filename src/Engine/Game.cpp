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

sf::RenderWindow& Game::GetRenderWindow()
{
	return m_Window;
}
