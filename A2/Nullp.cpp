#include "Expr.h"
#include "List.h"
#include "Nullp.h"
#include "Number.h"
#include <map>

Nullp::Nullp(Expr* op1)
{
    op1_ = op1;
}

Element* Nullp::eval(map<string,Element*> NT, map<string,Proc*> FT) const
{
    return new Number(((List*)op1_)->nullp());
}
