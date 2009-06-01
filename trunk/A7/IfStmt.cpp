#include "IfStmt.h"
#include "StmtList.h"
#include "Expr.h"
#include "Number.h"
#include <vector>
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

void IfStmt::translate(map<int, string> &constantValues, map<string, SymbolDetails> &symbolTable, vector<string> &ralProgram, map<string, Proc*> &ralProgramFT) const
{
	// Handle Condition
	string cond = E_->translate(constantValues, symbolTable, ralProgram);
	ralProgram.push_back("LDA " + cond);

	// Handle First Jumps
	Program p;
	string newLabel1;
	stringstream outLabel1;
	outLabel1 << p.labelCounter;
	newLabel1 = "L" + outLabel1.str();
	p.labelCounter++;

	ralProgram.push_back("JMN " + newLabel1);
	ralProgram.push_back("JMZ " + newLabel1);

	// Handle Code Block 1
	S1_->translate(constantValues, symbolTable, ralProgram);

	// Handle Second Jumps
	string newLabel2;
	stringstream outLabel2;
	outLabel2 << p.labelCounter;
	newLabel2 = "L" + outLabel2.str();
	p.labelCounter++;

	ralProgram.push_back("JMP " + newLabel2);

	// Handle Code Block 2
	ralProgram.push_back(newLabel1 + ":");
	S2_->translate(constantValues, symbolTable, ralProgram);

	// Handle Last Label
	ralProgram.push_back(newLabel2 + ":");
}

