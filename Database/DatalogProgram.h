#pragma once
#include "Lexicon.h"
#include "Rules.h"
#include "Facts.h"
#include "Queries.h"
#include "Schemes.h"
class DatalogProgram
{
public:
	DatalogProgram(Lexicon* lex);
	~DatalogProgram();
	string tostring();
	Schemes* getschemes();
	Queries* getqueries();
	Facts* getfacts();
	Rules* getrules();
protected:
	Schemes* schemes;
	Queries* queries;
	Facts* facts;
	Rules* rules;
};