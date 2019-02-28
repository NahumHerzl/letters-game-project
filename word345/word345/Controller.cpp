#include "Controller.h"



Controller::Controller()
{
}

void Controller::manageGame()
{
	sf::RenderWindow window(sf::VideoMode(windowWidth, windowHigh), "345WORD", 5);

	makeStartPage();
	makeFinishlevel();

	window.clear();
	window.draw(m_startPage);
	window.display();

	Sleep(2000);

	int level;

	for (level = 1; levels + 1; level++)
	{
		LevelController lc(level);
		m_score += lc.manage(window);
		m_words += lc.getWords();


		if (level < levels)
			drawFinishlevel(window);
		else
		{
			window.clear();
			makeFinishShow();
			drawFinishShow(window);
			window.display();
			Sounds s(std::string{ "finnish" });
			Sleep(2500);

			window.clear();
			window.draw(m_startPage);
			window.display();
			Sleep(1500);

			break;
		}

		window.display();

		bool next = false;
		sf::Event event;

		while (window.isOpen() && window.waitEvent(event) && next == false)
		{
			window.pollEvent(event);

			switch (event.type)
			{
			case sf::Event::Closed:
				window.close();
				exit(0);
				break;
			case sf::Event::MouseButtonPressed:
			{
				if (event.mouseButton.x > 290 && event.mouseButton.x < 750 &&
					event.mouseButton.y > 320 && event.mouseButton.y < 570)
				{
					next = true;
				}
				break;
			}
			default:
				break;
			}
		}
	}
}

Controller::~Controller()
{
}

void Controller::makeStartPage()
{
	m_startTex.loadFromFile("mainBK.png");
	m_startPage.setTexture(&m_startTex);
	m_startPage.setPosition({ 0,0 });
	m_startPage.setSize({ (float)windowWidth,(float)windowHigh });
}

void Controller::makeFinishlevel()
{
	m_levelStartPage.setSize({ 640,640 });
	m_levelStartPage.setPosition({ 230, 10 });
	m_levelStartTex.loadFromFile("nextLevel.png");
	m_levelStartPage.setTexture(&m_levelStartTex);

	m_fontS.loadFromFile("kirbyss.ttf");
	m_allWords.setFont(m_fontS);
	m_allScore.setFont(m_fontS);

	m_allWords.setPosition({ 380,145 });
	m_allScore.setPosition({ 630,145 });

	m_allWords.setCharacterSize(52);
	m_allScore.setCharacterSize(52);

	m_allWords.setFillColor(sf::Color::Red);
	m_allScore.setFillColor(sf::Color::Red);
}

void Controller::makeFinishShow()
{
	m_finnishPage.setSize({ 1040,660 });
	m_finnishPage.setPosition({ 0, 0 });
	m_finnishTex.loadFromFile("finnishShow.PNG");
	m_finnishPage.setTexture(&m_finnishTex);

	m_allWords.setPosition({ 260,560 });
	m_allScore.setPosition({ 680,560 });
}

void Controller::drawFinishlevel(sf::RenderWindow& window)
{
	m_allWords.setString(std::to_string(m_words));
	m_allScore.setString(std::to_string(m_score));

	window.draw(m_levelStartPage);
	window.draw(m_allWords);
	window.draw(m_allScore);
}

void Controller::drawFinishShow(sf::RenderWindow & window)
{
	m_allWords.setString(std::to_string(m_words));
	m_allScore.setString(std::to_string(m_score));

	window.draw(m_finnishPage);
	window.draw(m_allWords);
	window.draw(m_allScore);
}
