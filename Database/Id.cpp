#include "Id.h"



Id::Id(Token* token)
{
	mytoken = token;
}


Id::~Id()
{
	delete mytoken;
}

string Id::tostring()
{
	return mytoken->gettext();
}

Token* Id::gettoken()
{
	return mytoken;
}

string Id::type()
{
	return "id";
}