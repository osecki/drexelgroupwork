/**
 * Program:  NewClass.cpp
 * Authors:  Group 7: Jordan Osecki, Geoff Oxholm, Alimoor Reza
 * Class:    CS550, Assignment 5, Spring 2009
**/

#include <list>
#include <map>
#include <string>
#include <iostream>
#include "StmtList.h"
#include "Element.h"
#include "NewClass.h"

#define RETURN "return"


NewClass::NewClass(string name,list<string> *PL, StmtList *SL)
{
    SL_ = SL;
    PL_ = PL;
    this->name_ = name;
    this->superClassName_ = "";
    NumParam_ = PL->size();
    superClass_ = NULL;
    savedEnvironment = new map<string,Element*>();
}

NewClass::NewClass(string name, string superClassName, list<string> *PL, StmtList *SL)
{
    SL_ = SL;
    PL_ = PL;
    this->name_ = name;
    this->superClassName_ = superClassName;
    NumParam_ = PL->size();
    superClass_ = NULL;
    savedEnvironment = new map<string,Element*>();
}

NewClass::~NewClass() {
    delete SL_;
}

string NewClass::getName() {
	return this->name_;
}
string NewClass::getSuperClassName() {
	return this->superClassName_;
}
NewClass* NewClass::getTheSuperClass() {
	return this->superClass_;
}

void NewClass::setTheEnvironment(map<string, Element*> *NewNT) {
	this->savedEnvironment = NewNT;
}
map<string, Element*>* NewClass::getTheEnvironment()
{
	return this->savedEnvironment;
}

Element* NewClass::eval(map<string,Element*> &NT) const {
	// in the name table save the description of the class
	NT[name_] = new NewClass(*this);
	return NT[name_];
}

string NewClass::toString(map<string,Element*> NT) const {
	return "**Class**";
}

// Changed environment table here and in function below
Element* NewClass::constructor(map<string,Element*> &NT, list<Expr*> *EL)
{
    if (NumParam_ != EL->size()) {
        cout << "ERROR: Wrong number of parameters to class creation. Expecting " << NumParam_ << " got " << EL->size() << endl;
        exit(1);
    }
    
    if (superClassName_ != "") {
	  // There is a super class

    	// get the the super class using NT
    	Element* superClass = NT[superClassName_];
    	
    	if (dynamic_cast<NewClass*>(superClass)) {
    		
    		// Create a new object
    		NewClass* parentClass = dynamic_cast<NewClass*>(superClass);
    		
    		// Parent evaluation environment should have same environment
    		parentClass->setTheEnvironment(savedEnvironment);
    		superClass_ = dynamic_cast<NewClass*>(parentClass->constructor(*savedEnvironment, EL));

    	} else {
    		cout<<"ERROR: No such superclass to inherit from" << endl;
    		exit(1);
    	}

    }
    
	// Evaluate parameters
	// @note These are local only, so should override the parent scope without
	//       changing the parent's values.
    list<string>::iterator p;
    list<Expr*>::iterator e;
    for (p = PL_->begin(), e = EL->begin(); p != PL_->end(); p++, e++) {
        (*savedEnvironment)[*p] = (*e)->eval(NT);
    }

    SL_->eval(*savedEnvironment);

    return new NewClass(*this);
}

