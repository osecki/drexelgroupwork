#include <map>
#include "Proc.h"
#include "AssignStmt.h"
#include "ConsCell.h"
#include<vector>


AssignStmt::AssignStmt(string name, Expr *E)
{
  name_ = name;
  E_ = E;
}

// Changed environment table here
void AssignStmt:: eval(map<string,Element*> &NT, map<string,Proc*> &FT,vector<ConsCell> &listMemory, int &avail) const
{
    NT[name_] = E_->eval(NT,FT,listMemory,avail);
}
