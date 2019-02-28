#pragma once
#include <SFML/Graphics.hpp>
#include <memory>
#include "Consts.h"


class Letter
{
public:
	Letter(char letter, std::pair<int, int> Location, const int size);

	~Letter();
	char getChar() const;
	void draw(sf::RenderWindow & window);
	///////////////////////////////////////
	std::pair<int, int> getLocation() const;
	//////////////////////////////////////////

	void move(std::pair<int, int> newLoc);

	//void setColor(const sf::Color & color);
	bool m_removeMe = false;

private:
	char m_letter;

	sf::Texture m_form;

	sf::RectangleShape m_rect;
	std::pair<int, int> m_Location;

	void editText();

};
