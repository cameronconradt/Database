#pragma once
#include "Lexicon.h"
#include "HeadPredicate.h"
#include "Predicate.h"
#include <string>
class Rule
{
public:
	Rule(Lexicon* Lex, int inpos);
	~Rule();
	string tostring();
	HeadPredicate* gethead();
	vector<Predicate*> getpredicates();
protected:
	Lexicon* mylex;
	int pos;
	HeadPredicate* head;
	vector<Predicate*> predicates;
	void fillpredicates();
	enum tokens {
		datalogProgram, scheme, schemeList, idList, fact, factList, rule, ruleList, headPredicate, predicate, predicateList,
		parameter, parameterList, expression, operators, query, queryList, stringList, COMMA, PERIOD, Q_MARK, LEFT_PAREN,
		RIGHT_PAREN, COLON, COLON_DASH, MULTIPLY, ADD, SCHEMES, FACTS, RULES, QUERIES, ID, STRING
	};
};

