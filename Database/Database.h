#pragma once
#include "DatalogProgram.h"
#include "Table.h"
#include <sstream>
class Database
{
public:
	Database(DatalogProgram* indatalog);
	~Database();
	string tostring();
protected:
	DatalogProgram* datalog;
	vector<Table*> tables;
	vector<Table*> results;
	void getresults();
	void maketables();
	void evaluate(Query* query, Table* table);
};

