#include "Minus.h"
#include "Expr.h"
#include "Number.h"
#include <map>
#include <iostream>
#include <sstream>
#include "Program.h"
using namespace std;

Minus::Minus(Expr* op1, Expr* op2)
{
    op1_ = op1;
    op2_ = op2;
}

/*int Minus::eval(map<string,int> T) const
{
	return op1_->eval(T) - op2_->eval(T);
}*/

string Minus::translate(map<int, string> &constantValues, map<string, SymbolDetails> &symbolTable) const{
	string temp1 = op1_->translate(constantValues, symbolTable);
	string temp2 = op2_->translate(constantValues, symbolTable);

	cout<<"LD	"<<temp1<<endl;
	cout<<"SUB	"<<temp2<<endl;

	string newTemp;

	stringstream out;
	Program p;
	out << p.temporaryVarCounter;
	newTemp = "T" + out.str();

	p.temporaryVarCounter++;

	SymbolDetails newSymbolTemp(-1,"Temporary",-1);

	symbolTable[newTemp] = newSymbolTemp;

	cout<<"ST	"<<newTemp<<endl;


	return newTemp;
}

