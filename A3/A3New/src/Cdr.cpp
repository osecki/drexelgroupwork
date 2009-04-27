/**
 *  Program:  Cdr.cpp
 *  Authors:  Group 7: Jordan Osecki, Geoff Oxholm, Rich Price, Alimoor Reza
 *  Class:    CS550, Assignment 2, Spring 2009
**/

#include "Cdr.h"
#include "Expr.h"
#include "List.h"
#include <map>
#include "ConsCell.h"
#include<vector>


Cdr::Cdr(Expr* op1)
{
    op1_ = op1;
}

Element* Cdr:: eval(map<string,Element*> &NT, map<string,Proc*> &FT,vector<ConsCell> &listMemory, int &avail) const
{
		// Calls the getRest() function from List
    return ((List*)op1_->eval(NT, FT,listMemory,avail))->getRest();
}
