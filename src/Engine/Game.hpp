#pragma once

#include "Datatypes.hpp"

#include <SFML/Graphics.hpp>


struct GameWindowConfig
{
	const char* title;

	uint32 width;
	uint32 height;
	uint32 fpsTarget;
	
	// Todo: Add bools for fullscreen etc.
	bool fullscreen = false;
	bool resizable = false;
};


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

	void InitializeRenderWindow(const GameWindowConfig& config);

	sf::RenderWindow& GetRenderWindow();

private:
	sf::RenderWindow m_Window;
};
