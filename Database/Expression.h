#pragma once
#include "Parameter.h"
#include "Lexicon.h"
#include "String.h"
#include "Id.h"
#include <string>
#include <sstream>
class Expression :
	public Parameter
{
public:
	Expression(Lexicon* lex, int inpos);
	~Expression();
	string tostring();
protected:
	Lexicon* mylex;
	int pos;
	Token* myoperator;
	vector<Parameter*> parameters;
	void addtoparameters();
	void fillexpr();
	enum tokens {
		datalogProgram, scheme, schemeList, idList, fact, factList, rule, ruleList, headPredicate, predicate, predicateList,
		parameter, parameterList, expression, operators, query, queryList, stringList, COMMA, PERIOD, Q_MARK, LEFT_PAREN,
		RIGHT_PAREN, COLON, COLON_DASH, MULTIPLY, ADD, SCHEMES, FACTS, RULES, QUERIES, ID, STRING
	};
};

