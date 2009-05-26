#include "Plus.h"
#include "Expr.h"
#include "Number.h"
#include <vector>
#include <map>
#include <sstream>
#include "Program.h"
#include <iostream>
using namespace std;

Plus::Plus(Expr* op1, Expr* op2)
{
    op1_ = op1;
    op2_ = op2;
}

string Plus::translate(map<int, string> &constantValues, map<string, SymbolDetails> &symbolTable, vector<string> &ralProgram) const
{
	// Handle two operands
	string temp1 = op1_->translate(constantValues, symbolTable, ralProgram);
	string temp2 = op2_->translate(constantValues, symbolTable, ralProgram);

	// Handle Load and operator
	ralProgram.push_back("LD " + temp1);
	ralProgram.push_back("ADD " + temp2);

	// Handle Final Store and Temporary Variable Creation
	Program P;
	string newTemp;
	stringstream out;
	out << P.temporaryVarCounter;
	newTemp = "T" + out.str();
	P.temporaryVarCounter++;

	SymbolDetails newSymbolTemp(-1, "Temporary", -1);
	symbolTable[newTemp] = newSymbolTemp;
	ralProgram.push_back("ST " + newTemp);

	return newTemp;
}
