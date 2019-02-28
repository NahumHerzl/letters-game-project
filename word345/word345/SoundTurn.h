#pragma once
#include "Buttons.h"
class SoundTurn :
	public Buttons
{
public:
	SoundTurn();

	virtual void doActWhenPressed(sf::RenderWindow& window);
	virtual bool contains(sf::Vector2f loc);

	static bool isVoice();
	~SoundTurn();

private:
	static bool m_turnd;

};

