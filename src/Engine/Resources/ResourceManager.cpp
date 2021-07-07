#include "Engine/Resources/ResourceManager.hpp"

#include "Engine/Hasher.hpp"

#include <SFML/Graphics/Texture.hpp>

#include <rapidjson/document.h>
#include <rapidjson/filereadstream.h>
#include <cstdio>

#include <iostream>
#include <memory>

bool ResourceManager::HasTexture(Id id) const
{
	return m_Textures.find(id) != m_Textures.end();
}

bool ResourceManager::LoadTexture(const std::string& path, const std::string& fileName)
{
	const Id id = Hasher::Instance().Hash(fileName);

	if(HasTexture(id))
	{
		std::cerr << "Texture " << fileName << " already loaded.\n";
		return false;
	}

	const std::string fullFilePath = std::string(path) + std::string(fileName);

	sf::Texture texture;
	bool didLoad = texture.loadFromFile(fullFilePath);

	if(!didLoad)
	{
		std::cerr << "Texture file " << fullFilePath << " could not be loaded.\n";
		return false;
	}

	m_Textures.emplace(id, std::move(texture));
	return true;
}

bool ResourceManager::UnloadTexture(Id id)
{
	auto itTexture = m_Textures.find(id);

	if(itTexture == m_Textures.end())
	{
		std::cerr << "Texture " << id << " does not exist.\n";
		return false;
	}

	// Erase does delete... right?
	m_Textures.erase(itTexture);
	return true;
}

sf::Texture* const ResourceManager::GetTexture(Id id)
{
	if(!HasTexture(id))
	{
		std::cerr << "Texture " << id << " does not exist.\n";
		return false;
	}

	return &m_Textures[id];
}

bool ResourceManager::HasSpriteAtlas(Id id) const
{
	return m_SpriteAtlases.find(id) != m_SpriteAtlases.end();
}

bool ResourceManager::LoadAtlas(const std::string& path, const std::string& fileName)
{
	const Id id = Hasher::Instance().Hash(fileName);

	if(HasSpriteAtlas(id))
	{
		std::cerr << "Sprite atlas " << fileName << " already loaded.\n";
		return false;
	}

	const std::string fullFilePath = std::string(path) + std::string(fileName) + ".json";

	SpriteAtlas atlas;

	FILE* file = fopen(fullFilePath.c_str(), "rb"); // non-Windows use "r"

	if(!file)
	{
		// print warning
		std::cerr << "Sprite atlas file " << fileName << "was not found.\n";
		return false;
	}

	char readBuffer[65536];
	rapidjson::FileReadStream stream(file, readBuffer, sizeof(readBuffer));
	fclose(file);

	rapidjson::Document document;
	document.ParseStream(stream);

	if(document.HasParseError())
	{
		std::cerr << "The json document " << fileName << "had a parse error.\n";
		return {};
	}

	const auto& meta = document["meta"];

	std::string textureName = meta["image"].GetString();

	return true;
}

bool ResourceManager::UnloadAtlas(Id id)
{
	return false;
}

SpriteAtlas* const ResourceManager::GetSpriteAtlas(Id id)
{
	if(!HasSpriteAtlas(id))
	{
		std::cerr << "Texture " << id << " does not exist.\n";
		return false;
	}

	return &m_SpriteAtlases[id];
}
