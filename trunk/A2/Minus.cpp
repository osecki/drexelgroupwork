#include "Minus.h"
#include "Expr.h"
#include <map>

Minus::Minus(Expr* op1, Expr* op2)
{
    op1_ = op1;
    op2_ = op2;
}

Element* Minus::eval(map<string,Element*> NT, map<string,Proc*> FT) const
{
    return op1_->eval(NT,FT) - op2_->eval(NT,FT);
}
