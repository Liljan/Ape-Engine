#pragma once

#include "Engine/Scene/SceneFactory.hpp"

#include <SFML/Window/Event.hpp>

class SceneManager
{
public:

	void SetSceneFactory(SceneFactory& sceneFactory) { m_SceneFactory = &sceneFactory; }

	void AddScene(uint32 id);
	void RemoveScene();

	void ProcessInput(sf::Event& event);
	void Update(float dt);

	void Draw(sf::RenderWindow& window);

	bool SwitchToScene(uint32 id);

private:

	SceneFactory* m_SceneFactory = nullptr;
	Scene* m_CurrentScene = nullptr;
};
