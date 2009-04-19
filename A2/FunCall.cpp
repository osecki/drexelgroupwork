#include <map>
#include "Proc.h"
#include "FunCall.h"

FunCall::FunCall(string name, list<Expr*> *AL)
{
    name_= name;
    AL_ = AL;
}

FunCall::~FunCall() { delete AL_; }

int FunCall::eval(map<string,int> NT, map<string,Proc*> FT) const
{
    return FT[name_]->apply(NT, FT, AL_);
}
