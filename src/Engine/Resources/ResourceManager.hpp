#pragma once

#include "Engine/Graphics/SpriteAtlas.hpp"

#include <unordered_map>

namespace sf
{
	class Texture;
	//class SoundBuffer;
};

class ResourceManager
{
public:

	bool HasTexture(Id id) const;
	bool LoadTexture(const std::string& path, const std::string& fileName);
	bool UnloadTexture(Id id);

	sf::Texture* const GetTexture(Id id);

	bool HasSpriteAtlas(Id id) const;
	bool LoadAtlas(const std::string& path, const std::string& fileName);
	bool UnloadAtlas(Id id);

	SpriteAtlas* const GetSpriteAtlas(Id id);


private:

	std::unordered_map<Id, sf::Texture> m_Textures;
	std::unordered_map<Id, SpriteAtlas> m_SpriteAtlases;

	//std::unordered_map<uint32, sf::Texture*> m_SoundBuffers;
};
