#pragma once

#include "Engine/Scene/Scene.hpp"
#include "Testbed/Scene/FlappySceneTypes.hpp"

class LogoScene : public Scene
{
public:
	LogoScene(SceneManager& sceneManager);
	~LogoScene() = default;

	virtual void HandleInput(sf::Event& event) override;
	virtual void Update(float dt) override;
	virtual void Draw(sf::RenderWindow& window) override;

	virtual void Load() override;
	virtual void Unload() override;

	virtual uint32 GetType() const override { return SceneType::Logo; };
};