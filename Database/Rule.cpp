#include "Rule.h"



Rule::Rule(Lexicon* Lex, int inpos)
{
	mylex = Lex;
	pos = inpos;
	fillpredicates();
}


Rule::~Rule()
{
}

string Rule::tostring()
{
	string toreturn = "  " + head->tostring() + " :- ";
	for (int i = 0; i < predicates.size(); i++)
	{
		if(i != 0)
			toreturn += ",";
		toreturn += predicates[i]->tostring();
	}
	toreturn += ".";
	return toreturn;

}

void Rule::fillpredicates()
{
	head = new HeadPredicate(mylex, pos);
	Predicate* temppredicate;
	for (int i = pos; mylex->gettoken(i-2) != COLON_DASH; i++)
		pos = i;
	for (int i = pos; mylex->gettoken(i) != PERIOD; i++)
	{
		if (mylex->gettoken(i) == ID && mylex->gettoken(i+1) == LEFT_PAREN)
		{
			Token* temp = mylex->returnToken(i);
			temppredicate = new Predicate(mylex, i);
			predicates.push_back(temppredicate);
		}
	}
	if(predicates.size() == 0)
		throw 0;
}

HeadPredicate* Rule::gethead()
{
	return head;
}
vector<Predicate*> Rule::getpredicates()
{
	return predicates;
}