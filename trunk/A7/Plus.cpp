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

string Plus::translate(map<int, string> &constantValues, map<string, SymbolDetails> &symbolTable, vector<string> &ralProgram, map<string, Proc*> &FT) const
{
	// Handle two operands
  string temp1, temp2;
	temp1 = op1_->translate(constantValues, symbolTable, ralProgram, FT);
	temp2 = op2_->translate(constantValues, symbolTable, ralProgram, FT);
	ralProgram.push_back("LDO " + temp2);
	ralProgram.push_back("STA " + TEMP);
	ralProgram.push_back("LDO " + temp1);
	ralProgram.push_back("ADD " + TEMP);

	// Handle Final Store and Temporary Variable Creation
	Program P;
	string newTemp;
	stringstream out;
	out << P.temporaryVarCounter;
	newTemp = "T" + out.str();
	P.temporaryVarCounter++;

	SymbolDetails newSymbolTemp(-1, "Temporary", -1);
	symbolTable[newTemp] = newSymbolTemp;
	ralProgram.push_back("STO " + newTemp);

	return newTemp;
}
