#pragma once

#include "Engine/Datatypes.hpp"

#include <SFML/Graphics/RenderWindow.hpp>

class SceneManager;

class Scene
{
public:
	~Scene() = default;

	virtual void HandleInput(sf::Event& event) = 0;
	virtual void Update(float dt) = 0;
	virtual void Draw(sf::RenderWindow& window) = 0;

	virtual void Load() = 0;
	virtual void Unload() = 0;

	virtual uint32 GetType() const = 0;

protected:
	SceneManager* m_SceneManager = nullptr;
};
