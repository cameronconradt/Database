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
	Token* gettoken();
	string type();
	inline bool operator == (const Id rh)
	{
		if (this->mytoken == rh.mytoken)
			return true;
		else
			return false;
	}
	inline bool operator < (const Id rh)
	{
		if (this->mytoken < rh.mytoken)
			return true;
		else
			return false;
	}
protected:
	Token* mytoken;
};