#include <map>
#include "Proc.h"
#include "FunCall.h"
#include "ConsCell.h"

FunCall::FunCall(string name, list<Expr*> *AL)
{
    name_= name;
    AL_ = AL;
}

FunCall::~FunCall() { delete AL_; }

// Changed environment table here
Element* FunCall::eval(map<string,Element*> &NT, map<string,Proc*> &FT,vector<ConsCell> &listMemory, int &avail) const
{
    return FT[name_]->apply(NT, FT, AL_,listMemory,avail);
}
