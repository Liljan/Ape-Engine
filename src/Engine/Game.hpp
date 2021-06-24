#pragma once

#include <SFML/Graphics.hpp>

class Game
{
public:

	virtual ~Game() = default;

	virtual void InitializeSystems() = 0;

	void Run();

	virtual void HandleInput() = 0;
	virtual void Update(float dt) = 0;
	virtual void Draw() = 0;

protected:

	sf::RenderWindow& GetRenderWindow();

private:
	sf::RenderWindow m_Window;
};
