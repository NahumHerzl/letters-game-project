#pragma once
#include <string>
#include "SoundTurn.h"
#include "SFML/Audio.hpp"
#include "SFML/Graphics.hpp"


class Sounds
{
public:
	Sounds(std::string &file);
	~Sounds();

private:

	void play();

	void setSound(std::string &file);

	sf::SoundBuffer m_sound;

	sf::Sound m_audio;

	std::string m_path;

};


