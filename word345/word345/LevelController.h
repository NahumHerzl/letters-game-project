#pragma once

#include "GameTable.h"

class LevelController
{
public:
	LevelController(const int &level);

	int manage(sf::RenderWindow &window);
	int getWords() const;

	~LevelController();


private:
	float m_tiles;

	GameTable m_gt;

	std::array<std::unique_ptr<Buttons>, 4> m_allButtons;

	void makeAllButtons(sf::RenderWindow& window);
	void HandleButtons(sf::Vector2f &ind, sf::RenderWindow & window);

};

