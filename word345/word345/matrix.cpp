#include "matrix.h"
#include "Sounds.h"

matrix::matrix(const int &level)
	: m_level(level), m_lenghWord(m_level + 2), m_tiles(((level + 2) * 3)),
	m_col(m_tiles, deque<std::shared_ptr<Letter>>()), m_row(m_tiles, deque<std::shared_ptr<Letter>>()),
	m_used(m_tiles, vector<bool>(m_tiles)), m_countEmpty(m_tiles*m_tiles), m_dict(m_lenghWord)
{
	addLetters(m_tiles * 2);
}

void matrix::draw(sf::RenderWindow & window)
{
	for (auto &i : m_row)
	{
		for (auto &j : i)
		{
			j->draw(window);
		}
	}
}

void matrix::move(enum direction dir)
{
	switch (dir)
	{
	case (direction)0:
		moveUp();
		break;
	case (direction)1:
		moveDown();
		break;
	case (direction)2:
		moveRight();
		break;
	case (direction)3:
		moveLeft();
		break;
	default:
		break;
	}
}
void matrix::moveLeft()
{
	clearCols();

	for (auto &itRow : m_row)
	{
		int i = 0;
		for (auto &itCol : itRow)
		{
			m_used[itCol->getLocation().first][itCol->getLocation().second] = false;
			itCol->move({ itCol->getLocation().first, i });
			m_used[itCol->getLocation().first][itCol->getLocation().second] = true;
			setCol(itCol);
			i++;
		}
	}
}
//////////////////
void matrix::moveRight()
{
	clearCols();

	for (auto &itRow : m_row)
	{
		int i = m_tiles - 1;
		for (auto itCol = itRow.rbegin(); itCol != itRow.rend(); ++itCol)
		{
			m_used[(*itCol)->getLocation().first][(*itCol)->getLocation().second] = false;
			(*itCol)->move({ (*itCol)->getLocation().first, i });
			m_used[(*itCol)->getLocation().first][(*itCol)->getLocation().second] = true;
			setCol((*itCol));
			i--;
		}
	}
}
/////////////////////
void matrix::moveUp()
{
	clearRows();

	for (auto &itCol : m_col)
	{
		int i = 0;
		for (auto &itRow : itCol)
		{
			m_used[itRow->getLocation().first][itRow->getLocation().second] = false;
			itRow->move({ i, itRow->getLocation().second });
			m_used[itRow->getLocation().first][itRow->getLocation().second] = true;
			setRow(itRow);
			i++;
		}
	}
}
//////////////////
void matrix::moveDown()
{
	clearRows();

	for (auto &itCol : m_col)
	{
		int i = m_tiles;
		for (auto itRow = itCol.rbegin(); itRow != itCol.rend(); itRow++)
		{
			m_used[(*itRow)->getLocation().first][(*itRow)->getLocation().second] = false;
			(*itRow)->move({ --i, (*itRow)->getLocation().second });
			m_used[(*itRow)->getLocation().first][(*itRow)->getLocation().second] = true;
			setRow((*itRow));
		}
	}
}

void matrix::clearRows()
{
	for (auto &i : m_row)
		i.clear();
}

void matrix::clearCols()
{
	for (auto &i : m_col)
		i.clear();
}


int getNext(std::shared_ptr<Letter> &let, bool which)
{
	return (which ? let->getLocation().second : let->getLocation().first);
}

int matrix::signWords(const bool which)
{
	int countRemove = 0;

	for (auto &v : which ? m_row : m_col)
	{
		if (v.empty() || v.size() < m_lenghWord) continue;

		for (int i = 0; i < (int)(v.size() - (m_lenghWord - 1)); i++)
		{
			std::string word;
			int j = i;
			for (j; j < i + m_lenghWord - 1; j++)
			{
				if (getNext(v[j + 1], which) > getNext(v[j], which) + 1)
					break;
				word.push_back(v[j]->getChar());
			}
			if (word.size() < (size_t)m_lenghWord - 1)
				continue;

			word.push_back(v[j]->getChar());

			if (m_dict.checkWord(word))
			{
				sf::Vector2f aniPos{ (float)230 + (v[i]->getLocation().second * (gameBoard / m_tiles)),
					(float)10 + (v[i]->getLocation().first * (gameBoard / m_tiles)) };
				AnimattionWord ac(aniPos, gameBoard / m_tiles, m_lenghWord, which);
				m_allAnimations.push_back(ac);

				for (int k = 0; k < m_lenghWord; k++)
				{
					if (!v[i + k]->m_removeMe)
					{
						v[i + k]->m_removeMe = true;
						m_used[v[i + k]->getLocation().first][v[i + k]->getLocation().second] = false;
						m_countEmpty++;
						countRemove++;
					}
				}
			}
		}
	}
	return countRemove;
}

int matrix::findWord()
{
	return signWords(0) + signWords(1);
}

int matrix::animationFoundWord(sf::RenderWindow & window)
{
	int i = 0;
	for (auto a : m_allAnimations)
	{
		a.drow(window, (animationColor)(i % 5));
		i++;
	}
	window.display();
	m_allAnimations.clear();

	return i;
}

void matrix::removeWords()
{
	for (auto &row : m_row)
	{
		for (int i = 0; i < row.size(); i++)
		{
			if (row[i]->m_removeMe)
			{
				row.erase(row.begin() + i);
				i--;
			}
		}
	}

	for (auto &col : m_col)
	{
		for (int i = 0; i < col.size(); i++)
		{
			if (col[i]->m_removeMe)
			{
				col.erase(col.begin() + i);
				i--;
			}
		}
	}
}

bool matrix::addLetters(int num)
{
	int row, col;
	std::pair<int, int> Ptemp;
	char randomLetter;
	for (int i = 0; i < num; i++)
	{
		std::srand((unsigned)std::time(0));
		do {
			if (m_countEmpty == 0) return true;

			row = std::rand() % m_tiles;
			col = std::rand() % m_tiles;
		} while (m_used[row][col]);
		m_used[row][col] = true;
		m_countEmpty--;
		randomLetter = m_listOfLetters[std::rand() % m_listOfLetters.size()];
		Ptemp = std::make_pair(row, col);
		std::shared_ptr<Letter> tempLetter = std::make_shared<Letter>(randomLetter, Ptemp, gameBoard / m_tiles);
		setRow(tempLetter);
		setCol(tempLetter);

		if (m_countEmpty == 0) return true;
	}
	return false;
}

void matrix::setRow(std::shared_ptr<Letter> &let)
{
	auto &myList = m_row[let->getLocation().first];

	if (!myList.empty())
	{
		auto it = myList.begin();
		for (it; it != myList.end(); ++it)
		{
			if ((*it)->getLocation().second >= let->getLocation().second)
			{
				myList.insert(it, let);
				return;
			}
		}
	}
	myList.push_back(let);
}

void matrix::setCol(std::shared_ptr<Letter> &let)
{
	auto &myList = m_col[let->getLocation().second];

	if (!myList.empty())
	{
		auto it = myList.begin();
		for (it; it != myList.end(); ++it)
		{
			if ((*it)->getLocation().first >= let->getLocation().first)
			{
				myList.insert(it, let);
				return;
			}
		}
	}
	myList.push_back(let);
}

bool matrix::isUsed(const std::pair<int, int> location)
{
	return m_used[location.first][location.second];
}

matrix::~matrix()
{
}





