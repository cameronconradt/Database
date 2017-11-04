#pragma once
#include "Predicate.h"
#include "Token.h"
class HeadPredicate :
	public Predicate
{
public:
	HeadPredicate(Lexicon* lex, int inpos);
	~HeadPredicate();
};

