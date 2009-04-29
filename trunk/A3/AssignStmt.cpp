#include <map>
#include "Proc.h"
#include "AssignStmt.h"

AssignStmt::AssignStmt(string name, Expr *E)
{
  name_ = name;
  E_ = E;
}

// Changed environment table here
void AssignStmt::eval(map<string,Element*> &NT, map<string,Proc*> &FT, Memory &memory) const
{
    NT[name_] = E_->eval(NT,FT,memory);
}
