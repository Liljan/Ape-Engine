#include "Engine/Scene/SceneManager.hpp"

void SceneManager::AddScene(uint32 id)
{
	m_CurrentScene = m_SceneFactory->CreateScene(id);
	m_CurrentScene->Load();
}

void SceneManager::ProcessInput()
{
	m_CurrentScene->HandleInput();
}

void SceneManager::Update(float dt)
{
	m_CurrentScene->Update(dt);
}

void SceneManager::Draw(sf::RenderWindow& window)
{
	m_CurrentScene->Draw(window);
}
