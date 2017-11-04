#pragma once
#include "Predicate.h"
class Query :
	public Predicate
{
public:
	Query(Lexicon* lex, int inpos);
	~Query();
};

