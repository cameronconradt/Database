#pragma once
#include "String.h"
#include "Header.h"
#include "Row.h"
#include "SelectionKey.h"
#include "ColumnNamePair.h"
#include <set>
class Table
{
public:
	Table(String inname, Header inheader);
	Table(Header inheader);
	Table(Table* intable);
	~Table();
	Table* select(set<SelectionKey*> selectionKeys);
	Table* project(set<int> columnsToKeep);
	Table* rename(set<ColumnNamePair> newNames);
	String getName();
	Header getHeader();
	set<Row*> getRows();
	void addRow(vector<String> invalues);
protected:
	String name;
	Header header;
	set<Row*> rows;
};

