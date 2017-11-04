#include "List.h"



List::List()
{

}


List::~List()
{
}

void List::additem(Token* input)
{
	mytokens.push_back(input);
}

string List::tostring()
{
	string toreturn = "";
	for (int i = 0; i < mytokens.size(); i++)
	{
		toreturn += mytokens[i]->gettext();
	}
		return toreturn;
}
