#pragma once
#include "DatalogProgram.h"
#include "Table.h"
class Database
{
public:
	Database(DatalogProgram* indatalog);
	~Database();
protected:
	DatalogProgram* datalog;
	vector<Table*> tables;
	void maketables();
};

