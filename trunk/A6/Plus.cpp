#include "Plus.h"
#include "Expr.h"
#include "Number.h"
#include <map>

Plus::Plus(Expr* op1, Expr* op2)
{
    op1_ = op1;
    op2_ = op2;
}

/*int Plus::eval(map<string,int> T) const
{
	return op1_->eval(T) + op2_->eval(T);
}*/


string Plus::translate(map<int, string> &constantValues, map<string, SymbolDetails> &symbolTable) const{

	Program P;

	string temp1 = op1_->translate(constantValues, symbolTable);
	string temp2 = op2_->translate(constantValues, symbolTable);


	cout<<"LD	"<<temp1<<endl;
	cout<<"ADD	"<<temp2<<endl;

	string newTemp;

	stringstream out;
	out << P.temporaryVarCounter;
	newTemp = "T" + out.str();

	P.temporaryVarCounter++;

	SymbolDetails newSymbolTemp(-1,"Temporary",-1);

	symbolTable[newTemp] = newSymbolTemp;

	cout<<"ST	"<<newTemp<<endl;

	return newTemp;
}