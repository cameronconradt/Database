#pragma once
#include <string>
#include <sstream>
#include <iostream>

using namespace std;

class Token
{
public:
	Token(string intype, string intext, int inputline);
	~Token();
	string gettype();
	string gettext();
	string getline();
	friend bool operator<(const Token lh, const Token rh)
	{
		if (lh.text < rh.text)
		{
			return true;
		}
		return false;
	}
	friend bool operator==(const Token lh, const Token rh)
	{
		if (lh.text == rh.text)
			return true;
		else
			return false;
	}
protected:
	string type;
	string text;
	int line;
};