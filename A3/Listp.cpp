/**
 *  Program:  Listp.cpp
 *  Authors:  Group 7: Jordan Osecki, Geoff Oxholm, Rich Price, Alimoor Reza
 *  Class:    CS550, Assignment 2, Spring 2009
**/

#include "Listp.h"
#include "Expr.h"
#include "Element.h"
#include <map>

#include "Number.h"

Listp::Listp(Expr* op1)
{
    op1_ = op1;
}

Element* Listp::eval(map<string,Element*> NT, map<string,Proc*> FT, Memory &memory) const
{
		// Calls the listp() function from List
    return new Number(((Element*)op1_->eval(NT, FT))->listp());
}
