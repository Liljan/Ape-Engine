#include "Engine/Scene/SceneManager.hpp"

#include <iostream>
#include <cassert>

void SceneManager::AddScene(uint32 id)
{
	m_CurrentScene = m_SceneFactory->CreateScene(id);

	assert(m_CurrentScene);
	m_CurrentScene->Load();
}

void SceneManager::RemoveScene()
{
	m_CurrentScene->Unload();
	delete m_CurrentScene;
}

void SceneManager::ProcessInput(sf::Event& event)
{
	m_CurrentScene->HandleInput(event);
}

void SceneManager::Update(float dt)
{
	m_CurrentScene->Update(dt);
}

void SceneManager::Draw(sf::RenderWindow& window)
{
	m_CurrentScene->Draw(window);
}

bool SceneManager::SwitchToScene(uint32 id)
{
	if(id == m_CurrentScene->GetType())
	{
		std::cerr << "Warning: Trying to switch to the same scene.\n";
		return false;
	}

	if(!m_SceneFactory->DoesSceneExist(id))
	{
		std::cerr << "Warning: Trying to switch to an invalid scene id.\n";
		return false;
	}
	
	RemoveScene();
	AddScene(id);

	return true;
}
