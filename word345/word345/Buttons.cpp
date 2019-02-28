#include "Buttons.h"



Buttons::Buttons(sf::Vector2f posi) :
	m_rect({ 150,150 })
{
	m_rect.setPosition(posi);
	m_rect.setFillColor(sf::Color::Transparent);
}

bool Buttons::contains(sf::Vector2f loc)
{
	return m_rect.getGlobalBounds().contains(loc);
}


Buttons::~Buttons()
{
}
