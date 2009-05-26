#include "Plus.h"
#include "Expr.h"
#include "Number.h"
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

string Plus::translate(map<int, string> &constantValues, map<string, SymbolDetails> &symbolTable) const
{
	// Handle two operands
	string temp1 = op1_->translate(constantValues, symbolTable);
	string temp2 = op2_->translate(constantValues, symbolTable);

	// Handle Load and operator
	cout<<"LD	"<<temp1<<endl;
	cout<<"ADD	"<<temp2<<endl;

	// Handle Final Store and Temporary Variable Creation
	Program P;
	string newTemp;
	stringstream out;
	out << P.temporaryVarCounter;
	newTemp = "T" + out.str();
	P.temporaryVarCounter++;

	SymbolDetails newSymbolTemp(-1, "Temporary", -1);
	symbolTable[newTemp] = newSymbolTemp;
	cout<<"ST	"<<newTemp<<endl;

	return newTemp;
}