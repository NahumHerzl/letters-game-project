#pragma once
#include<vector>
#include<array>
#include <memory>
#include <string>
#include <random>
#include <cstdlib>     /* srand, rand */
#include <ctime>       /* time */
#include <Windows.h>
#include "Letter.h"
#include "Consts.h"
#include "utilities.h"
#include "matrix.h"
#include <SFML/Graphics.hpp>
#include "Sounds.h"
#include "Exit.h"
#include "SoundTurn.h"
#include "Pause.h"
#include "Help.h"


using std::vector;
using std::array;


class GameTable
{
public:
	GameTable(const int &level);

	void draw(sf::RenderWindow &window);
	void move(direction dir, sf::RenderWindow & window);
	int getscore() const;
	int getwords() const;
	bool isFinishLevel() const;


	~GameTable();

private:
	int m_level;
	int m_tiles;
	int m_score = 0;
	int m_words = 0;
	bool m_finishLevel = false;
	float m_tilesize;

	matrix m_matrix;
	sf::RectangleShape m_mainBackground;
	sf::Texture m_mainBacTex;

	sf::Font m_myFont;
	sf::Text m_curentLevel;
	sf::Text m_points;
	sf::Text m_wordsFou;

	sf::RectangleShape m_noVoice;
	sf::Texture m_turnVoice;

	void makeInfo();
	void drawInfo(sf::RenderWindow& window);
	void makeMainBackground();
	void drawbuttons(sf::RenderWindow& window);
};

