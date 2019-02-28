#include "Pause.h"

Pause::Pause() :
	Buttons::Buttons({ 880,335 })
{
	m_pausePageRect.setSize({ 600,600 });
	m_pausePageRect.setPosition({ 220,30 });
	m_pausePageTex.loadFromFile("startT.PNG");
	m_pausePageRect.setOutlineThickness(-10);
	m_pausePageRect.setOutlineColor(sf::Color::Red);
	m_pausePageRect.setTexture(&m_pausePageTex);
}

void Pause::doActWhenPressed(sf::RenderWindow & window)
{
	window.draw(m_pausePageRect);
	window.display();

	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			switch (event.type)
			{
			case sf::Event::Closed:
				window.close();
				break;
			case sf::Event::MouseButtonPressed:
				return;
			case sf::Event::KeyPressed:
				switch (event.key.code)
				{
				case sf::Keyboard::Return:
					return;
				case sf::Keyboard::Space:
					return;
				default:
					break;
				}
			default:
				break;
			}
		}
	}
}

bool Pause::contains(sf::Vector2f loc)
{
	return (Buttons::contains(loc));
}

Pause::~Pause()
{
}
