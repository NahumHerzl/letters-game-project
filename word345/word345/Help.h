#pragma once
#include "Buttons.h"
class Help :
	public Buttons
{
public:
	Help();

	virtual void doActWhenPressed(sf::RenderWindow& window);

	~Help();

private:
	sf::RectangleShape m_helpPageRect;
	sf::Texture m_helpPageTex;
};

