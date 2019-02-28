#pragma once
#include "Buttons.h"
class Exit :
	public Buttons
{
public:
	Exit();

	virtual void doActWhenPressed(sf::RenderWindow& window);
	virtual bool contains(sf::Vector2f loc);

	~Exit();

private:
	sf::RectangleShape m_end;
	sf::Texture m_endPage;
};

