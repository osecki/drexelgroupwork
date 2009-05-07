/**
 *  Program:  Intp.cpp
 *  Authors:  Group 7: Jordan Osecki, Geoff Oxholm, Rich Price, Alimoor Reza
 *  Class:    CS550, Assignment 2, Spring 2009
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

Element* Intp::eval(map<string,Element*> NT, map<string,Proc*> FT) const
{
		// Calls the intp() function from integer
    return new Number(((Element*)op1_->eval(NT, FT))->intp());
}
