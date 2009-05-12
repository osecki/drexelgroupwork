/**
 *  Program:  Concat.cpp
 *  Authors:  Group 7: Jordan Osecki, Geoff Oxholm, Alimoor Reza
 *  Class:    CS550, Assignment 4, Spring 2009
**/

#include "Concat.h"
#include "Expr.h"
#include "List.h"
#include <map>

Concat::Concat(Expr* op1, Expr* op2)
{
    op1_ = op1;
    op2_ = op2;
}

Element* Concat::eval(map<string,Element*> &NT) const
{
		// Calls the concatenate() function from List
    List* newL = new List((List*)op1_->eval(NT));
    newL->concatenate((List*)op2_->eval(NT));
    return newL;
}

