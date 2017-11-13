#pragma once
#include "Table.h"



Table::Table(String inname, Header inheader)
{
	name = inname;
	header = inheader;
}

Table::Table(Header inheader)
{
	header = inheader;
}

Table::Table(Table* intable)
{
	name = intable->getName();
	header = intable->getHeader();
	rows = intable->getRows();
}


Table::~Table()
{
	for (auto i : rows)
	{
		delete i;
	}
}

Table* Table::select(set<SelectionKey*> selectionKeys)
{
	Table* result = new Table(new Header(header));
	for (auto i : rows)
	{
		bool satisfied = true;
		for (auto j : selectionKeys)
		{
			/*Base *b = new Derived<int>(1);
			Derived<int> *d = dynamic_cast<Derived<int> *>(b);*/
			if (j->type())
			{
				ColValueKey* temp = dynamic_cast<ColValueKey*>(j);
				satisfied = i->satisfies(temp);
			}
			else
			{
				ColColKey* temp = dynamic_cast<ColColKey*>(j);
				satisfied = i->satisfies(temp);
			}
			if (!satisfied)
				break;
		}
		if (satisfied)
			result->rows.insert(i);
	}
	return result;
}

Table* Table::project(set<int> columnsToKeep)
{
	Table* result = new Table(new Header(header));
	result->header.removeAllOtherColumnsBut(columnsToKeep);
	for (auto i : rows)
	{
		Row* newRow = new Row(i);
		newRow->removeAllOtherColumnsBut(columnsToKeep);
		result->rows.insert(newRow);
	}
	return result;
}

Table* Table::rename(set<ColumnNamePair> newNames)
{
	Table* result = new Table(this);
	for (auto i : newNames)
	{
		result->header.rename(i.getColumn(), i.getName());
	}
	return result;
}

String Table::getName()
{
	return name;
}

Header Table::getHeader()
{
	return header;
}

set<Row*,APtrComp> Table::getRows()
{
	return rows;
}

void Table::addRow(vector<String> invalues)
{
	rows.insert(new Row(invalues));
}

string Table::tostring()
{
	cout << "table" << endl;
	bool first = true;
	stringstream output("");
	for (auto i : rows)
	{
		first = true;
		int temp = 0;
		for (int j = 0; j < header.getcolnames().size() ; j++)
		{
			cout << "header " << header.getcolnames().size() << endl;
			cout << "values " << i->getvalues().size() << endl;
			if (first)
			{
				output << "  "<< header.getcolnames()[j].tostring() << "=" << i->getvalues()[j].tostring();
				first = false;
			}
			else
			{
				output << ", " << header.getcolnames()[j].tostring() << "=" << i->getvalues()[j].tostring() << "";
			}
			temp++;
		}
		output << endl;
	}
	return output.str();
}