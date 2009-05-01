#include "Plus.h"
#include "Expr.h"
#include "Number.h"
#include <map>

Plus::Plus(Expr* op1, Expr* op2)
{
    op1_ = op1;
    op2_ = op2;
}

// Changed environment table here and casted it to be a "Number"
Element* Plus::eval(map<string,Element*> NT, map<string,Proc*> FT, Memory &memory) const
{
    return new Number(((Number*)op1_->eval(NT,FT,memory))->getValue() + ((Number*)op2_->eval(NT,FT,memory))->getValue());
}
