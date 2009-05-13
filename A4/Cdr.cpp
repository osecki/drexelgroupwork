/**
 *  Program:  Cdr.cpp
 *  Authors:  Group 7: Jordan Osecki, Geoff Oxholm, Alimoor Reza
 *  Class:    CS550, Assignment 4, Spring 2009
**/

#include "Cdr.h"
#include "Expr.h"
#include "List.h"
#include <map>

Cdr::Cdr(Expr* op1)
{
    op1_ = op1;
}

Element* Cdr::eval(map<string,Element*> &NT) const
{
    Element* e = op1_->eval(NT);
    if(dynamic_cast<List*>(e)) {
    	return ((List*)e)->getRest()->eval(NT);
    }
    
    cout << "ERROR: Can not perform cdr on a non-list" << endl;
    exit(1);
    
}
