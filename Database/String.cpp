#include "String.h"



String::String(Token* token)
{
	mytoken = token;
}

String::String()
{

}


String::~String()
{
}
string String::tostring()
{
	return mytoken->gettext();
}

string String::type()
{
	return "string";
}
