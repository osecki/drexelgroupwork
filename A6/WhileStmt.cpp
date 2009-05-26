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

void WhileStmt::translate(map<int, string> &constantValues, map<string, SymbolDetails> &symbolTable, vector<string> &ralProgram) const
{
  // Handle first label and condition
	Program p;
	string newLabel1;
	stringstream outLabel1;
	outLabel1 << p.labelCounter;
	newLabel1 = "L" + outLabel1.str();
	p.labelCounter++;;

	string temp = E_->translate(constantValues, symbolTable, ralProgram);
	ralProgram.push_back(newLabel1 + ":LD	" + temp);

  // Handle the first jumps
	string newLabel2;
	stringstream outLabel2;
	outLabel2 << p.labelCounter;
	newLabel2 = "L" + outLabel2.str();
	p.labelCounter++;

	ralProgram.push_back("JMN	" + newLabel2);
	ralProgram.push_back("JMZ	" + newLabel2);

	// Handle the loop body
	S_->translate(constantValues, symbolTable, ralProgram);

	// Handle the second jumps
	ralProgram.push_back("JMP	" + newLabel1);

	// Handle last label
	ralProgram.push_back(newLabel2 + ":");
}
