#pragma once

#include "Engine/Datatypes.hpp"
#include "Engine/Graphics/Subsprite.hpp"

#include <unordered_map>

// Forward declarations
//namespace sf
//{
//	class Texture;
//}

class SpriteAtlas
{
public:

	bool AddSprite(Id id, const sf::IntRect& rect);
	bool RemoveSprite(Id id);

	Subsprite* const GetSubsprite(Id id);

	void Clear();

private:

	std::unordered_map<Id, Subsprite> m_Subsprites;
};

