#include "ColumnNamePair.h"



ColumnNamePair::ColumnNamePair(int column, String inname)
{
	col = column;
	name = inname;
}


ColumnNamePair::~ColumnNamePair()
{
}

int ColumnNamePair::getColumn()
{
	return col;
}

String ColumnNamePair::getName()
{
	return name;
}