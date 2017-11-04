#pragma once
#include "Parameter.h"
#include "Id.h"
#include "Lexicon.h"
#include "Expression.h"
#include "String.h"
#include <string>
#include <vector>
class Predicate
{
public:
	Predicate(Lexicon* lex, int inpos);
	~Predicate();
	string tostring();
	vector<Parameter*> getparameters();
	Id* getid();
protected:
	Lexicon* mylex;
	int pos;
	Id* predicateId;
	vector <Parameter*> parameters;
	void fillparameters();
	enum tokens {
		datalogProgram, scheme, schemeList, idList, fact, factList, rule, ruleList, headPredicate, predicate, predicateList,
		parameter, parameterList, expression, operators, query, queryList, stringList, COMMA, PERIOD, Q_MARK, LEFT_PAREN,
		RIGHT_PAREN, COLON, COLON_DASH, MULTIPLY, ADD, SCHEMES, FACTS, RULES, QUERIES, ID, STRING
	};

};

