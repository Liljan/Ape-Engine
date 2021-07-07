#pragma once

#include <SFML/Graphics/Rect.hpp>

struct Subsprite
{
	Subsprite(const sf::IntRect& rect) : textureCoordinates(rect) {};

	sf::IntRect textureCoordinates;
};
