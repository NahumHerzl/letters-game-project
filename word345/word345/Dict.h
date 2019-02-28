#pragma once
#include<set>
#include<string>
#include <iostream>
#include<fstream>
#include <sstream>
#include <vector>
#include <memory>

using std::set;
using std::string;

class Dict
{
public:
	Dict();
	Dict(int lengh = 3);
	void print() const;
	bool checkWord(const string & word)const;
	~Dict();

private:

	set<string> m_dict;
	int m_lengh;
};


