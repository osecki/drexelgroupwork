/**
 * Program: Car.cpp
 * Authors:  Group 7: Jordan Osecki, Geoff Oxholm, Alimoor Reza
 * Class:    CS550, Assignment 5, Spring 2009
**/

#include "Car.h"
#include "Expr.h"
#include "List.h"
#include <map>

Car::Car(Expr* op1)
{
    op1_ = op1;
}

Element* Car::eval(map<string,Element*> &NT) const
{
    Element* e = op1_->eval(NT);
    if(dynamic_cast<List*>(e)) {
    	return ((List*)e)->getFirst()->eval(NT); 
    }
    
    cout << "ERROR: Can not perform car on a non-list" << endl;
    exit(1);	
}
