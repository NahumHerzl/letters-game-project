#include "Letter.h"

Letter::Letter(char letter, std::pair<int, int> Location, const int size)
	:m_letter(letter), m_Location(Location), m_rect({ (float)size, (float)size })
{
	editText();
	m_rect.setPosition({ (float)(230 + m_Location.second * size), (float)(10 + m_Location.first * size) });
	m_rect.setTexture(&m_form);
}

char Letter::getChar() const
{
	return m_letter;
}

void Letter::draw(sf::RenderWindow & window)
{
	window.draw(m_rect);
}

//////////////////////////////////////
std::pair<int, int> Letter::getLocation() const
{
	return m_Location;
}
//////////////////////////////////////

void Letter::editText()
{
	switch (m_letter)
	{
	case 'a':
		m_form.loadFromFile("lettersTextures\\A.jpg");
		break;
	case 'b':
		m_form.loadFromFile("lettersTextures\\B.jpg");
		break;
	case 'c':
		m_form.loadFromFile("lettersTextures\\C.jpg");
		break;
	case 'd':
		m_form.loadFromFile("lettersTextures\\D.jpg");
		break;
	case 'e':
		m_form.loadFromFile("lettersTextures\\E.jpg");
		break;
	case 'f':
		m_form.loadFromFile("lettersTextures\\F.jpg");
		break;
	case 'g':
		m_form.loadFromFile("lettersTextures\\G.jpg");
		break;
	case 'h':
		m_form.loadFromFile("lettersTextures\\H.jpg");
		break;
	case 'i':
		m_form.loadFromFile("lettersTextures\\I.jpg");
		break;
	case 'j':
		m_form.loadFromFile("lettersTextures\\J.jpg");
		break;
	case 'k':
		m_form.loadFromFile("lettersTextures\\K.jpg");
		break;
	case 'l':
		m_form.loadFromFile("lettersTextures\\L.jpg");
		break;
	case 'm':
		m_form.loadFromFile("lettersTextures\\M.jpg");
		break;
	case 'n':
		m_form.loadFromFile("lettersTextures\\N.jpg");
		break;
	case 'o':
		m_form.loadFromFile("lettersTextures\\O.jpg");
		break;
	case 'p':
		m_form.loadFromFile("lettersTextures\\P.jpg");
		break;
	case 'q':
		m_form.loadFromFile("lettersTextures\\Q.jpg");
		break;
	case 'r':
		m_form.loadFromFile("lettersTextures\\R.jpg");
		break;
	case 's':
		m_form.loadFromFile("lettersTextures\\S.jpg");
		break;
	case 't':
		m_form.loadFromFile("lettersTextures\\T.jpg");
		break;
	case 'u':
		m_form.loadFromFile("lettersTextures\\U.jpg");
		break;
	case 'v':
		m_form.loadFromFile("lettersTextures\\V.jpg");
		break;
	case 'w':
		m_form.loadFromFile("lettersTextures\\W.jpg");
		break;
	case 'x':
		m_form.loadFromFile("lettersTextures\\X.jpg");
		break;
	case 'y':
		m_form.loadFromFile("lettersTextures\\Y.jpg");
		break;
	case 'z':
		m_form.loadFromFile("lettersTextures\\Z.jpg");
		break;
	default:
		break;
	}
}

void Letter::move(std::pair<int, int> newLoc)
{
	m_Location = newLoc;
	m_rect.setPosition((230 + m_Location.second * m_rect.getSize().x), (10 + m_Location.first * m_rect.getSize().x));
}

Letter::~Letter()
{
}
