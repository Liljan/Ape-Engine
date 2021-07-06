#pragma once

#include "Engine/Scene/SceneFactory.hpp"
#include "Testbed/Scene/FlappySceneTypes.hpp"

class FlappySceneFactory : public SceneFactory
{
public:
	FlappySceneFactory() = default;
	~FlappySceneFactory() = default;

	Scene* CreateScene(uint32 Id, SceneManager& sceneManager, ResourceManager& resourceManager) override;
};
