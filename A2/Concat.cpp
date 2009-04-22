#include "Concat.h"
#include "Expr.h"
#include "List.h"
#include <map>

Concat::Concat(Expr* op1, Expr* op2)
{
    op1_ = op1;
    op2_ = op2;
}

Element* Concat::eval(map<string,Element*> NT, map<string,Proc*> FT) const
{
    List* newL = new List((List*)op1_->eval(NT, FT));
    newL->concatenate((List*)op2_->eval(NT, FT));
    return newL;
}

