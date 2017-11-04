#include "Fact.h"



Fact::Fact(Lexicon* Lex, int inpos)
{
	mylex = Lex;
	pos = inpos;
	fillstrings();
}


Fact::~Fact()
{
}

string Fact::tostring()
{
	string toreturn = factId->tostring();
	toreturn += "(";
	for (int i = 0; i < strings.size(); i++)
	{
		if(i!=0)
			toreturn+= ",";
		toreturn += strings[i]->tostring();
	}
	toreturn += ").";
	return toreturn;

}
set<string> Fact::returnDomain()
{
	for(int i = 0; i < strings.size(); i++)
	{
		myset.insert(strings[i]->tostring());
	}
	return myset;
}
void Fact::fillstrings()
{
	factId = new Id(mylex->returnToken(pos));
	String* tempstring;
	for (int i = pos + 1; mylex->gettoken(i - 1) != PERIOD; i++)
	{
		if(mylex->gettoken(i) == STRING)
		{		
			tempstring = new String(mylex->returnToken(i));
			strings.push_back(tempstring);
		}
	}
	if(strings.size() == 0)
		throw 0;
}
vector<String*> Fact::getstrings()
{
	return strings;
}
Id* Fact::getid()
{
	return factId;
}