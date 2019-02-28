#include "Exit.h"
#include <Windows.h>


Exit::Exit() :
	Buttons::Buttons({ 880,15 })
{
	m_end.setPosition({ 0,0 });
	m_end.setSize({ 1040, 660 });
	m_endPage.loadFromFile("mainBK.png");
	m_end.setTexture(&m_endPage);
}


void Exit::doActWhenPressed(sf::RenderWindow& window)
{
	window.clear();
	window.draw(m_end);
	window.display();
	Sleep(2000);
	window.close();
	exit(0);
}

bool Exit::contains(sf::Vector2f loc)
{
	return (Buttons::contains(loc));
}


Exit::~Exit()
{
}
