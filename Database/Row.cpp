#include "Row.h"



Row::Row(vector<String> invalues)
{
	values = invalues;
}

Row::Row(Row* inrow)
{
	values = inrow->getvalues();
}

Row::~Row()
{
}

bool Row::satisfies(ColColKey* colColKey)
{
	if (values[colColKey->getcol1()].tostring() == values[colColKey->getcol2()].tostring())
		return true;
	else
		return false;
}

bool Row::satisfies(ColValueKey* colValueKey)
{
	if (values[colValueKey->getcol()].tostring() == colValueKey->getval().tostring())
		return true;
	else
		return false;
}

void Row::removeAllOtherColumnsBut(set<int> columnsToKeep)
{
	vector<String> tempkept;
	for (auto i : columnsToKeep)
	{
		tempkept.push_back(values[i]);
	}
	for (int i = 0; values.size() != tempkept.size(); i++)
	{
		if (i < tempkept.size())
			values[i] = tempkept[i];
		else
			values.pop_back();
	}
	/*for (std::set<int>::reverse_iterator i = columnsToKeep.rbegin(); i != columnsToKeep.rend(); i++)
	{
		for (int j = 0; j < values.size() - 1; j++)
		{
			if (j + 1 == *i)
			{
				values.erase(values.begin() + j);
			}
		}
	}
	*/
	/*int currentcol = 0;
	for (int i = 0; i < values.size(); i++)
	{
		for (auto j : columnsToKeep)
		{
			if (currentcol == j)
				break;
			else
			{
				values.erase(i);
				currentcol++;
			}
		}
	}*/
}

vector<String> Row::getvalues() const
{
	return values;
}

bool Row::matches(Row otherRow, set<ColColKey> columnsToMerge)
{
	bool result = true;
	for (auto i : columnsToMerge)
	{
		if (!(values[i.getcol1()] == otherRow.values[i.getcol2()]))
			result = false;
	}
	return result;

	/*	bool result = true
	int i = 0
	while(i < colColPairs.length() && result) {
		result = values[colColPairs[0]] == 
			   	otherRow.values[colColPairs[1]]
		i++
	}
	return result
*/
}

Row* Row::mergeWith(Row* inrow, vector<int> columnsToMerge)
{
	Row* result = new Row(this);
	for (auto i : columnsToMerge)
	{
		result->values.push_back(inrow->values[i]);
	}
	return result;
	/*	Row result = new Row(this)
	for(int i in columnsToMerge)
		result.values.append(
			otherRow.values[columnsToMerge[i]];
	return result;
*/
}

Row* Row::rearrange(vector<int> order)
{
	vector<String> newvalues;
	for (int i = 0; i < order.size(); i++)
	{
		if(order[i] != -1)
			newvalues.push_back(values[order[i]]);
	}
	Row* result = new Row(newvalues);
	return result;
}