#pragma once

#include "Engine/Scene/SceneFactory.hpp"
#include "Engine/Resources/ResourceManager.hpp"

#include <SFML/Window/Event.hpp>

// Forward declarations

namespace sf
{
	class RenderWindow;
};

class SceneManager
{
public:

	void SetSceneFactory(SceneFactory& sceneFactory) { m_SceneFactory = &sceneFactory; }
	void SetResourceManager(ResourceManager& resourceManager) { m_ResourceManager = &resourceManager; }

	void ProcessInput(sf::Event& event);
	void Update(float dt);

	void Draw(sf::RenderWindow& window);

	bool SwitchToScene(uint32 id);

private:
	void AddScene(uint32 id);
	void RemoveScene();

private:

	SceneFactory* m_SceneFactory = nullptr;
	ResourceManager* m_ResourceManager = nullptr;

	Scene* m_CurrentScene = nullptr;
};
