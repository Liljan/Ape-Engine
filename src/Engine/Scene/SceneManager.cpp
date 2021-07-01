#include "Engine/Scene/SceneManager.hpp"

#include "Engine/Scene/Scene.hpp"

#include <iostream>
#include <cassert>

void SceneManager::AddScene(uint32 id)
{
	m_CurrentScene = m_SceneFactory->CreateScene(id, *this);

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
	if(m_CurrentScene)
	{
		if(id == m_CurrentScene->GetType())
		{
			std::cerr << "Warning: Trying to switch to the same scene.\n";
			return false;
		}

		RemoveScene();
	}

	AddScene(id);
	return true;
}
