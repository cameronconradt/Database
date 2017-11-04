#pragma once
#include "Token.h"

class Parameter
{
public:
	Parameter();
	~Parameter();
	virtual string tostring()= 0;
	virtual string type() = 0;
};

