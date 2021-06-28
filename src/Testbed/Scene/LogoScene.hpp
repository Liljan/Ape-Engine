#pragma once

#include "Engine/Scene/Scene.hpp"
#include "Testbed/Scene/FlappySceneTypes.hpp"

class LogoScene : public Scene
{
	~LogoScene() = default;

	virtual void HandleInput() override;
	virtual void Update(float dt) override;
	virtual void Draw(sf::RenderWindow& window) override;

	virtual void Load() override;
	virtual void Unload() override;

	virtual uint32 GetType() const override { return SceneType::Logo; };
};