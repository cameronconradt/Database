#pragma once
#include "Parameter.h"
#include <string>
class Id :
	public Parameter
{
public:
	Id(Token* token);
	~Id();
	string tostring();
protected:
	Token* mytoken;
};