#include "Testbed/Scene/LogoScene.hpp"

#include "Engine/Scene/SceneManager.hpp"

LogoScene::LogoScene(SceneManager& sceneManager)
{
	m_SceneManager = &sceneManager;
}

void LogoScene::HandleInput(sf::Event& event)
{
	if(event.type == sf::Event::KeyReleased)
	{
		switch (event.key.code)
		{
		case sf::Keyboard::Num1:
			m_SceneManager->SwitchToScene(SceneType::Game);
			break;
		default:
			break;
		}
	}
}

void LogoScene::Update(float dt)
{
}

void LogoScene::Draw(sf::RenderWindow& window)
{
	window.clear(sf::Color::Red);

	window.display();
}

void LogoScene::Load()
{
}

void LogoScene::Unload()
{
}
