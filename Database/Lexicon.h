#pragma once
#include <string>
#include <vector>
#include <sstream>
#include <ctype.h>
#include <iostream>
#include "Token.h"

using namespace std;


class Lexicon
{
public:
	Lexicon();
	~Lexicon();
	string tostring();
	void readin(char in);
	void filter();
	int gettoken(int pos);
	Token* returnToken(int pos);
protected:
	vector<Token*> tokens;
	vector<char> chars;
	int endline;
	enum tokens {
		datalogProgram, scheme, schemeList, idList, fact, factList, rule, ruleList, headPredicate, predicate, predicateList,
		parameter, parameterList, expression, operators, query, queryList, stringList, COMMA, PERIOD, Q_MARK, LEFT_PAREN,
		RIGHT_PAREN, COLON, COLON_DASH, MULTIPLY, ADD, SCHEMES, FACTS, RULES, QUERIES, ID, STRING, end
	};
	int id(int line, int pos);
	void comma(int line);
	void period(int line);
	void q_mark(int line);
	void left_paren(int line);
	void right_paren(int line);
	void colon(int line);
	void colon_dash(int line);
	void multiply(int line);
	void add(int line);
	void undefined_single(int line, int pos);
	void eof(int line);
	int line_comment(int line, int pos);
	int addstring(int line, int pos);
	int block_comment(int line, int pos);
	int undefined(int line, int pos);
	int schemes(int line, int pos);
	int facts(int line, int pos);
	int rules(int line, int pos);
	int queries(int line, int pos);

};

