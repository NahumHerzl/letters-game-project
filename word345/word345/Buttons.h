#pragma once
#include <SFML/Graphics.hpp>

class Buttons
{
public:
	Buttons(sf::Vector2f posi);

	virtual void doActWhenPressed(sf::RenderWindow& window) = 0;
	virtual bool contains(sf::Vector2f loc);

	virtual ~Buttons();

protected:

	sf::RectangleShape m_rect;
};

