#include <map>
#include "Proc.h"
#include "AssignStmt.h"

AssignStmt::AssignStmt(string name, Expr *E)
{
  name_ = name;
  E_ = E;
}

// Changed environment table here
void AssignStmt::eval(map<string,Element*> &NT) const
{
    NT[name_] = E_->eval(NT);
}
