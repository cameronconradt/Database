#include "Scheme.h"



Scheme::Scheme(Lexicon* Lex, int inpos)
{
	mylex = Lex;
	pos = inpos;
	fillcolumns();
}


Scheme::~Scheme()
{
	delete schemeId;
	for(auto i = columnNames.begin(); i != columnNames.end(); i++)
	{
		
		delete *i;
	}
}

string Scheme::tostring()
{
	string toreturn = schemeId->tostring();
	toreturn += "(";
	for (int i = 0; i < columnNames.size(); i++)
	{
		if(i!=0)
			toreturn +=",";
		toreturn += columnNames[i]->tostring();
	}
	toreturn += ")";
	return toreturn;
}

void Scheme::fillcolumns()
{
	schemeId = new Id(mylex->returnToken(pos));
	Id* tempid;
	for (int i = pos + 1; mylex->gettoken(i-1) != RIGHT_PAREN; i++)
	{
		if(mylex->gettoken(i) == ID)
		{
			tempid = new Id(mylex->returnToken(i));
			columnNames.push_back(tempid);
		}
	}
	if(columnNames.size() == 0)
		throw 0;
}

Id* Scheme::getid()
{
	return schemeId;
}

vector<Id*> Scheme::getcolumnNames()
{
	return columnNames;
}
