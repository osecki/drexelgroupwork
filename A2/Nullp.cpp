#include "Car.h"
#include "Expr.h"
#include <map>

Nullp::Nullp(Expr* op1)
{
    op1_ = op1;
}

Element* Nullp::eval(map<string,Element*> NT, map<string,Proc*> FT) const
{
    return op1_->nullp();
}
