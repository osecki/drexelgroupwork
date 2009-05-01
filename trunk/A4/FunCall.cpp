#include <map>
#include "Proc.h"
#include "FunCall.h"

FunCall::FunCall(string name, list<Expr*> *AL)
{
    name_= name;
    AL_ = AL;
}

FunCall::~FunCall() { delete AL_; }

// Changed environment table here
Element* FunCall::eval(map<string,Element*> NT, map<string,Proc*> FT, Memory &memory) const
{
    return FT[name_]->apply(NT, FT, AL_, memory);
}
