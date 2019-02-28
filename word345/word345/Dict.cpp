#include "Dict.h"



Dict::Dict()
{

}

Dict::Dict(int lengh)
	:m_lengh(lengh)
{
	std::ifstream infile;
	switch (m_lengh)
	{
	case 3:
		infile = std::ifstream{ "3charLen.txt" };
		break;
	case 4:
		infile = std::ifstream{ "4charLen.txt" };
		break;
	case 5:
		infile = std::ifstream{ "5charLen.txt" };
		break;
	default:
		break;
	}

	std::string line;
	std::string temp;
	while (std::getline(infile, temp))
	{
		std::istringstream ss(temp);
		if (temp.size() != m_lengh)
			continue;
		ss >> line;
		m_dict.insert(temp);
	}
}

void Dict::print() const
{
	for (auto it = m_dict.begin(); it != m_dict.end(); ++it)
	{
		std::cout << *it << std::endl;
	}
}

bool Dict::checkWord(const string & word) const
{
	if (word.size() != m_lengh)
		return false;

	std::set<string>::iterator it;
	it = m_dict.find(word);
	return(it != m_dict.end());
}


Dict::~Dict()
{

}
