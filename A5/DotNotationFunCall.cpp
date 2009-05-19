/**
 *  Program:  Cons.h
 *  Authors:  Group 7: Jordan Osecki, Geoff Oxholm, Alimoor Reza
 *  Class:    CS550, Assignment 5, Spring 2009
**/

#include <map>
#include "Proc.h"
#include "FunCall.h"
#include "Ident.h"
#include "DotNotationFunCall.h"
#include "NewClass.h"

DotNotationFunCall::DotNotationFunCall(string name, FunCall* FC)
{
    name_= name;
    FC_ = FC;
}

DotNotationFunCall::~DotNotationFunCall() {
    delete FC_;
}

// Changed environment table here
Element* DotNotationFunCall::eval(map<string,Element*> &NT) const
{
    Element* element = (new Ident(name_))->eval(NT);

    if(dynamic_cast<NewClass*>(element)) {
    	NewClass* newClass = dynamic_cast<NewClass*>(element);
    	map<string, Element*>* NNT = newClass->getTheEnvironment();
		  Element* returnElement = FC_->eval(*NNT);
		
    	return returnElement;
    } else {
    	cout << "ERROR: Tried to treat a non-class as a class" << endl;
    	exit(1);
    }
}
