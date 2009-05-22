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

IfStmt::~IfStmt() { delete E_; delete S1_; delete S2_; }

void IfStmt::eval(map<string,int> &NT) const
{
	if (E_->eval(NT) > 0)
		S1_->eval(NT);
	else
		S2_->eval(NT);
}
