#pragma once
#include "String.h"
class ColumnNamePair
{
public:
	ColumnNamePair(int column, String inname);
	~ColumnNamePair();
	int getColumn();
	String getName();
	friend bool operator<(const ColumnNamePair lh , const ColumnNamePair rh)
	{
		if (lh.col < rh.col)
		{
			if(lh.name < rh.name)
				return true;
			return false;
		}
		return false;
	}
protected:
	int col;
	String name;
};

