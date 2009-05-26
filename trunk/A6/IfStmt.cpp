#include "IfStmt.h"
#include "StmtList.h"
#include "Expr.h"
#include "Number.h"
#include <map>
#include "Program.h"
#include <sstream>
#include <iostream>
using namespace std;

IfStmt::IfStmt(Expr *E, StmtList *S1, StmtList *S2)
{
  E_ = E;
  S1_ = S1;
  S2_ = S2;
}

/*void IfStmt::eval(map<string,int> &T) const
{
	if (E_->eval(T) > 0)
		S1_->eval(T);
	else
		S2_->eval(T);
}*/

void IfStmt::translate(map<int, string> &constantValues, map<string, SymbolDetails> &symbolTable) const{

	//cout<<"";
	string temp = E_->translate(constantValues, symbolTable);

	cout<<"LD	"<<temp<<endl;

	Program p;
	string newLabel1;
	stringstream outLabel1;
	outLabel1 << p.labelCounter;

	newLabel1 = "L" + outLabel1.str();

	p.labelCounter++;

	cout<<"JMN	"<<newLabel1<<endl;
	cout<<"JMZ	"<<newLabel1<<endl;

	S1_->translate(constantValues, symbolTable);

	string newLabel2;
	stringstream outLabel2;
	outLabel2 << p.labelCounter;

	newLabel2 = "L" + outLabel2.str();

	p.labelCounter++;

	cout<<"JMP	"<<newLabel2<<endl;

	cout<<newLabel1<<":";
	S2_->translate(constantValues, symbolTable);

	cout<<newLabel2<<":";
}