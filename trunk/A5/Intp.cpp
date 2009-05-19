/**
 *  Program:  Intp.cpp
 *  Authors:  Group 7: Jordan Osecki, Geoff Oxholm, Alimoor Reza
 *  Class:    CS550, Assignment 5, Spring 2009
**/

#include "Intp.h"
#include "Expr.h"
#include "Element.h"
#include <map>

#include "Number.h"

Intp::Intp(Expr* op1)
{
    op1_ = op1;
}

Element* Intp::eval(map<string,Element*> &NT) const
{
    return new Number(op1_->eval(NT)->intp());
}
