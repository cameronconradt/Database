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

Table* Table::naturalJoin(Table* table)
{
	vector<int> columnsToMerge = header.getColumnsToMerge(table->getHeader());
	Header* resultHeader = new Header(header.mergeWith(table->header, columnsToMerge));
	Table* result = new Table(resultHeader);

	set <ColColKey> colColPairs = header.getColumnMappings(table->header);

	for (auto i : rows)
	{
		for (auto j : table->rows)
		{
			if (i->matches(j, colColPairs))
			{
				result->addRow(i->mergeWith(j, columnsToMerge));
			}
		}
	}
	return result;
	/*	vector<int> columnsToMerge = 
		header.getColumnsToMerge(table.header)
 	Table resultHeader = header.mergeWith(table.header, columnsToMerge))
	Table result = new Table(resultHeader)

	set<ColColPair> colColPairs = 
		header.getColumnMappings(table.header)

	for( Row row1 in rows)
		for(Row row2 in table.rows())
			if(row1.matches(row2, colColPairs)
				result.addRow(
					row1.mergeWith(row2,columnsToMerge))
*/
}

Table* Table::Union(Table* table)
{
	/*	vector<int> newOrderingMap = header.createMapFor(table.getHeader())
	for(Row row in table.rows)
		Row rearrangedRow =	row.rearrange(newOrderingMap)
		rows.add(rearrangedRow)
*/

	Table* result = new Table(this);
	vector<int> neworder = header.createMap(table->getHeader());
	for (auto i : rows)
	{
		Row* rearrangedRow = new Row(i->rearrange(neworder));
		result->addRow(rearrangedRow);
	}
	set <ColColKey> colColPairs = header.getColumnMappings(table->header);
	for (auto i : table->rows)
	{
		vector<String> values;
		for (auto j : colColPairs)
		{
			values.push_back(i->getvalues()[j.getcol2()]);
		}
		Row* newRow = new Row(values);
		result->addRow(newRow);
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
void Table::addRow(Row* inrow)
{
	rows.insert(inrow);
}

string Table::tostring()
{
	cout << "table =" << endl;
	bool first = true;
	stringstream output("");
	for (auto i : rows)
	{
		first = true;
		int temp = 0;
		for (int j = 0; j < header.getcolnames().size() ; j++)
		{
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