#include "Predicate.h"



Predicate::Predicate(Lexicon* lex, int inpos)
{
	mylex = lex;
	pos = inpos;
	fillparameters();
}


Predicate::~Predicate()
{
}
string Predicate::tostring()
{
	string toreturn = predicateId->tostring();
	toreturn += "(";
	for (int i = 0; i < parameters.size(); i++)
	{
		if(i != 0)
			toreturn += ",";
		toreturn += parameters[i]->tostring();
	}
	toreturn += ")";
	return toreturn;
}
void Predicate::fillparameters()
{
	predicateId = new Id(mylex->returnToken(pos));
	while(mylex->gettoken(pos-1) != LEFT_PAREN)
		pos++;
	for (int i = pos; mylex->gettoken(i) != RIGHT_PAREN; i++)
	{
		if (mylex->gettoken(i) == STRING)
		{
			String* tempstring;
			tempstring = new String(mylex->returnToken(i));
			parameters.push_back(tempstring);
		}
		else if (mylex->gettoken(i) == ID)
		{
			Id* tempid;
			tempid = new Id(mylex->returnToken(i));
			parameters.push_back(tempid);
		}
		else if(mylex->gettoken(i) == LEFT_PAREN )
		{
			Expression* tempexp;
			tempexp = new Expression(mylex, i+1);
			parameters.push_back(tempexp);/*
			while(mylex->gettoken(i) != RIGHT_PAREN || mylex->gettoken(i+1) == RIGHT_PAREN)
				i++;*/
				while (mylex->gettoken(i) != COMMA)
					i++;
		}
	}
	if(parameters.size() == 0)
		throw 0;

}

vector<Parameter*> Predicate::getparameters()
{
	return parameters;
}
Id* Predicate::getid()
{
	return predicateId;
}
