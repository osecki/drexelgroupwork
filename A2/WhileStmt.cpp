#include <map>
#include "Proc.h"
#include "WhileStmt.h"
#include "Expr.h"
#include "Number.h"

WhileStmt::WhileStmt(Expr *E, StmtList *S)
{
  E_ = E;
  S_ = S;
}

WhileStmt::~WhileStmt() { delete E_; delete S_; }

// Changed environment table here
void WhileStmt::eval(map<string,Element*> &NT, map<string,Proc*> &FT) const
{
    while (((Number*)E_->eval(NT,FT))->getValue() > 0)
        S_->eval(NT,FT);
}
