#pragma once
#include "Lexicon.h"
#include "Id.h"
#include <iostream>
class Scheme
{
public:
	Scheme(Lexicon* Lex, int inpos);
	~Scheme();
	string tostring();
	Id* getid();
	vector<Id*> getcolumnNames();
protected:
	Lexicon* mylex;
	int pos;
	vector<Id*> columnNames;
	Id* schemeId;
	void fillcolumns();
	enum tokens {
		datalogProgram, scheme, schemeList, idList, fact, factList, rule, ruleList, headPredicate, predicate, predicateList,
		parameter, parameterList, expression, operators, query, queryList, stringList, COMMA, PERIOD, Q_MARK, LEFT_PAREN,
		RIGHT_PAREN, COLON, COLON_DASH, MULTIPLY, ADD, SCHEMES, FACTS, RULES, QUERIES, ID, STRING
	};
};

