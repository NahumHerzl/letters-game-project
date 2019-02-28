#include "Help.h"



Help::Help() :
	Buttons::Buttons({ 880,495 })
{
	m_helpPageRect.setSize({ 980,600 });
	m_helpPageRect.setPosition({ 30,30 });
	m_helpPageTex.loadFromFile("helpPage.PNG");
	m_helpPageRect.setTexture(&m_helpPageTex);
}

void Help::doActWhenPressed(sf::RenderWindow & window)
{
	window.draw(m_helpPageRect);
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

Help::~Help()
{
}
