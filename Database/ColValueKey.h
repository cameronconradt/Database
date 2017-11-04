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
	inline bool operator > (const ColValueKey rh)
	{
		if (this->col < rh.col)
		{
			if (this->val < rh.val)
			{
				return true;
			}
			return false;
		}
		return false;
	}
protected:
	int col;
	String val;
};

