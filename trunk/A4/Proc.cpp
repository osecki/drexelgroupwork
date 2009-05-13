/**
 * Program:  Proc.cpp
 * Authors:  Group 7: Jordan Osecki, Geoff Oxholm, Alimoor Reza
 * Class:    CS550, Assignment 4, Spring 2009
**/


#include <list>
#include <map>

#include <string>
#include <iostream>
#include "StmtList.h"
#include "Element.h"
#include "Proc.h"

#define RETURN "return"

Proc::Proc(list<string> *PL, StmtList *SL)
{
    SL_ = SL;
    PL_ = PL;
    NumParam_ = PL->size();
}

Proc::~Proc() {
    delete SL_;
}

void Proc::setTheEnvironment(map<string, Element*> *NewNT) {
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
    if (NumParam_ != EL->size()) {
        cout << "ERROR: Wrong number of parameters to function call" << endl;
        exit(1);
    }
    
    //
    // Establish environment for evaluation
    //
    
    map<string,Element*> *evaluationEnvironment = new map<string,Element*>();    
    if(STATIC) {
		// *Copy* over values from parent environment
	    for (map<string,Element*>::iterator p = savedEnvironment->begin();p != savedEnvironment->end();p++) {
	        (*evaluationEnvironment)[p->first] = p->second;
	    }
	} else {
	    // Copy name table from current context ... (Geoff)
	    for (map<string,Element*>::iterator p = NT.begin();p != NT.end();p++) {
	        (*evaluationEnvironment)[p->first] = p->second;
	    }
    }
    
    	
	// Evaluate parameters 
	// @note These are local only, so should override the parent scope without
	//       changing the parent's values.
    list<string>::iterator p;
    list<Expr*>::iterator e;
    for (p = PL_->begin(), e = EL->begin(); p != PL_->end(); p++, e++) {
        (*evaluationEnvironment)[*p] = (*e)->eval(NT);
    }

	/*
	// Evaluate statement list in the new environment
	cout << "Applying with this environment" << endl;
	for (map<string,Element*>::iterator p = evaluationEnvironment->begin();p != evaluationEnvironment->end();p++) {
        cout << p->first << endl;
    }
    cout << "-EOE-" << endl;
    /**/
	    
    SL_->eval(*evaluationEnvironment);
    
    if(!STATIC) {
		// Copy changes over to single environment
	    for (map<string, Element*>::iterator p = evaluationEnvironment->begin(); p != evaluationEnvironment->end(); p++) {
	    	if(p->first != RETURN) {
	    		// Do not copy return value 
				NT[p->first] = p->second;
	    	}
		}	
    }
    
    if ( evaluationEnvironment->find(RETURN) != evaluationEnvironment->end() ) {
        return (*evaluationEnvironment)[RETURN];
    }
    
    cout << "Error:  No return value set in function" << endl;
    exit(1);
}

