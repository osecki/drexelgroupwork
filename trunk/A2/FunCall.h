#ifndef FUNCALL_H
#define FUNCALL_H

#include <list>
#include <map>
#include <string>
#include "Expr.h"

using namespace std;

class Proc;

class FunCall : public Expr
{
public:
    FunCall(string name, list<Expr*> *AL)
    {
	name_= name;
	AL_ = AL;
    }

    virtual ~FunCall() { delete AL_; }

    virtual int eval(map<string,int> NT, map<string,Proc*> FT) const
    {
	return FT[name_]->apply(NT, FT, AL_);
    }

private:
    string name_;
    list<Expr*> *AL_;
};

#endif
