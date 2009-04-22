#include "Listp.h"
#include "Expr.h"
#include "Element.h"
#include <map>



#include "Number.h"

Listp::Listp(Expr* op1)
{
    op1_ = op1;
}

Element* Listp::eval(map<string,Element*> NT, map<string,Proc*> FT) const
{
    return new Number(((Element*)op1_)->listp());
}
