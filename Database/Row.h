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
	bool matches(Row otherRow, set<ColColKey> columnsToMerge);
	vector<String> getvalues() const;
	Row* mergeWith(Row* inrow, vector<int> columnsToMerge);
	Row* rearrange(vector<int> order);
	friend bool operator<(const Row lh, const Row rh)
	{
		for (int i = 0; i < lh.values.size() && i < rh.values.size(); i++)
		{
			if (!(lh.values[i] == rh.values[i]))
			{
				if(lh.values[i] < rh.values[i])
					return true;
				else
					return false;
			}
		}
		return false;
		/*
		for (int i = 0; i < this->values.size() || i < rh.values.size(); i++)
		{
			if (!(this->values[i] < rh.values[i]))
			{
				cout << "returned false:" << this->values[i]
				return false;
			}
		}
		return true;*/
		/*cout << "row comparator" << endl;
		if (lh.values[0] < rh.values[0])
		{
			if(lh.values[1] < rh.values[1])
				return true;
			else
				return false;
		}
		cout << "row return false" << endl;
		return false;*/
	}
	friend bool operator==(const Row lh, const Row rh)
	{
		for (int i = 0; i < lh.values.size() || i < rh.values.size(); i++)
		{
			if (!(lh.values[i] == rh.values[i]))
			{
				return false;
			}
		}
		return true;
	}
protected:
	vector<String> values;
};

