#include <map>
#include "WhileStmt.h"
#include "Expr.h"
#include "Number.h"
#include "Program.h"
#include <sstream>
#include <iostream>
using namespace std;

WhileStmt::WhileStmt(Expr *E, StmtList *S)
{
  	E_ = E;
  	S_ = S;
}

void WhileStmt::translate(map<int, string> &constantValues, map<string, SymbolDetails> &symbolTable) const
{
  // Handle first label and condition
	Program p;
	string newLabel1;
	stringstream outLabel1;
	outLabel1 << p.labelCounter;
	newLabel1 = "L" + outLabel1.str();
	p.labelCounter++;
	cout<<newLabel1<<":";

	string temp = E_->translate(constantValues, symbolTable);
	cout<<"LD	"<<temp<<endl;

  // Handle the first jumps
	string newLabel2;
	stringstream outLabel2;
	outLabel2 << p.labelCounter;
	newLabel2 = "L" + outLabel2.str();
	p.labelCounter++;

	cout<<"JMN	"<<newLabel2<<endl;
	cout<<"JMZ	"<<newLabel2<<endl;

	// Handle the loop body
	S_->translate(constantValues, symbolTable);

	// Handle the second jumps
	cout<<"JMP	"<<newLabel1<<endl;

	// Handle last label
	cout<<newLabel2<<":";
}
