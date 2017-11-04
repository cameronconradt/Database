#pragma once
#include "String.h"
#include "ColColKey.h"
#include "ColValueKey.h"
#include <set>
#include <vector>
class Row
{
public:
	Row(vector<String> invalues);
	Row(Row* inrow);
	~Row();
	bool satisfies(ColColKey* colColKey);
	bool satisfies(ColValueKey* colValueKey);
	void removeAllOtherColumnsBut(set<int> columnsToKeep);
	vector<String> getvalues();
	inline bool operator < (const Row rh)
	{
		for (int i = 0; i < this->values.size() || i < rh.values.size(); i++)
		{
			if (!(this->values[i] < rh.values[i]))
				return false;
		}
		return true;
		/*
		if (this->values[0] < rh.values[0])
		{
			if(this->values[1] < rh.values[1])
				return true;
			return false;
		}
		return false;*/
	}
protected:
	vector<String> values;
};

