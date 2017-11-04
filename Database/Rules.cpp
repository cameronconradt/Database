#include "Rules.h"



Rules::Rules(Lexicon* Lex)
{
	mylex = Lex;
	add();
}


Rules::~Rules()
{
}
string Rules::tostring()
{
	stringstream toreturn("");
	toreturn << "Rules(";
	toreturn << rules.size() << "):\n";
	for (int i = 0; i < rules.size(); i++)
	{
		toreturn << rules[i]->tostring() << "\n";
	}
	return toreturn.str();
}

void Rules::add()
{
	int foundfirst = -1;
	for (int i = 0; -1 ==foundfirst; i++)
	{
		if (mylex->gettoken(i) == RULES)
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
		if(mylex->gettoken(i) == QUERIES)
			done = true;
		if ((mylex->gettoken(i - 1) != COLON_DASH) &&(mylex->gettoken(i - 1) !=  COMMA))
		{
			if (mylex->gettoken(i) == ID)
			{
				if (mylex->gettoken(i + 1) == LEFT_PAREN)
				{
					try {
						Rule* myrule = new Rule(mylex, i);
						rules.push_back(myrule);
					}
					catch (int)
					{
						done = true;
					}
				}
			}
		}
	}
}

vector<Rule*> Rules::getrules()
{
	return rules;
}