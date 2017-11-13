#pragma once
#include "Parameter.h"
#include <string>
class String :
	public Parameter
{
public:
	String(Token* token);
	String();
	~String();
	string tostring();
	string type();
	friend bool operator<(const String lhs, const String rhs) { 
		if (*lhs.mytoken < *rhs.mytoken)
			return true;
		else
			return false;
	}
	friend bool operator==(const String lhs, const String rhs)
	{
		if (*lhs.mytoken == *rhs.mytoken)
			return true;
		else
			return false;
	}
protected:
	Token* mytoken;
};

