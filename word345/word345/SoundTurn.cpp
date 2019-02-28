#include "SoundTurn.h"



SoundTurn::SoundTurn() :
	Buttons::Buttons({ 880,175 })
{
}

void SoundTurn::doActWhenPressed(sf::RenderWindow& window)
{
	if (m_turnd == true)
	{
		m_turnd = false;
	}
	else
	{
		m_turnd = true;
	}
}

bool SoundTurn::contains(sf::Vector2f loc)
{
	return (Buttons::contains(loc));
}

bool SoundTurn::isVoice()
{
	return m_turnd;
}

SoundTurn::~SoundTurn()
{
}


bool SoundTurn::m_turnd;