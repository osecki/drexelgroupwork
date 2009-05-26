#include "Number.h"
#include <map>
#include "Program.h"
#include <sstream>
#include <iostream>
#define CONSTANT "CONSTANT_"
using namespace std;

Number::Number(int value)
{
    value_ = value;
}

string Number::translate(map<int, string> &constantValues, map<string, SymbolDetails> &symbolTable) const
{
	// Look into constant table for the Number. If it is there get value, otherwise create new Number and add to symbol table
	string newConstant;
	Program p;
	
	map<int, string>::iterator location = constantValues.find(value_);
	if ( location!=constantValues.end() ) {
		newConstant = constantValues[value_];
	}else {
		stringstream outConst;

		outConst << p.constantCounter;
		newConstant = CONSTANT + outConst.str();
		// increment the counter for the next constant
		p.constantCounter++;
		// add this into the constant table
		constantValues[value_] = newConstant;
		// then add to the symbol table
		SymbolDetails newSymbolConst(value_, "Constant", -1);
		symbolTable[newConstant] = newSymbolConst;
	}

	cout<<"LD	"<<newConstant<<endl;

	// create new temporary variable then Store the new ident there
	string newTemp;
	stringstream outTemp;
	outTemp << p.temporaryVarCounter;
	newTemp = "T" + outTemp.str();
	p.temporaryVarCounter++;

	SymbolDetails newSymbolTemp(-1, "Temporary", -1);
	symbolTable[newTemp] = newSymbolTemp;

	cout<<"ST	"<<newTemp<<endl;

	return newTemp;
}
