#include "Intp.h"
#include "Expr.h"
#include "Element.h"
#include <map>



#include "Number.h"

Intp::Intp(Expr* op1)
{
    op1_ = op1;
}

Element* Intp::eval(map<string,Element*> NT, map<string,Proc*> FT) const
{
    return new Number(((Element*)op1_)->intp());
}
