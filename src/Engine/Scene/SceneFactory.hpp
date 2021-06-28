#pragma once

#include "Engine/Datatypes.hpp"

class Scene;

class SceneFactory
{
	virtual ~SceneFactory() = default;

	virtual Scene* CreateScene(uint32 Id) = 0;
};
