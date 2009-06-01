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

/*void DefineStmt::eval(map<string,Element*> &NT, map<string,Proc*> &FT) const
{
    FT[name_] = P_;
}*/

void DefineStmt::translate(map<int, string> &constantValues, map<string, SymbolDetails> &symbolTable, vector<string> &ralProgram, map<string, Proc*> &ralProgramFT) const
{
	// TODO
}
