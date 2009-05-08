/**
 * Program:  Cons.cpp
 * Authors:  Group 7: Jordan Osecki, Geoff Oxholm, Alimoor Reza
 * Class:    CS550, Assignment 4, Spring 2009
**/

#include "Cons.h"
#include "Expr.h"
#include "List.h"
#include <map>

Cons::Cons(Expr* op1, Expr* op2)
{
    op1_ = op1;
    op2_ = op2;
}

Element* Cons::eval(map<string,Element*> NT) const
{
		// Calls the cons() function from List
    List* newL = new List((List*)op1_->eval(NT));
    Element* two = (Element*)op2_->eval(NT);
    newL->cons(two);
    return newL;
}