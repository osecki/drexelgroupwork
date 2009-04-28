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

// Changed environment table here
void DefineStmt::eval(map<string,Element*> &NT, map<string,Proc*> &FT) const
{
    FT[name_] = P_;
}
