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
	name = getName();
	header = getHeader();
	rows = getRows();
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

set<Row*> Table::getRows()
{
	return rows;
}

void Table::addRow(vector<String> invalues)
{
	rows.insert(new Row(invalues));
}

string Table::tostring()
{
	stringstream output;
	for (auto i : rows)
	{
		int temp = 0;
		for (auto j : header.getcolnames())
		{
			if(j == header.getcolnames().begin())
				output << j.tostring() << "='" << i->getvalues()[temp].tostring() << "'";
		}
		output << endl;
	}
}