#pragma once
#include "Query.h"
#include "Lexicon.h"
class Queries
{
public:
	Queries(Lexicon* Lex);
	~Queries();
	string tostring();
	vector<Query*> getqueries();
protected:
	Lexicon* mylex;
	vector<Query*> queries;
	void add();
	enum tokens {
		datalogProgram, scheme, schemeList, idList, fact, factList, rule, ruleList, headPredicate, predicate, predicateList,
		parameter, parameterList, expression, operators, query, queryList, stringList, COMMA, PERIOD, Q_MARK, LEFT_PAREN,
		RIGHT_PAREN, COLON, COLON_DASH, MULTIPLY, ADD, SCHEMES, FACTS, RULES, QUERIES, ID, STRING, end
	};
};

