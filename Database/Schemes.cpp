#include "Schemes.h"



Schemes::Schemes(Lexicon* Lex)
{
	mylex = Lex;
	add();
}


Schemes::~Schemes()
{
	//cout << tostring() << endl;
	for(auto i = schemes.begin(); i != schemes.end(); i++)
	{
		//cout << schemes.size() << endl;
		delete *i;
	}
}
string Schemes::tostring()
{
	stringstream toreturn("");
	toreturn << "Schemes(";
	toreturn << schemes.size() << "):\n";
	for (int i = 0; i < schemes.size(); i++)
	{
		toreturn << "  " << schemes[i]->tostring() << "\n";
	}
	return toreturn.str();
}
void Schemes::add()
{
	int foundfirst = -1;
	for (int i = 0; foundfirst == -1; i++)
	{
		if (mylex->gettoken(i) == SCHEMES)
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
					Scheme* myscheme = new Scheme(mylex, i);
					schemes.push_back(myscheme);
				}
				catch (int)
				{
					done = true;
				}
			}
		}
	}

}
vector<Scheme*> Schemes::getschemes()
{
	return schemes;
}
