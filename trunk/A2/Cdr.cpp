#include "Cdr.h"
#include "Expr.h"
#include "List.h"
#include <map>

Cdr::Cdr(Expr* op1)
{
    op1_ = op1;
}

Element* Cdr::eval(map<string,Element*> NT, map<string,Proc*> FT) const
{
    return ((List*)op1_)->getRest();
}
