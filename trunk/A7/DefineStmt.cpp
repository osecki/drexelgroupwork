#include "Proc.h"
#include "DefineStmt.h"

DefineStmt::~DefineStmt()
{
  	delete P_;
}

DefineStmt::DefineStmt(string name, Proc *P)
{
  	name_ = name;
  	P_ = P;
}

void DefineStmt::translate(map<int, string> &constantValues, map<string, SymbolDetails> &symbolTable, vector<string> &ralProgram, map<string, Proc*> &FT) const
{
	// Add proc to function table
    FT[name_] = P_;
    // Generate its code
    P_->translate(constantValues, FT);
}
