#include "Testbed/Scene/GameScene.hpp"

#include "Engine/Scene/SceneManager.hpp"
#include "Engine/Resources/ResourceManager.hpp"

#include "Engine/Hasher.hpp"

GameScene::GameScene(SceneManager& sceneManager, ResourceManager& resourceManager)
{
	m_SceneManager = &sceneManager;
	m_ResourceManager = &resourceManager;
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
	const std::string imagePath("assets/img/");

	m_ResourceManager->LoadTexture(imagePath, "Bird.png");

	const Id id = Hasher::Instance().Hash("Bird.png");

	sf::Texture* tex = m_ResourceManager->GetTexture(id);
}

void GameScene::Unload()
{
	m_ResourceManager->UnloadTexture(Hasher::Instance().Hash("Bird.png"));
}
