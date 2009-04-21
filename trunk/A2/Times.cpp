#include "Times.h"
#include "Expr.h"
#include <map>

Times::Times(Expr* op1, Expr* op2)
{
    op1_ = op1;
    op2_ = op2;
}

int Times::eval(map<string,int> NT, map<string,Proc*> FT) const
{
    return op1_->eval(NT,FT) * op2_->eval(NT,FT);
}
