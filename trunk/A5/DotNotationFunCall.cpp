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
    Element* element;
    //if(name_ != "") {
    	// Have Ident do the lookup so it can catch errors if any
		element = (new Ident(name_))->eval(NT);
//    } else {
//        element = expression->eval(NT);
//    }

    if(dynamic_cast<NewClass*>(element)) {

    	NewClass* newClass = dynamic_cast<NewClass*>(element);
    	map<string, Element*>* NNT = newClass->getTheEnvironment();

    	// solving the pointer problem of FunCall::eval
    	/*map<string, Element*> SE;
    	// copy the content of the evaluationEnvironment into the saveEnvironment for further access
		for (map<string, Element*>::iterator p = NNT->begin(); p != NNT->end(); p++) {
				SE[p->first] = p->second;
		}
			*/
    	return FC_->eval(*NNT);

    } else {
    	cout << "ERROR: Tried to treat a non-class function as a function" << endl;
    	exit(1);
    }
}
