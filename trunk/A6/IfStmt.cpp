#include "IfStmt.h"
#include "StmtList.h"
#include "Expr.h"
#include "Number.h"
#include <map>

IfStmt::IfStmt(Expr *E, StmtList *S1, StmtList *S2)
{
  E_ = E;
  S1_ = S1;
  S2_ = S2;
}

void IfStmt::eval(map<string,int> &T) const
{
	if (E_->eval(T) > 0)
		S1_->eval(T);
	else
		S2_->eval(T);
}
