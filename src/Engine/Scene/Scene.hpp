#pragma once

#include "Engine/Datatypes.hpp"

// Fwd declarations
namespace sf
{
	class RenderWindow;
};

class Scene
{
public:
	~Scene() = default;

	virtual void HandleInput() = 0;
	virtual void Update(float dt) = 0;
	virtual void Draw(sf::RenderWindow& window) = 0;

	virtual void Load() = 0;
	virtual void Unload() = 0;

	virtual uint32 GetType() const = 0;
};