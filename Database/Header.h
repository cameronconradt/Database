#pragma once
#include "String.h"
#include <algorithm>
#include <vector>
#include <set>
class Header
{
public:
	Header(vector<String> incolumnNames);
	Header(Header* inheader);
	Header();
	~Header();
	vector<String> getcolnames();
	void removeAllOtherColumnsBut(set<int> columnsToKeep);
	void rename(int column, String newName);
protected:
	vector<String> columnNames;
};

