#include "Header.h"



Header::Header(set<String> incolumnNames)
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

set<String> Header::getcolnames()
{
	return columnNames;
}

void Header::removeAllOtherColumnsBut(set<int> columnsToKeep)
{
	int currentcol = 0;
	for (auto i = columnNames.begin(); i != columnNames.end(); i++)
	{
		for (auto j : columnsToKeep)
		{
			if (currentcol == j)
				break;
			else
			{
				columnNames.erase(i);
				currentcol++;
			}
		}
	}
}

void Header::rename(int column, String newName)
{
	int colnum = 0;
	for (auto i : columnNames)
	{
		if (colnum = column)
			i = newName;
		colnum++;
	}
}