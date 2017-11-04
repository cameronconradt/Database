#pragma once
#include "Fact.h"
#include "Lexicon.h"
#include <sstream>
#include <set>
#include <string>
class Facts
{
public:
	Facts(Lexicon* Lex);
	~Facts();
	string tostring();
	string tostringDomain();
	vector<Fact*> getfacts();
protected:
	Lexicon* mylex;
	vector<Fact*> facts;
	void add();
	set<string> myset;
	enum tokens {
		datalogProgram, scheme, schemeList, idList, fact, factList, rule, ruleList, headPredicate, predicate, predicateList,
		parameter, parameterList, expression, operators, query, queryList, stringList, COMMA, PERIOD, Q_MARK, LEFT_PAREN,
		RIGHT_PAREN, COLON, COLON_DASH, MULTIPLY, ADD, SCHEMES, FACTS, RULES, QUERIES, ID, STRING
	};
};

