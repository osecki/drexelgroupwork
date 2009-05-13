/**
 * Program:  Proc.cpp
 * Authors:  Group 7: Jordan Osecki, Geoff Oxholm, Alimoor Reza
 * Class:    CS550, Assignment 4, Spring 2009
**/

#include "Proc.h"
#include <list>
#include <map>
#include <string>
#include "StmtList.h"
#include <iostream>
#include "Element.h"


Proc::Proc(list<string> *PL, StmtList *SL)
{
    SL_ = SL;
    PL_ = PL;
    NumParam_ = PL->size();
}

Proc::~Proc() {
    delete SL_;
}

void Proc::setTheEnvironment(map<string, Element*> NewNT) {
	this->savedEnvironment = NewNT;
}

Element* Proc::eval(map<string,Element*> &NT) const {
	return new Proc(*this);
}


string Proc::toString(map<string,Element*> NT) const {
	return "** Function **";
}

// Changed environment table here and in function below
Element* Proc::apply(map<string,Element*> &NT, list<Expr*> *EL)
{
    map<string,Element*> evaluationEnvironment;

    // bind parameters in new name table

    if (NumParam_ != EL->size()) {
        cout << "Param count does not match" << endl;
        exit(1);
    }
        
    // Do this always
	evaluationEnvironment = savedEnvironment;
	
    if(!STATIC) {
	    // Copy name table from current context ... (Geoff)
	    for (map<string,Element*>::iterator p = NT.begin();p != NT.end();p++) {
    		// TODO Remove me
    		// cout << "Copying over " << p->first << endl;
	        evaluationEnvironment[p->first] = p->second;
	    }
    }
    
    	
	// Evaluate parameters
    list<string>::iterator p;
    list<Expr*>::iterator e;
    for (p = PL_->begin(), e = EL->begin(); p != PL_->end(); p++, e++) {
        evaluationEnvironment[*p] = (*e)->eval(NT);
    }
    


	/* TODO Remove me
	cout << "Evaluating with environment: "<< endl;
	for (map<string, Element*>::iterator p = evaluationEnvironment.begin(); p != evaluationEnvironment.end(); p++) {	
		cout << p->first << endl;
	}
	*/

    // evaluate function body using new name table and old function table

    SL_->eval(evaluationEnvironment);
    
    if(!STATIC) {
		// Copy changes over to single environment
	    for (map<string, Element*>::iterator p = evaluationEnvironment.begin(); p != evaluationEnvironment.end(); p++) {
	    	if(p->first != "return")	
				NT[p->first] = p->second;
		}	
    }
    
    if ( evaluationEnvironment.find("return") != evaluationEnvironment.end() ) {
        return evaluationEnvironment["return"];
    } else {
        cout << "Error:  no return value" << endl;
        exit(1);
    }
}

