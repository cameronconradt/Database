#include "Queries.h"



Queries::Queries(Lexicon* Lex)
{
	mylex = Lex;
	add();
}


Queries::~Queries()
{
}
string Queries::tostring()
{
	stringstream toreturn("Queries(");
	toreturn << "Queries(";
	toreturn << queries.size() << "):\n";
	for (int i = 0; i < queries.size(); i++)
	{
		toreturn << "  "<< queries[i]->tostring() << "?\n";
	}
	return toreturn.str();
}
void Queries::add()
{
	int foundfirst = -1;
	for (int i = 0; foundfirst == -1; i++)
	{
		if (mylex->gettoken(i) == QUERIES)
		{
			if (mylex->gettoken(i+1) == COLON)
			{
				foundfirst = i;
			}
		}
	}
	bool done = false;
	for (int i = foundfirst; !done; i++)
	{
		if(mylex->gettoken(i) == end)
		{
			done = true;
		}
		if (mylex->gettoken(i) == ID)
		{
			if (mylex->gettoken(i + 1) == LEFT_PAREN)
			{
				try {
					Query* myquery = new Query(mylex, i);
					queries.push_back(myquery);
				}
				catch (int)
				{
					done = true;
				}
			}
		}
	}
}

vector<Query*> Queries::getqueries()
{
	return queries;
}
