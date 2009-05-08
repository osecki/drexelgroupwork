#include "Minus.h"
#include "Expr.h"
#include "Number.h"
#include <map>

Minus::Minus(Expr* op1, Expr* op2)
{
    op1_ = op1;
    op2_ = op2;
}

// Changed environment table here and cast it to be a "Number"
Element* Minus::eval(map<string,Element*> NT) const
{
    return new Number(((Number*)op1_->eval(NT))->getValue() - ((Number*)op2_->eval(NT))->getValue());
}
