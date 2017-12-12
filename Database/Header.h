#pragma once
#include "String.h"
#include "ColColKey.h"
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
	vector<int> getColumnsToMerge(Header inheader);
	Header* mergeWith(Header inheader, vector<int> columnsToMerge);
	set<ColColKey> getColumnMappings(Header inheader);
	vector<int> createMap(Header inheader);
protected:
	vector<String> columnNames;
	int getLocOf(String value);
};

