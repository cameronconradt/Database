#pragma once
#include "Lexicon.h"
#include "String.h"
#include "Id.h"
#include <set>
#include <string>
class Fact
{
public:
	Fact(Lexicon* Lex, int inpos);
	~Fact();
	string tostring();
	set<string> returnDomain();
	vector<String*> getstrings();
	Id* getid();
protected:
	Lexicon* mylex;
	int pos;
	vector<String*> strings;
	Id* factId;
	set<string> myset;
	void fillstrings();
	enum tokens {
		datalogProgram, scheme, schemeList, idList, fact, factList, rule, ruleList, headPredicate, predicate, predicateList,
		parameter, parameterList, expression, operators, query, queryList, stringList, COMMA, PERIOD, Q_MARK, LEFT_PAREN,
		RIGHT_PAREN, COLON, COLON_DASH, MULTIPLY, ADD, SCHEMES, FACTS, RULES, QUERIES, ID, STRING
	};
};

