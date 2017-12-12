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
	inline bool operator < (const ColColKey rh)
	{
		if (this->col1 < rh.col1)
		{
			if (this->col2 < rh.col2)
			{
				return true;
			}
			return false;
		}
		return false;
	}
	friend bool operator < (const ColColKey lh, const ColColKey rh)
	{
		if (lh.col1 < rh.col1)
		{
			return true;
		}
		else if (lh.col1 == rh.col1)
		{
			if (lh.col2 < rh.col2)
			{
				return true;
			}
			return false;
		}
		return false;
	}
protected:
	int col1;
	int col2;
};

