#pragma once

#include "Datatypes.hpp"

#include "Scene/SceneManager.hpp"

#include <SFML/Graphics.hpp>

#include <string>
#include <optional>

struct GameWindowConfig
{
	std::string title;

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

	std::optional<GameWindowConfig> ReadWindowConfigFromJSON(const std::string& fileName);
	void InitializeRenderWindow(const GameWindowConfig& config);

	sf::RenderWindow& GetRenderWindow();
	SceneManager& GetSceneManager();

private:
	sf::RenderWindow m_Window;
	SceneManager m_SceneManager;
};
