#pragma once

#include "Engine/Datatypes.hpp"

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

private:

	std::unordered_map<Id, sf::Texture> m_Textures;
	//std::unordered_map<uint32, sf::Texture*> m_SoundBuffers;
};
