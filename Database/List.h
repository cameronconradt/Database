#pragma once
#include <string>
#include <iostream>
#include "Token.h"
#include <vector>
using namespace std;



class List
{
public:
	List();
	~List();
	void additem(Token* input);
	string tostring();
protected:
	vector<Token*> mytokens;
};

