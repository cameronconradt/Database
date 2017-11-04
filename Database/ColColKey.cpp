#include "ColColKey.h"



ColColKey::ColColKey(int column1, int column2)
{
	col1 = column1;
	col2 = column2;
}


ColColKey::~ColColKey()
{
}

bool ColColKey::type()
{
	return false;
}
int ColColKey::getcol1()
{
	return col1;
}
int ColColKey::getcol2()
{
	return col2;
}