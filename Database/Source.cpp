#pragma once
#include "Table.h"
#include "Token.h"
#include "String.h"
#include "SelectionKey.h"
#include "ColumnNamePair.h"
#include "ColColKey.h"
#include "ColValueKey.h"
#include <vector>

using namespace std;

bool test1(Table* table, int col1, int col2);
bool test2(Table* table, String* a, int keep);
bool test3(Table* table, String* c, int coltorename);
bool test4(Table* table, String* a, int col);
bool test5(Table* table);
bool test6(Table* table);
bool test7(Table* table);
bool test8(Table* table);
bool test9(Table* table);
bool test10(Table* table);
void addtovector(vector<vector<String>> &vec, String str1, String str2);

int main()
{
	String* a = new String( new Token("STRING", "a", 1));
	String* b = new String(new Token("STRING", "b", 1));
	String* c = new String(new Token("STRING", "c", 1));
	set<String> columnNames;
	columnNames.insert(*a);
	columnNames.insert(*b);
	Header header(columnNames);
	Table* mytable = new Table(*a, header);
	vector<vector<String>> rows;
	addtovector(rows, *a, *a);
	addtovector(rows, *b, *b);
	addtovector(rows, *a, *b);
	addtovector(rows, *b, *a);
	for (int i = 0; i < rows.size(); i++)
		mytable->addRow(rows[i]);
	Table* newtable = new Table(mytable);
	vector<bool> results;
	if (test1(mytable, 0, 1))
		results.push_back(true);
	else
		results.push_back(false);
	if (test2(mytable, a, 0))
		results.push_back(true);
	else
		results.push_back(false);
	if (test3(mytable, c,0))
		results.push_back(true);
	else
		results.push_back(false);
	if (test4(mytable, a,0))
		results.push_back(true);
	else
		results.push_back(false);
	if (test5(mytable))
		results.push_back(true);
	else
		results.push_back(false);
	if (test6(mytable))
		results.push_back(true);
	else
		results.push_back(false);
	if (test7(mytable))
		results.push_back(true);
	else
		results.push_back(false);
	if (test8(mytable))
		results.push_back(true);
	else
		results.push_back(false);
	if (test9(mytable))
		results.push_back(true);
	else
		results.push_back(false);
	if (test10(mytable))
		results.push_back(true);
	else
		results.push_back(false);
	for (int i = 1; i < 11; i++)
	{
		if (results[i-1])
			cout << "Test " << i << " Succeeded!" << endl;
		else
			cout << "Test " << i << " Failed!" << endl;
	}

	return 0;
}
void addtovector(vector<vector<String>> &vec, String str1, String str2)
{
	vector<String> row;
	row.push_back(str1);
	row.push_back(str2);
	vec.push_back(row);
}
bool test1(Table* table, int col1, int col2) // Select - ColCol
{
	ColColKey* sel = new ColColKey(col1, col2);
	set<SelectionKey*> myset;
	myset.insert(sel);
	table = table->select(myset);
	if (table->getRows().size() == 2)
	{
		return true;
	}
	else
		return false;
}
bool test2(Table* table, String* a, int keep) // Project
{
	set<int> columnstokeep;
	columnstokeep.insert(keep);
	table = table->project(columnstokeep);
	auto i = table->getHeader().getcolnames().begin();
	String temp = *i;
	if (temp.tostring() == a->tostring())
	{
		return true;
	}
	else
		return false;
}
bool test3(Table* table, String* c, int coltorename) // Rename
{
	String temp = *c;
	set<ColumnNamePair> newNames;
	ColumnNamePair* newpair = new ColumnNamePair(coltorename, temp);
	newNames.insert(*newpair);
	table = table->rename(newNames);
	set<String> newtableheader = table->getHeader().getcolnames();
	auto i = newtableheader.begin();
	for(int j = 0; j < coltorename && i != newtableheader.end(); j++)
	{
		i++;
	}
	if(i != newtableheader.end())
		temp = *i;
	if (temp.tostring() == c->tostring())
	{
		return true;
	}
	else
		return false;
}
bool test4(Table* table, String* a, int col) // Select - ColValue
{
	SelectionKey* sel = new ColValueKey(col, *a);
	set<SelectionKey*> myset;
	myset.insert(sel);
	table = table->select(myset);
	if (table->getRows().size() == 2)
	{
		return true;
	}
	else
		return false;
}
bool test5(Table* table) // Select ColCol, ColValue
{
	String* a = new String(new Token("STRING", "a", 1));
	SelectionKey* sel = new ColColKey(0, 1);
	set<SelectionKey*> myset;
	myset.insert(sel);
	sel = new ColValueKey(1, *a);
	myset.insert(sel);
	table = table->select(myset);
	if (table->getRows().size() == 1)
	{
		return true;
	}
	else
		return false;
}
bool test6(Table* table) // Select ColCol - Project
{
	//Select ColCol
	ColColKey* sel = new ColColKey(0, 1);
	set<SelectionKey*> myset;
	myset.insert(sel);
	table = table->select(myset);

	//Project
	set<int> columnstokeep;
	columnstokeep.insert(1);
	String* b = new String(new Token("STRING", "b", 1));
	table = table->project(columnstokeep);
	auto i = table->getHeader().getcolnames().begin();
	String temp = *i;

	if (table->getRows().size() == 2)
	{
		if (temp.tostring() == b->tostring())
		{
			return true;
		}
		else
			return false;
	}
	else
		return false;
}
bool test7(Table* table) // Query a(c,c)
{
	String* c = new String(new Token("STRING", "c", 1));
	String* a = new String(new Token("STRING", "a", 1));
	if (test1(table, 0, 1))
		if (test2(table, a, 0))
			if (test3(table, c, 0))
			{
				return true;
			}
	return false;
}
bool test8(Table* table) // Query a(c,'b')
{
	String* a = new String(new Token("STRING", "a", 1));
	String* c = new String(new Token("STRING", "c", 1));
	String* b = new String(new Token("STRING", "b", 1));
	if (test4(table, b, 0))
		if (test2(table, a, 0))
			if (test3(table, c, 0))
				return true;
	return false;
	
}
bool test9(Table* table) // Query a('b',c)
{
	String* a = new String(new Token("STRING", "a", 1));
	String* c = new String(new Token("STRING", "c", 1));
	String* b = new String(new Token("STRING", "b", 1));
	if (test4(table, b, 1))
		if (test2(table, b, 1))
			if (test3(table, c, 0))
				return true;
	return false;
}
bool test10(Table* table) // Query a(c,d)
{
	String* c = new String(new Token("STRING", "c", 1));
	String* d = new String(new Token("STRING", "d", 1));

	if (test3(table, c, 0))
		if (test3(table, d, 1))
			return true;
	return false;
}