#include "Sounds.h"


Sounds::Sounds(std::string &file)
{
	setSound(file);
	m_audio.setBuffer(m_sound);
	m_audio.setVolume(50);
	play();
}

Sounds::~Sounds()
{
}

void Sounds::play()
{
	if (SoundTurn::isVoice())
		m_audio.play();
}

void Sounds::setSound(std::string & file)
{
	std::string end{ ".wav" };
	m_path = file + end;

	m_sound.loadFromFile(m_path);
}

