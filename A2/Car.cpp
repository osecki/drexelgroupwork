#include "Car.h"
#include "Expr.h"
#include <map>

Plus::Car(Expr* op1)
{
    op1_ = op1;
}

Element* Car::eval(map<string,Element*> NT, map<string,Proc*> FT) const
{
    return op1_->getFirst();
}
