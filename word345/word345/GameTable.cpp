#include "GameTable.h"



GameTable::GameTable(const int &level)
	: m_level(level), m_tiles(((level + 2) * 3)), m_matrix(level), m_tilesize((float)gameBoard / m_tiles)//, m_SlabBoard(m_tiles, vector<sf::RectangleShape>(m_tiles))
{
	makeInfo();
	makeMainBackground();

	m_turnVoice.loadFromFile("soundOnT.PNG");

	m_noVoice.setSize({ 150,150 });
	m_noVoice.setPosition({ 880,175 });
	m_noVoice.setTexture(&m_turnVoice);
}

void GameTable::draw(sf::RenderWindow & window)
{
	window.clear();
	window.draw(m_mainBackground);
	drawbuttons(window);
	m_matrix.draw(window);
	drawInfo(window);
	window.display();
}

void GameTable::move(direction dir, sf::RenderWindow & window)
{
	m_matrix.move(dir);
	draw(window);
	Sounds temp1(std::string{ "move" });
	Sleep(200);

	int numToAdd = int(m_matrix.findWord()*1.2);
	draw(window);
	m_words += m_matrix.animationFoundWord(window);
	m_score = m_words*(m_level + 2);

	if (numToAdd > 0)
	{
		Sounds temp2(std::string{ "foundWord" });
		Sleep(1500);
	}

	m_matrix.removeWords();
	draw(window);
	Sleep(100);

	if (numToAdd == 0)
		numToAdd = m_tiles;

	if (m_matrix.addLetters(numToAdd))
		m_finishLevel = true;
	draw(window);


}

int GameTable::getscore() const
{
	return m_score;
}

int GameTable::getwords() const
{
	return m_words;
}

bool GameTable::isFinishLevel() const
{
	return m_finishLevel;
}


GameTable::~GameTable()
{
}

void GameTable::makeMainBackground()
{
	m_mainBacTex.loadFromFile("gameScreen1.png");
	m_mainBackground.setTexture(&m_mainBacTex);
	m_mainBackground.setPosition({ 0,0 });
	m_mainBackground.setSize({ (float)windowWidth,(float)windowHigh });
}

void GameTable::makeInfo()
{
	m_myFont.loadFromFile("kirbyss.ttf");
	m_curentLevel.setFont(m_myFont);
	m_points.setFont(m_myFont);
	m_wordsFou.setFont(m_myFont);

	m_curentLevel.setPosition({ 115,130 });
	m_points.setPosition({ 80,296 });
	m_wordsFou.setPosition({ 90,462 });

	m_curentLevel.setCharacterSize(42);
	m_points.setCharacterSize(42);
	m_wordsFou.setCharacterSize(42);

	m_points.setString('0');
	m_wordsFou.setString('0');

	m_curentLevel.setFillColor(sf::Color::Red);
	m_points.setFillColor(sf::Color::Red);
	m_wordsFou.setFillColor(sf::Color::Red);
}

void GameTable::drawInfo(sf::RenderWindow & window)
{
	std::string level = { char('0' + m_level) };
	m_curentLevel.setString(level);

	std::string points;
	if (m_score != 0)
	{
		int score = m_score;
		do {
			points = (char)('0' + int(score % 10)) + points;
			score = score / 10;
		} while (score != 0);
		m_points.setString(points);
	}
	std::string words;
	if (m_words != 0)
	{
		int wordsN = m_words;
		do {
			words = (char)('0' + int(wordsN % 10)) + words;
			wordsN = wordsN / 10;
		} while (wordsN != 0);
		m_wordsFou.setString(words);
	}

	window.draw(m_curentLevel);
	window.draw(m_points);
	window.draw(m_wordsFou);
}

void GameTable::drawbuttons(sf::RenderWindow & window)
{
	if (SoundTurn::isVoice()) return;

	window.draw(m_noVoice);
}
