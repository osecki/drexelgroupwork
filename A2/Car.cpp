#include "Car.h"
#include "Expr.h"
#include "List.h"
#include <map>

Car::Car(Expr* op1)
{
    op1_ = op1;
}

Element* Car::eval(map<string,Element*> NT, map<string,Proc*> FT) const
{
    return ((List*)op1_)->getFirst();
}
