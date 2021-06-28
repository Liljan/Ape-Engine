#include "Testbed/Scene/FlappySceneFactory.hpp"

#include "Testbed/Scene/LogoScene.hpp"
#include "Testbed/Scene/GameScene.hpp"

#include <iostream>

bool FlappySceneFactory::DoesSceneExist(uint32 id) const
{
	return id < static_cast<uint32>(SceneType::Amount);
}

Scene* FlappySceneFactory::CreateScene(uint32 id)
{
	const SceneType sceneType = static_cast<SceneType>(id);

	switch (sceneType)
	{
		case SceneType::Logo:
			return new LogoScene();

		case SceneType::Game:
			return new GameScene();

		default:
		{
			std::cerr << "Could not create scene type " << id << "\n";
			return nullptr;
		}
		break;
	}
}
