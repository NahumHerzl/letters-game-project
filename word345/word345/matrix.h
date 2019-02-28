#pragma once
#include <string>
#include <vector>
#include <iostream>
#include <memory>
#include <iterator>
#include <array>
#include <deque>
#include <algorithm>

#include "Letter.h"
#include "Consts.h"
#include "AnimattionWord.h"
#include "Dict.h"
#include "utilities.h"


using std::vector;
using std::deque;


class matrix
{
public:
	matrix(const int &level);

	void draw(sf::RenderWindow & window);

	void move(enum direction dir);

	bool addLetters(int num);

	int findWord();
	int animationFoundWord(sf::RenderWindow &window);
	void removeWords();

	~matrix();


private:
	int m_tiles;
	int m_level;
	int m_lenghWord;
	int m_countEmpty;

	Dict m_dict;

	vector<deque<std::shared_ptr<Letter>>> m_row;
	vector<deque<std::shared_ptr<Letter>>> m_col;
	vector<vector<bool>> m_used;

	vector<AnimattionWord> m_allAnimations;

	void setRow(std::shared_ptr<Letter> &let);
	void setCol(std::shared_ptr<Letter> &let);
	bool isUsed(const std::pair<int, int> location);
	//////////////////////////////
	void moveLeft();
	void moveRight();
	void moveUp();
	void moveDown();
	void clearRows();
	void clearCols();
	int signWords(const bool which);
	//////////////////////////////

	std::array<char, 249> m_listOfLetters{
		'a' , 'a' , 'a' , 'a' , 'a' , 'a' , 'a' , 'a' , 'a' , 'a' , 'a' , 'a' , 'a' , 'a' , 'a' ,
		'a' , 'a' , 'a' , 'a' , 'a' , 'a' , 'a' , 'a' , 'a' , 'a' , 'a' ,
		'b' , 'b' , 'b' , 'b' , 'b' , 'b' ,
		'c' , 'c' , 'c' , 'c' , 'c' , 'c' , 'c' , 'c' ,	'c' ,
		'd' , 'd' , 'd' , 'd' , 'd' , 'd' ,	'd' , 'd' , 'd' ,
		'e' , 'e' , 'e' , 'e' , 'e' , 'e' , 'e' , 'e' , 'e' , 'e' , 'e' , 'e' ,	'e' , 'e' , 'e' ,
		'e' , 'e' , 'e' , 'e' , 'e' , 'e' , 'e' , 'e' , 'e' , 'e' , 'e' ,
		'f' , 'f' , 'f' , 'f' ,
		'g' , 'g' , 'g' , 'g' , 'g' , 'g' ,
		'h' , 'h' , 'h' , 'h' , 'h' , 'h' , 'h' ,
		'i' , 'i' , 'i' , 'i' , 'i' , 'i' , 'i' , 'i' , 'i' , 'i' ,	'i' , 'i' , 'i' , 'i' ,	'i' ,
		'i' ,
		'j' ,
		'k' , 'k' , 'k' , 'k' ,
		'l' , 'l' , 'l' , 'l' , 'l' , 'l' , 'l' , 'l' , 'l' , 'l' ,	'l' , 'l' , 'l' , 'l' ,
		'm' , 'm' , 'm' , 'm' , 'm' , 'm' , 'm' , 'm' ,
		'n' , 'n' , 'n' , 'n' , 'n' , 'n' , 'n' , 'n' , 'n' , 'n' , 'n' , 'n' , 'n' ,
		'o' , 'o' , 'o' , 'o' , 'o' , 'o' , 'o' , 'o' , 'o' , 'o' , 'o' , 'o' , 'o' , 'o' , 'o' ,
		'o' ,	'o' ,
		'p' , 'p' , 'p' , 'p' , 'p' , 'p' , 'p' ,
		'q' ,
		'r' , 'r' , 'r' , 'r' , 'r' , 'r' , 'r' , 'r' , 'r' , 'r' , 'r' , 'r' , 'r' , 'r' , 'r' ,
		'r' , 'r' , 'r' ,
		's' , 's' , 's' , 's' , 's' , 's' , 's' , 's' , 's' , 's' , 's' , 's' ,	's' , 's' , 's' ,
		's' , 's' , 's' ,
		't' , 't' , 't' , 't' , 't' , 't' , 't' , 't' , 't' , 't' , 't' , 't' , 't' , 't' ,
		'u' , 'u' , 'u' , 'u' ,	'u' , 'u' , 'u' , 'u' , 'u' , 'u' , 'u' ,
		'v' , 'v' , 'v' ,
		'w' , 'w' , 'w' ,
		'x' ,
		'y' , 'y' , 'y' , 'y' , 'y' , 'y' ,
		'z' ,
	};
};

