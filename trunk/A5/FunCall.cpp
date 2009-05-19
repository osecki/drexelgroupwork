#include <map>
#include "Proc.h"
#include "FunCall.h"
#include "Ident.h"
#include "NewClass.h"

class NewClass;

FunCall::FunCall(string name, list<Expr*> *AL)
{
    expression = NULL;
    name_= name;
    AL_ = AL;
}

FunCall::FunCall(Expr* e, list<Expr*> *AL) {
    this->expression = e;
    AL_ = AL;
}

FunCall::~FunCall() {
    delete AL_;
    if(NULL != expression) {
        delete expression;
    }
}


// Changed environment table here
Element* FunCall::eval(map<string,Element*> &NT) const
{
    Element* element;
    if(name_ != "") {
    	// Have Ident do the lookup so it can catch errors if any
        element = (new Ident(name_))->eval(NT);
    } else {
        element = expression->eval(NT);
    }

    if(dynamic_cast<Proc*>(element)) {

    	return ((Proc*)element)->apply(NT, AL_);
    }
    else if(dynamic_cast<NewClass*>(element)) {

    	// check whether it is calling the constructor
    	NewClass* newClass = (NewClass*)element;
    	if (this->name_ == newClass->getName()) {
    		newClass->setTheEnvironment(new map<string,Element*>(NT));
    		return newClass->constructor(NT, AL_);
    	} else {
    		cout << "ERROR: No such class!" << endl;
    		exit(1);
    	}

    } else {
    	cout << "ERROR: Tried to treat a non-function as a function" << endl;
    	exit(1);
    }
}

string FunCall::getName() {
		return name_;
}
