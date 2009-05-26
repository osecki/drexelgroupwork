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

void IfStmt::translate(map<int, string> &constantValues, map<string, SymbolDetails> &symbolTable) const
{
	// Handle Condition
	string cond = E_->translate(constantValues, symbolTable);
	cout<<"LD	" << cond << endl;

	// Handle First Jumps
	Program p;
	string newLabel1;
	stringstream outLabel1;
	outLabel1 << p.labelCounter;
	newLabel1 = "L" + outLabel1.str();
	p.labelCounter++;

	cout<<"JMN	"<<newLabel1<<endl;
	cout<<"JMZ	"<<newLabel1<<endl;

	// Handle Code Block 1
	S1_->translate(constantValues, symbolTable);

	// Handle Second Jumps
	string newLabel2;
	stringstream outLabel2;
	outLabel2 << p.labelCounter;
	newLabel2 = "L" + outLabel2.str();
	p.labelCounter++;

	cout<<"JMP	"<<newLabel2<<endl;

	// Handle Code Block 2
	cout<<newLabel1<<":";
	S2_->translate(constantValues, symbolTable);

	// Handle Last Label
	cout<<newLabel2<<":";
}

