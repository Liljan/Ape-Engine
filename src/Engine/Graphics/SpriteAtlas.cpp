#include "Engine/Graphics/SpriteAtlas.hpp"

#include <iostream>
#include <memory>

bool SpriteAtlas::AddSprite(Id id, const sf::IntRect& rect)
{
	if(m_Subsprites.find(id) != m_Subsprites.end())
	{
		std::cerr << "Sub-sprite" << id << " already added.\n";
		return false;
	}

	m_Subsprites.insert(std::pair<Id, sf::IntRect>(id, rect));
	return true;
}

bool SpriteAtlas::RemoveSprite(Id id)
{
	if(m_Subsprites.find(id) == m_Subsprites.end())
	{
		std::cerr << "Failed to remove sub-sprite" << id << " since it was not found.\n";
		return false;
	}

	m_Subsprites.erase(id);
	return true;
}

Subsprite* const SpriteAtlas::GetSubsprite(Id id)
{
	auto it = m_Subsprites.find(id);

	if(it == m_Subsprites.end())
	{
		std::cerr << "Sub-sprite" << id << " not found.\n";
		return nullptr;
	}
	
	return &m_Subsprites[id];
}

void SpriteAtlas::Clear()
{
	m_Subsprites.clear();
}
