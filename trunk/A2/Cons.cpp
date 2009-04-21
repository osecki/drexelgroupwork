#include "Cons.h"
#include "Expr.h"
#include <map>

Cons::Cons(Expr* op1, Expr* op2)
{
    op1_ = op1;
		op2_ = op2;
}

Element* Cons::eval(map<string,Element*> NT, map<string,Proc*> FT) const
{
    return op1_->cons(op2_);
}
