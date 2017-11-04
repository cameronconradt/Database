#include "Facts.h"



Facts::Facts(Lexicon* Lex)
{
	mylex = Lex;
	add();
}


Facts::~Facts()
{

}
string Facts::tostring()
{
	stringstream toreturn("");
	toreturn << "Facts(";
	toreturn << facts.size() << "):\n";
	for (int i = 0; i < facts.size(); i++)
	{
		toreturn << "  " << facts[i]->tostring() << "\n";
	}
	return toreturn.str();
}
string Facts::tostringDomain()
{
	for(int i = 0; i < facts.size(); i++)
	{
		set<string> tempset = facts[i]->returnDomain();
		for(set<string>::iterator j = tempset.begin(); j !=tempset.end(); j ++)
		{
			myset.insert(*j);
		}
	}
	stringstream ss;
	ss << "Domain(";
	ss << myset.size();
	ss << ")\n";
	for(set<string>::iterator i = myset.begin(); i != myset.end(); i++)
	{
		ss << "  " << *i << endl;
	}
	return ss.str();
}
void Facts::add()
{
	int foundfirst = -1;
	for (int i = 0; foundfirst == -1; i++)
	{
		if (mylex->gettoken(i) == FACTS)
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
		if (mylex->gettoken(i) == ID)
		{
			if (mylex->gettoken(i + 1) == LEFT_PAREN)
			{
				try {
					Fact* myscheme = new Fact(mylex, i);
					facts.push_back(myscheme);
				}
				catch (int)
				{
					done = true;
				}
			}
		}
	}
}
vector<Fact*> getfacts()
{
	return facts;
}

