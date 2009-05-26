#ifndef SYMBOLDETAILS_H
#define SYMBOLDETAILS_H

//#include <map>
#include <string>
//#include "StmtList.h"
using namespace std;

//class StmtList;

class SymbolDetails
{
public:
	SymbolDetails(int value, string type, int address);
	SymbolDetails();
	int getValue();
	string getType();
	int getAddress();

//private:
    int value_;
    string type_;
    int address_;
private:
};

#endif
