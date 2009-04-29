/**
 *  Program:  Nullp.cpp
 *  Authors:  Group 7: Jordan Osecki, Geoff Oxholm, Rich Price, Alimoor Reza
 *  Class:    CS550, Assignment 2, Spring 2009
**/

#include "Expr.h"
#include "List.h"
#include "Nullp.h"
#include "Number.h"
#include <map>

Nullp::Nullp(Expr* op1)
{
    op1_ = op1;
}

Element* Nullp::eval(map<string,Element*> NT, map<string,Proc*> FT, Memory &memory) const
{
	  // Calls the nullp() function from List
    return new Number(((List*)op1_->eval(NT,FT,memory))->nullp());
}
