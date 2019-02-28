#include "LevelController.h"



LevelController::LevelController(const int &level)
	: m_tiles((float)((level + 2) * 3)), m_gt(level)
{
}

int LevelController::manage(sf::RenderWindow &window)
{
	makeAllButtons(window);
	if (window.isOpen())
	{
		m_gt.draw(window);
		Sounds temp2(std::string{ "newLevel" });
		Sleep(2000);
	}

	while (window.isOpen() && !m_gt.isFinishLevel())
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			switch (event.type)
			{
			case sf::Event::Closed:
				window.close();
				exit(0);
				break;
			case sf::Event::KeyPressed:
				switch (event.key.code)
				{
				case sf::Keyboard::Left:
					m_gt.move(left, window);
					break;
				case sf::Keyboard::Right:
					m_gt.move(right, window);
					break;
				case sf::Keyboard::Up:
					m_gt.move(up, window);
					break;
				case sf::Keyboard::Down:
					m_gt.move(down, window);
					break;
				default:
					break;
				};
				break;
			case sf::Event::MouseButtonPressed:
			{
				sf::Vector2f mouseCoords = { (float)event.mouseButton.x, (float)event.mouseButton.y };
				HandleButtons(mouseCoords, window);
				m_gt.draw(window);
			};
			break;
			default:
				break;
			}
		}

		m_gt.draw(window);
	}
	Sounds s(std::string{ "tada" });
	Sleep(1000);
	return(m_gt.getscore());
}

int LevelController::getWords() const
{
	return m_gt.getwords();
}

void LevelController::HandleButtons(sf::Vector2f &ind, sf::RenderWindow & window)
{
	for (auto &i : m_allButtons)
		if (i->contains(ind))
		{
			Sounds temp(std::string{ "press" });
			Sleep(200);
			i->doActWhenPressed(window);
		}
}

void LevelController::makeAllButtons(sf::RenderWindow& window)
{
	m_allButtons[0] = std::make_unique<Exit>();
	m_allButtons[1] = std::make_unique<SoundTurn>();
	m_allButtons[2] = std::make_unique<Pause>();
	m_allButtons[3] = std::make_unique<Help>();

	if (!SoundTurn::isVoice() && m_tiles == 9)
		m_allButtons[1]->doActWhenPressed(window);
}


LevelController::~LevelController()
{
}
