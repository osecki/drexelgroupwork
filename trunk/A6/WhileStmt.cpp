#include <map>
#include "WhileStmt.h"
#include "Expr.h"
#include "Number.h"

WhileStmt::WhileStmt(Expr *E, StmtList *S)
{
  	E_ = E;
  	S_ = S;
}

void WhileStmt::eval(map<string,int> &T) const
{
	while (E_->eval(T) > 0) 
		S_->eval(T);
}
