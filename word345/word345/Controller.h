#pragma once
#include "Consts.h"
#include "LevelController.h"
#include <SFML/Graphics.hpp>


class Controller
{
public:
	Controller();

	void manageGame();

	~Controller();

private:

	void makeStartPage();
	void makeFinishlevel();
	void makeFinishShow();

	void drawFinishlevel(sf::RenderWindow& window);
	void drawFinishShow(sf::RenderWindow& window);


	int m_score = 0;
	int m_words = 0;

	sf::RectangleShape m_startPage;
	sf::Texture m_startTex;

	sf::RectangleShape m_levelStartPage;
	sf::Texture m_levelStartTex;

	sf::RectangleShape m_finnishPage;
	sf::Texture m_finnishTex;

	sf::Font m_fontS;
	sf::Text m_allWords;
	sf::Text m_allScore;
};

