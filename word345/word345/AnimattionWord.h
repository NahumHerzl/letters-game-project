#pragma once
#include "utilities.h"
#include <SFML/Graphics.hpp>

class AnimattionWord
{
public:
	AnimattionWord(sf::Vector2f pos, int size, int len, bool dir);
	void drow(sf::RenderWindow &window, animationColor color);
	~AnimattionWord();

private:
	sf::RectangleShape m_rect;

};

