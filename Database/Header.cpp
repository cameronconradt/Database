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
	int currentcol = 0;
	
	for(std::set<int>::reverse_iterator i = columnsToKeep.rbegin(); i != columnsToKeep.rend(); i++)
	{
		for(int j = 0; j < columnNames.size()-1; j++)
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