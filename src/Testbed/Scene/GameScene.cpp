#include "Testbed/Scene/GameScene.hpp"

#include "Engine/Scene/SceneManager.hpp"

GameScene::GameScene(SceneManager& sceneManager)
{
	m_SceneManager = &sceneManager;
}

void GameScene::HandleInput(sf::Event& event)
{
	if(event.type == sf::Event::KeyReleased)
	{
		switch (event.key.code)
		{
		case sf::Keyboard::Num1:
			m_SceneManager->SwitchToScene(SceneType::Logo);
			break;
		default:
			break;
		}
	}
}

void GameScene::Update(float dt)
{
}

void GameScene::Draw(sf::RenderWindow& window)
{
	window.clear(sf::Color::Blue);

	window.display();
}

void GameScene::Load()
{
}

void GameScene::Unload()
{
}
