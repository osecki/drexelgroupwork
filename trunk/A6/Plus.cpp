#include "Plus.h"
#include "Expr.h"
#include "Number.h"
#include <map>

Plus::Plus(Expr* op1, Expr* op2)
{
    op1_ = op1;
    op2_ = op2;
}

int Plus::eval(map<string,int> T) const
{
	return op1_->eval(T) + op2_->eval(T);
}
