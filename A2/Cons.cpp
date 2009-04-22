#include "Cons.h"
#include "Expr.h"
#include "List.h"
#include <map>

Cons::Cons(Expr* op1, Expr* op2)
{
    op1_ = op1;
    op2_ = op2;
}

Element* Cons::eval(map<string,Element*> NT, map<string,Proc*> FT) const
{
    List* newL = new List((List*)op1_->eval(NT, FT));
    Element* two = (Element*)op2_->eval(NT, FT);
    newL->cons(two);
    return newL;
}