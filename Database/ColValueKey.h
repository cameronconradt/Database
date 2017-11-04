#pragma once
#include "SelectionKey.h"
#include "String.h"
class ColValueKey :
	public SelectionKey
{
public:
	ColValueKey(int column, String value);
	~ColValueKey();
	bool type();
	int getcol();
	String getval();
protected:
	int col;
	String val;
};

