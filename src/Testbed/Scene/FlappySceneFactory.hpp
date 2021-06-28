#pragma once

#include "Engine/Scene/SceneFactory.hpp"

class FlappySceneFactory : public SceneFactory
{
public:
	FlappySceneFactory() = default;
	~FlappySceneFactory() = default;

	Scene* CreateScene(uint32 Id) override;
};
