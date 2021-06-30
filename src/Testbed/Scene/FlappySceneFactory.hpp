#pragma once

#include "Engine/Scene/SceneFactory.hpp"
#include "Testbed/Scene/FlappySceneTypes.hpp"



class FlappySceneFactory : public SceneFactory
{
public:
	FlappySceneFactory() = default;
	~FlappySceneFactory() = default;

	bool DoesSceneExist(uint32 Id) const override;
	Scene* CreateScene(uint32 Id) override;


};
