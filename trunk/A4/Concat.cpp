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
	Element* e1 = op1_->eval(NT);
	Element* e2 = op2_->eval(NT);
	if(dynamic_cast<List*>(e1) && dynamic_cast<List*>(e2)){
    	List* newL = new List((List*)e1);
    	newL->concatenate((List*)e2);
    	return newL;
	}
	
	cout << "ERROR: Tried to conncatenate non-lists" << endl;
	exit(1);
}

