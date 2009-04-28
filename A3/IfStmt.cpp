#include "IfStmt.h"
#include "StmtList.h"
#include "Proc.h"
#include "Expr.h"
#include "Number.h"
#include <map>
#include "ConsCell.h"
#include<vector>



IfStmt::IfStmt(Expr *E, StmtList *S1, StmtList *S2)
{
  E_ = E;
  S1_ = S1;
  S2_ = S2;
}

IfStmt::~IfStmt() { delete E_; delete S1_; delete S2_; }

// Changed environment table here
void IfStmt::eval(map<string,Element*> &NT, map<string,Proc*> &FT,vector<ConsCell> &listMemory, int &avail) const
{
    if (((Number*)E_->eval(NT,FT,listMemory,avail))->getValue() > 0)
        S1_->eval(NT,FT,listMemory,avail);
    else
        S2_->eval(NT,FT,listMemory,avail);
}
