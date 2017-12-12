#include "Header.h"



Header::Header(vector<String> incolumnNames)
{
	columnNames = incolumnNames;
}

Header::Header(Header* inheader)
{
	columnNames = inheader->getcolnames();
}

Header::Header()
{

}

Header::~Header()
{
}

vector<String> Header::getcolnames()
{
	return columnNames;
}

void Header::removeAllOtherColumnsBut(set<int> columnsToKeep)
{
	int currentcol = columnNames.size();
	for(std::set<int>::reverse_iterator i = columnsToKeep.rbegin(); i != columnsToKeep.rend(); i++)
	{
		for(int j = currentcol; j >= 0; j--, currentcol--)
		{
			if(j+1==*i)
			{
				columnNames.erase(columnNames.begin()+j);
			}
		}
	}
	/*for (auto i = columnNames.begin(); (i != columnNames.end()) && currentcol < columnNames.size(); i++)
	{
		for (auto j : columnsToKeep)
		{
			if (currentcol == j)
				break;
			else
			{
				cout << "colerased" << currentcol << endl;
				columnNames.erase(i);
				currentcol++;
			}
		}
	}*/
}

void Header::rename(int column, String newName)
{
	columnNames[column] = newName;
}

vector<int> Header::getColumnsToMerge(Header inheader)
{
	vector<int> result;
	for (int i = 0; i < inheader.columnNames.size(); i++)
	{
		String attribute = inheader.getcolnames()[i];
		bool found = false;
		for (int j = 0; j < columnNames.size(); j++)
		{
			if (columnNames[j] == attribute)
				found = true;
		}
		if (!found)
			result.push_back(i);
	}
	return result;

	/*vector<int> getColumnsToMerge(Header otherHeader)
	vector<int> result = new vector<int>()
	for(i = 0; i < otherHeader.values.length(); i++)
		String attribute = otherHeader[i]
		if(!values.contains(attribute)) {
			result.append(i);
		}
	return result
*/
}

Header* Header::mergeWith(Header inheader, vector<int> columnsToMerge)
{
	Header* result = new Header(this);
	for (int i = 0; i < columnsToMerge.size(); i++)
	{
		result->columnNames.push_back(inheader.columnNames[columnsToMerge[i]]);
	}
	return result;
	/*
	Header result = new Header(this);
	for(int column in columnsToMerge)
		result.values.append(otherHeader.values[column])
	return result
*/
}

set<ColColKey> Header::getColumnMappings(Header inheader)
{
	set<ColColKey> result;
	for (int i = 0; i < columnNames.size(); i++)
	{
		int loc = inheader.getLocOf(columnNames[i]);
		if (loc >= 0)
		{
			result.insert(ColColKey(i, loc));
		}
	}

	return result;
	/*	vector<ColColPair> result = new vector<ColColPair>()
	for(i = 0; i < values.length; i++)
		int loc = otherHeader.getLocationOf(values[i])
		//The result can be -1 if values[i] does not appear
		//in the otherHeader’s values
		if(loc >= 0)
			result.append(new ColColPair(i, loc))
	return result
*/
}

int Header::getLocOf(String value)
{
	int result = -1;
	for (int i = 0; i < columnNames.size(); i++)
	{
		if (value == columnNames[i])
			result = i;
	}
	return result;
}

vector<int> Header::createMap(Header inheader)
{
	vector<int> result;
	for (int i = 0; i < columnNames.size(); i++)
	{
		int loc = inheader.getLocOf(columnNames[i]);
		result.push_back(loc);
	}
	return result;
}