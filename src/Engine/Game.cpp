#include "Engine/Game.hpp"

#include <rapidjson/document.h>
#include <rapidjson/filereadstream.h>
#include <cstdio>

#include <iostream>

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

std::optional<GameWindowConfig> Game::ReadWindowConfigFromJSON(const std::string& fileName)
{
	FILE* file = fopen(fileName.c_str(), "rb"); // non-Windows use "r"

	if(!file)
	{
		// print warning
		std::cerr << "Window config file " << fileName << "was not found.\n";
		return {};
	}

	//
	char readBuffer[65536];
	rapidjson::FileReadStream stream(file, readBuffer, sizeof(readBuffer));
	fclose(file);

	rapidjson::Document document;
	document.ParseStream(stream);

	if(document.HasParseError())
	{
		std::cerr << "The json document " << fileName << "had a parse error.\n";
		return {};
	}

	GameWindowConfig config;

	auto str = document["title"].GetString();

	config.title = document["title"].GetString();
	config.width = document["width"].GetUint();
	config.height = document["height"].GetUint();
	config.fullscreen = document["fullscreen"].GetBool();
	config.resizable = document["resizeable"].GetBool();
	config.fpsTarget = document["fps_target"].GetUint();
	
	return config;
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

SceneManager& Game::GetSceneManager()
{
	return m_SceneManager;
}
