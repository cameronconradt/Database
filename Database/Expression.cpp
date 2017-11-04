#include "Expression.h"



Expression::Expression(Lexicon* lex, int inpos)
{
	//cout << "expression" << endl;
	mylex = lex;
	pos = inpos;
	fillexpr();
	
}


Expression::~Expression()
{
}

string Expression::tostring()
{
	stringstream toreturn;
	toreturn << "(";
	toreturn << parameters[0]->tostring();
	toreturn << myoperator->gettext();
	toreturn << parameters[1]->tostring();
	toreturn << ")";
	return toreturn.str();
}

void Expression::fillexpr()
{
	Parameter* temp;
	while(parameters.size() == 0)
		addtoparameters();/*
	for (int i = pos; mylex->gettoken(i - 1) != ADD || mylex->gettoken(i - 1) != MULTIPLY; i++)
	{
		pos = i;
	}*/
	myoperator = mylex->returnToken(pos);
	pos++;
	while(parameters.size() == 1)
	addtoparameters();
}

void Expression::addtoparameters()
{
	if(mylex->gettoken(pos) != COMMA  && mylex->gettoken(pos) != COLON_DASH)
	{
		Parameter* temp;
		if (mylex->gettoken(pos) == STRING)
		{
			temp = new String(mylex->returnToken(pos));
		}
		else if (mylex->gettoken(pos) == ID)
		{
			temp = new Id(mylex->returnToken(pos));
		}
		else if(mylex->gettoken(pos) == LEFT_PAREN)
		{
			temp = new Expression(mylex, pos+1);
			int paren = 0;
			if(parameters.size() == 0)
			{
				string tempstring = temp->tostring();
				for(int i = 0; i < tempstring.length(); i++)
				{
					if(tempstring[i] == '(')
						{
							paren++;
							
						}
				}
			}
			for(int i = 0; i < paren; i++)
			{
				if(i != 0)
					pos++;
				while(mylex->gettoken(pos)!= RIGHT_PAREN || mylex->gettoken(pos+1) == RIGHT_PAREN)
				pos++;
			}
			/*
			while(mylex->gettoken(pos)!= RIGHT_PAREN || mylex->gettoken(pos+1) == RIGHT_PAREN)
				pos++;*/
		}
		parameters.push_back(temp);
	}
	pos++;
}

string Expression::type()
{
	return "expression";
}
