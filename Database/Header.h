#pragma once
#include "String.h"
#include <set>
class Header
{
public:
	Header(set<String> incolumnNames);
	Header(Header* inheader);
	Header();
	~Header();
	set<String> getcolnames();
	void removeAllOtherColumnsBut(set<int> columnsToKeep);
	void rename(int column, String newName);
protected:
	set<String> columnNames;
};

