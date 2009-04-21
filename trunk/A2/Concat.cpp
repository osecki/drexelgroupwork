#include "Concat.h"
#include "Expr.h"
#include <map>

Concat::Concat(Expr* op1, Expr* op2)
{
    op1_ = op1;
		op2_ = op2;
}

Element* Concat::eval(map<string,Element*> NT, map<string,Proc*> FT) const
{
    return op1_->concatenate(op2_);
}
