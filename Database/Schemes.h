#pragma once
#include "Scheme.h"
#include "Lexicon.h"
#include <vector>
#include <sstream>
#include <iostream>
class Schemes
{
public:
	Schemes(Lexicon* Lex);
	~Schemes();
	string tostring();
	vector<Scheme*> getschemes();
protected:
	Lexicon* mylex;
	vector<Scheme*> schemes;
	void add();
	enum tokens {
		datalogProgram, scheme, schemeList, idList, fact, factList, rule, ruleList, headPredicate, predicate, predicateList,
		parameter, parameterList, expression, operators, query, queryList, stringList, COMMA, PERIOD, Q_MARK, LEFT_PAREN,
		RIGHT_PAREN, COLON, COLON_DASH, MULTIPLY, ADD, SCHEMES, FACTS, RULES, QUERIES, ID, STRING
	};
};

