#include "Number.h"
#include <map>
#include "Program.h"
#include <sstream>
#include <vector>
#include <iostream>
#define CONSTANT "C"
using namespace std;

Number::Number(int value)
{
    value_ = value;
}

string Number::getConstant(map<int, string> &constantValues, int value) {
	map<int, string>::iterator location = constantValues.find(value);
	if ( location!=constantValues.end() ) {
		return constantValues[value];
	} else {
		stringstream outConst;

		outConst << value;
		string newConstant = CONSTANT + outConst.str();
		// increment the counter for the next constant
		Program::constantCounter++;
		// add this into the constant table
		constantValues[value] = newConstant;
		return newConstant;
	}
}

string Number::translate(map<int, string> &constantValues, map<string, SymbolDetails> &symbolTable, vector<string> &ralProgram, map<string, Proc*> &FT) const
{
	ralProgram.push_back("; + number");
	// Look into constant table for the Number. If it is there get value, otherwise create new Number and add to symbol table
	string newConstant = getConstant(constantValues, value_);


	// create new temporary variable then Store the new ident there
	string newTemp;
	stringstream outTemp;
	outTemp << Program::temporaryVarCounter;
	newTemp = "T" + outTemp.str();
	Program::temporaryVarCounter++;

	SymbolDetails newSymbolTemp(-1, "Temporary", -1);
	symbolTable[newTemp] = newSymbolTemp;

	// Load the dynamic memory location
	ralProgram.push_back("LD " + newConstant);
	// Save the constant there
	ralProgram.push_back("STO " + newTemp);
	

	ralProgram.push_back("; - number");

	return newTemp;
}
