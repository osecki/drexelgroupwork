#include <map>
#include "Proc.h"
#include "FunCall.h"

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
        element = NT[name_];
    } else {
        element = expression->eval(NT);
    }
    return ((Proc*)element)->apply(NT, AL_);
}
