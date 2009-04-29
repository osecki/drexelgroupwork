/**
 * Program: Car.cpp
 * Authors:  Group 7: Jordan Osecki, Geoff Oxholm, Rich Price, Alimoor Reza
 * Class:    CS550, Assignment 2, Spring 2009
**/

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
    // Calls the getFirst() method from inside list
    Expr* x = ((List*)op1_->eval(NT,FT))->getFirst();
    return x->eval(NT,FT);
}
