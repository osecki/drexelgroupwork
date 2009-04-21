#include "Cdr.h"
#include "Expr.h"
#include <map>

Plus::Cdr(Expr* op1)
{
    op1_ = op1;
}

Element* Cdr::eval(map<string,Element*> NT, map<string,Proc*> FT) const
{
    return op1_->getRest();
}
