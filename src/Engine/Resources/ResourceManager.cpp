#include "Engine/Resources/ResourceManager.hpp"

#include "Engine/Hasher.hpp"

#include <SFML/Graphics/Texture.hpp>

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
