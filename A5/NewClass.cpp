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
#include "NewClass.h"

#define RETURN "return"

NewClass::NewClass(string name,list<string> *PL, StmtList *SL)
{
    SL_ = SL;
    PL_ = PL;
    this->name_ = name;
    this->superClassName_ = "";
    NumParam_ = PL->size();
	cout<<"New Class Constructor\n";
}


NewClass::NewClass(string name, string superClassName, list<string> *PL, StmtList *SL)
{
    SL_ = SL;
    PL_ = PL;
    this->name_ = name;
    this->superClassName_ = superClassName;
    NumParam_ = PL->size();
	cout<<"New Class Constructor\n";
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
        cout << "ERROR: Wrong number of parameters to function call" << endl;
        exit(1);
    }

    savedEnvironment = new map<string,Element*>();
    //
    // Establish environment for evaluation
    //
    map<string,Element*> *evaluationEnvironment = new map<string,Element*>();
    /*if(STATIC) {
		// *Copy* over values from parent environment
	    for (map<string,Element*>::iterator p = savedEnvironment->begin();p != savedEnvironment->end();p++) {
	        (*evaluationEnvironment)[p->first] = p->second;
	    }
	} else  {
	    // Copy name table from current context ... (Geoff)
	    for (map<string,Element*>::iterator p = NT.begin();p != NT.end();p++) {
	        (*evaluationEnvironment)[p->first] = p->second;
	    }
    //}*/

		// grab function and values from the super class if there is any
        map<string, Element*>* superClassSavedEnvironment;
        if (superClassName_ != "") {

        	// get the environment of the super class using NT
        	Element* superClass = NT[superClassName_];
        	if (dynamic_cast<NewClass*>(superClass)) {
        		// create a new object
        		NewClass* tempClass = dynamic_cast<NewClass*>(superClass);
        		superClass_ = dynamic_cast<NewClass*>(tempClass->constructor(NT, EL));
        		superClassSavedEnvironment = superClass_->getTheEnvironment();
        		// now push the super class environment into the child class evaluation environment
        		for (map<string, Element*>::iterator p = superClassSavedEnvironment->begin(); p != superClassSavedEnvironment->end(); p++) {
    				// Do not copy return value
    				(*evaluationEnvironment)[p->first] = p->second;

        		}

        	} else {
        		cout<<"ERROR : accessing non class as class object\n";
        		exit(1);
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


    // copy the content of the evaluationEnvironment into the saveEnvironment for further access
    for (map<string, Element*>::iterator p = evaluationEnvironment->begin(); p != evaluationEnvironment->end(); p++) {
    	if(p->first != RETURN) {
    		// Do not copy return value
    		(*savedEnvironment)[p->first] = p->second;
    	}
    }

	/*
	// Evaluate statement list in the new environment
	cout << " saved environment " << endl;
	for (map<string,Element*>::iterator p = savedEnvironment->begin();p != savedEnvironment->end();p++) {
        cout << p->first << " " <<   p->second << endl;
    }
    /*
    if(!STATIC) {
		// Copy changes over to single environment
	    for (map<string, Element*>::iterator p = evaluationEnvironment->begin(); p != evaluationEnvironment->end(); p++) {
	    	if(p->first != RETURN) {
	    		// Do not copy return value
				NT[p->first] = p->second;
	    	}
		}
    }
    */

    // instead of returning set the NT with the name of the class a NewClass type object
    return new NewClass(*this);

//    if ( evaluationEnvironment->find(RETURN) != evaluationEnvironment->end() ) {
//        return (*evaluationEnvironment)[RETURN];
//    }

    //cout << "Error:  No return value set in function" << endl;
    //exit(1);
}

