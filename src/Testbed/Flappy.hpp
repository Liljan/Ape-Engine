#pragma once

#include "Engine/Game.hpp"

#include "Testbed/Scene/FlappySceneFactory.hpp"

class Flappy : public Game
{
public:

	Flappy();

	virtual void InitializeSystems() override;

	virtual void HandleInput() override;
	virtual void Update(float dt) override;
	virtual void Draw() override;

private:

	FlappySceneFactory m_SceneFactory;
};
