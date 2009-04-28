/**
 *  Program:  Listp.cpp
 *  Authors:  Group 7: Jordan Osecki, Geoff Oxholm, Rich Price, Alimoor Reza
 *  Class:    CS550, Assignment 2, Spring 2009
**/

#include "Listp.h"
#include "Expr.h"
#include "Element.h"
#include <map>
#include "ConsCell.h"
#include<vector>

#include "Number.h"

Listp::Listp(Expr* op1)
{
    op1_ = op1;
}

Element* Listp:: eval(map<string,Element*> &NT, map<string,Proc*> &FT,vector<ConsCell> &listMemory, int &avail) const
{
		// Calls the listp() function from List
    return new Number(((Element*)op1_->eval(NT, FT,listMemory,avail))->listp());
}
