#include "Engine/Scene/Scene.hpp"
#include "Testbed/Scene/FlappySceneTypes.hpp"

class GameScene : public Scene
{
public:
	~GameScene() = default;

	virtual void HandleInput(sf::Event& event) override;
	virtual void Update(float dt) override;
	virtual void Draw(sf::RenderWindow& window) override;

	virtual void Load() override;
	virtual void Unload() override;

	virtual uint32 GetType() const override { return SceneType::Game; };
};