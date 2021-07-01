#pragma once

#include "Engine/Datatypes.hpp"

// Forward declarations
class Scene;
class SceneManager;

class SceneFactory
{
public:
	~SceneFactory() = default;

	virtual Scene* CreateScene(uint32 Id, SceneManager& sceneManager) = 0;
};
