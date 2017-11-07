#pragma once
#include <iostream>
#include "parser.h"
#include "DatalogProgram.h"
#include "Database.h"

using namespace std;


int main(int argc, char* argv[])
{

		ifstream myfile(argv[1]);
		if (!myfile.is_open())
		{
			cout << "Bad file name!" << endl;
			return 0;
		}
		else
		{
			parser* myparse = new parser(argv[1]);
			Database* mydata = new Database(myparse->getprogram());
			cout << mydata->tostring();
		}
	return 0;
}