#include "AnimattionWord.h"



AnimattionWord::AnimattionWord(sf::Vector2f pos, int size, int len, bool dir)
{
	m_rect.setPosition(pos);
	m_rect.setFillColor(sf::Color::Color(250, 40, 40, 100));
	m_rect.setOutlineThickness(-6);

	switch (dir)
	{
	case 0:
		m_rect.setSize({ (float)size, (float)(size*len) });
		break;
	case 1:
		m_rect.setSize({ (float)(size*len), (float)size });
		break;
	}
}

void AnimattionWord::drow(sf::RenderWindow &window, animationColor color)
{
	switch (color)
	{
	case orange:
		m_rect.setOutlineColor(sf::Color::Yellow);
		break;
	case red:
		m_rect.setOutlineColor(sf::Color::Red);
		break;
	case pink:
		m_rect.setOutlineColor(sf::Color::Cyan);
		break;
	case blue:
		m_rect.setOutlineColor(sf::Color::Blue);
		break;
	case green:
		m_rect.setOutlineColor(sf::Color::Green);
		break;
	default:
		break;
	}

	window.draw(m_rect);
}


AnimattionWord::~AnimattionWord()
{
}
