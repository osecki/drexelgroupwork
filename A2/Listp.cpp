#include "Listp.h"
#include "Expr.h"
#include <map>

Listp::Listp(Expr* op1)
{
    op1_ = op1;
}

Element* Listp::eval(map<string,Element*> NT, map<string,Proc*> FT) const
{
    return op1_->listp();
}
