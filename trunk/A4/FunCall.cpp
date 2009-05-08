#include <map>
#include "Proc.h"
#include "FunCall.h"

FunCall::FunCall(string name, list<Expr*> *AL)
{
    name_= name;
    AL_ = AL;
}

FunCall::FunCall(Expr* e, list<Expr*> *AL) {
    this->expression = e;
    AL_ = AL;
}

FunCall::~FunCall() { delete AL_; }

// Changed environment table here
Element* FunCall::eval(map<string,Element*> NT, map<string,Proc*> FT) const
{
    Element* element;
    if(NULL == expression) {
        element = NT[name_];
    } else {
        element = expression->eval(NT, FT);
    }
    return ((Proc*)element)->apply(NT, FT, AL_);
}
