#include "Testbed/Scene/LogoScene.hpp"

#include "Engine/Scene/SceneManager.hpp"

LogoScene::LogoScene(SceneManager& sceneManager) : Scene(sceneManager)
{
}

void LogoScene::HandleInput(sf::Event& event)
{

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
