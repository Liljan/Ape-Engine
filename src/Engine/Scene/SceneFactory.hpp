#pragma once

#include "Engine/Datatypes.hpp"
#include "Engine/Scene/Scene.hpp"

class SceneFactory
{
public:
	~SceneFactory() = default;

	virtual bool DoesSceneExist(uint32 Id) const = 0;
	virtual Scene* CreateScene(uint32 Id) = 0;
};
