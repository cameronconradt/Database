#pragma once
#include "SelectionKey.h"
class ColColKey :
	public SelectionKey
{
public:
	ColColKey(int column1, int column2);
	~ColColKey();
	bool type();
	int getcol1();
	int getcol2();
protected:
	int col1;
	int col2;
};

