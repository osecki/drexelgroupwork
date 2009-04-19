#include <map>
#include "Proc.h"
#include "AssignStmt.h"

AssignStmt::AssignStmt(string name, Expr *E)
{
  name_ = name;
  E_ = E;
}

void AssignStmt::eval(map<string,int> &NT, map<string,Proc*> &FT) const
{
    NT[name_] = E_->eval(NT,FT);
}
