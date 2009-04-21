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

void DefineStmt::eval(map<string,int> &NT, map<string,Proc*> &FT) const
{
    FT[name_] = P_;
}
