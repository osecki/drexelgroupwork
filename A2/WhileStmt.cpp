#include <map>
#include "Proc.h"
#include "WhileStmt.h"

WhileStmt::WhileStmt(Expr *E, StmtList *S)
{
  E_ = E;
  S_ = S;
}

WhileStmt::~WhileStmt() { delete E_; delete S_; }

void WhileStmt::eval(map<string,Element*> &NT, map<string,Proc*> &FT) const
{
    while (E_->eval(NT,FT) > 0)
        S_->eval(NT,FT);
}
