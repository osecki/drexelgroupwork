#include "Intp.h"
#include "Expr.h"
#include <map>

Intp::Intp(Expr* op1)
{
    op1_ = op1;
}

Element* Intp::eval(map<string,Element*> NT, map<string,Proc*> FT) const
{
    return op1_->intp();
}
