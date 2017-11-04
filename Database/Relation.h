#pragma once
#include "Table.h"
#include "SelectionKey.h"
#include "ColumnNamePair.h"
#include <vector>
class Relation
{
public:
	Relation();
	~Relation();
protected:
	vector<Table> mytables;
};

