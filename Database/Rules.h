#pragma once
#include <vector>
#include <sstream>
#include "Lexicon.h"
#include "Rule.h"
#include "Scheme.h"
class Rules
{
public:
	Rules(Lexicon* Lex);
	~Rules();
	string tostring();
	vector<Rule*> getrules();
protected:
	Lexicon* mylex;
	vector<Rule*> rules;
	void add();
	enum tokens {
		datalogProgram, scheme, schemeList, idList, fact, factList, rule, ruleList, headPredicate, predicate, predicateList,
		parameter, parameterList, expression, operators, query, queryList, stringList, COMMA, PERIOD, Q_MARK, LEFT_PAREN,
		RIGHT_PAREN, COLON, COLON_DASH, MULTIPLY, ADD, SCHEMES, FACTS, RULES, QUERIES, ID, STRING
	};
};

