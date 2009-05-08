/**
 * Program: Car.cpp
 * Authors:  Group 7: Jordan Osecki, Geoff Oxholm, Alimoor Reza
 * Class:    CS550, Assignment 4, Spring 2009
**/

#include "Car.h"
#include "Expr.h"
#include "List.h"
#include <map>

Car::Car(Expr* op1)
{
    op1_ = op1;
}

Element* Car::eval(map<string,Element*> NT) const
{
    // Calls the getFirst() method from inside list
    Element* x = ((List*)op1_->eval(NT))->getFirst()->eval(NT);
    return x;
}
