#pragma once

#include "Engine/Scene/SceneFactory.hpp"

class SceneManager
{
public:

	void SetSceneFactory(SceneFactory& sceneFactory) { m_SceneFactory = &sceneFactory; }

	void AddScene(uint32 id);

	void ProcessInput();
	void Update(float dt);

	void Draw(sf::RenderWindow& window);

private:

	SceneFactory* m_SceneFactory = nullptr;
	Scene* m_CurrentScene = nullptr;
	uint32 m_CurrentSceneId = 0;
};
