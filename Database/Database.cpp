#include "Database.h"



Database::Database(DatalogProgram* indatalog)
{
	datalog = indatalog;
	maketables();
	getresults();
}


Database::~Database()
{
}

void Database::maketables()
{
	vector<Scheme*> myschemes = datalog->getschemes()->getschemes();
	for (int i = 0; i < myschemes.size(); i++)
	{
		String* name = new String(myschemes[i]->getid()->gettoken());
		vector<String> colnames;
		vector<Id*> schemenames = myschemes[i]->getcolumnNames();
		for (int j = 0; j < schemenames.size(); j++)
		{
			String col(schemenames[j]->gettoken());
			//if(std::find(colnames.begin(), colnames.end(),col) != colnames.end())
			colnames.push_back(col);
		}
		Header head(colnames);
		Table* temptable = new Table(*name, head);
		tables.push_back(temptable);
	}
	vector<Fact*> myfacts = datalog->getfacts()->getfacts();
	for (int i = 0; i < myfacts.size(); i++)
	{
		String name(myfacts[i]->getid()->gettoken());
		for (int j = 0; j < tables.size(); j++)
		{
			if (name.tostring() == tables[j]->getName().tostring())
			{
				vector<String*> stringvalues = myfacts[i]->getstrings();
				vector<String> values;
				for (int k = 0; k < stringvalues.size(); k++)
				{
					values.push_back(*stringvalues[k]);
				}
				tables[j]->addRow(values);
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
			if (temp.tostring() == tables[j]->getName().tostring())
				evaluate(myqueries[i], tables[j]);
		}
	}
}

void Database::evaluate(Query* query, Table* table)
{
	Table* result = new Table(table);
	set<SelectionKey*> selkeys;
	vector<Parameter*> parameters = query->getparameters();
	vector<Parameter*> ids;
	set<int> coltokeep;
	for (int i = 0; i < parameters.size(); i++)
	{
		if (parameters[i]->type() == "string")
		{
			String* temp = dynamic_cast<String*>(parameters[i]);
			SelectionKey* tempkey = new ColValueKey(i, *temp);
			selkeys.insert(tempkey);
		}
		else
		{
			if (parameters[i]->type() == "id")
			{
				ids.push_back(parameters[i]);
				for(int j = 0; j < ids.size()-1; j++)
				{
					if(parameters[i]->tostring() == ids[j]->tostring())
						ids.pop_back();
				}
			}
			for (int j = 0; j < i; j++)
			{
				if (parameters[j]->type() == "id" && parameters[i]->type() == "id")
				{
					if (parameters[j]->tostring() == parameters[i]->tostring())
					{
						SelectionKey* tempkey = new ColColKey(j, i);
						selkeys.insert(tempkey);
					}
				}
			}
		}
	}
	result = result->select(selkeys);
	for (auto i : ids)
	{
		for (int j = 0; j < parameters.size(); j++)
		{
			if (parameters[j] == i)
			{
				coltokeep.insert(j);
				break;
			}
		}
	}
	result = result->project(coltokeep);
	set<ColumnNamePair> newNames;
	int col = 0;
	for (auto i : coltokeep)
	{
		Id* tempid = dynamic_cast<Id*>(parameters[i]);
		String tempstr(tempid->gettoken());
		ColumnNamePair temp(col, tempstr);
		newNames.insert(temp);
		col++;
	}
	result = result->rename(newNames);
	results.push_back(result);
}

string Database::tostring()
{
	cout << "tostring" << endl;
	stringstream output;
	vector<Query*> myqueries = datalog->getqueries()->getqueries();
	for (int i = 0; i < myqueries.size(); i++)
	{
		cout << "here" << endl;
		output << myqueries[i]->tostring();
		set<Row*, APtrComp> rows = results[i]->getRows();
		if (rows.size() > 0)
		{
			output << "Yes(" << rows.size() << ")\n" << results[i]->tostring();
		}
		else
		{
			output << "No\n";
		}
		cout << "output = " << output.str() << endl;
	}
	return output.str();
}