#include "Testbed/Scene/FlappySceneFactory.hpp"

#include "Engine/Scene/Scene.hpp"
#include "Engine/Scene/SceneManager.hpp"

#include "Testbed/Scene/LogoScene.hpp"
#include "Testbed/Scene/GameScene.hpp"

#include <iostream>

Scene* FlappySceneFactory::CreateScene(uint32 id, SceneManager& sceneManager)
{
	// Todo: Weird casting from uint32 to enum -> please fix
	const SceneType sceneType = static_cast<SceneType>(id);

	switch(sceneType)
	{
		case SceneType::Logo:
			return new LogoScene(sceneManager);

		case SceneType::Game:
			return new GameScene(sceneManager);

		default:
		{
			std::cerr << "Could not create scene type " << id << "\n";
			return nullptr;
		}
		break;
	}
}
