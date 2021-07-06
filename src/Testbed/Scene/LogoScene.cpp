#include "Testbed/Scene/LogoScene.hpp"

#include "Engine/Scene/SceneManager.hpp"
#include "Engine/Resources/ResourceManager.hpp"

LogoScene::LogoScene(SceneManager& sceneManager, ResourceManager& resourceManager)
{
	m_SceneManager = &sceneManager;
	m_ResourceManager = &resourceManager;
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
