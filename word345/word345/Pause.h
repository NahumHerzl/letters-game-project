#pragma once
#include "Buttons.h"
class Pause :
	public Buttons
{
public:
	Pause();

	virtual void doActWhenPressed(sf::RenderWindow& window);
	virtual bool contains(sf::Vector2f loc);

	~Pause();
private:
	sf::RectangleShape m_pausePageRect;
	sf::Texture m_pausePageTex;
};



