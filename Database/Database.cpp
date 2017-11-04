#include "Database.h"



Database::Database(DatalogProgram* indatalog)
{
	datalog = indatalog;
	maketables();
}


Database::~Database()
{
}

void Database::maketables()
{
	vector<Scheme*> myschemes = datalog->getschemes()->getschemes();
	for (int i = 0; i < myschemes.size(); i++)
	{
		String* name = new String(myschemes[i]->getid()->gettoken);
		set<String> colnames;
		vector<Id*> schemenames = myschemes[i]->getcolumnNames;
		for (int j = 0; j < schemenames.size(); j++)
		{
			String col(schemenames[j]->gettoken());
			colnames.insert(col);
		}
		Header head(colnames);
		Table* temptable = new Table(*name, head);
		tables.push_back(temptable);
	}
	vector<Fact*> myfacts = datalog->getfacts()->getfacts();
	for (int i = 0; i < myfacts.size(); i++)
	{
		String name(myfacts[i]->getid()->gettoken);
		for (int j = 0; j < tables.size(); j++)
		{
			if (name == tables[i]->getName())
			{
				vector<String*> stringvalues = myfacts[i]->getstrings();
				vector<String> values;
				for (int k = 0; k < stringvalues.size(); k++)
				{
					values.push_back(*stringvalues[i]);
				}
				tables[i]->addRow(values);
			}
		}
	}
}

void Database::getresults()
{
	vector<Query*> myqueries = datalog->getqueries()->getqueries();
	for (int i = 0; i < myqueries.size(); i++)
	{
		for (int j = 0; j < tables.size(); j++)
		{
			String temp(myqueries[i]->getid()->gettoken());
			if (temp == tables[j]->getName())
				evaluate(myqueries[i], tables[j]);
		}
	}
}

void Database::evaluate(Query* query, Table* table)
{

}